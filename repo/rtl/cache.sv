/* verilator lint_off UNUSED */
module cache #(
    parameter   ADDRESS_WIDTH = 32,
                DATA_WIDTH = 32, 
                BYTE_WIDTH = 8,
                SET_SIZE = 8,
                TAG_SIZE = 22,
                BYTE_OFFSET_WIDTH = 2,
                WAY_WIDTH = 56,             // V(1) + Dirty(1) + Tag(22) + Data(32) = 56
                CACHE_WIDTH = 113           // U(1) + Way0(56) + Way1(56) = 113

)(
    input   logic                       clk_i,
    input   logic                       rst_i,
    
    input   logic                       MemWriteM_i,    //write enable
    input   logic [1:0]                 ResultSrcM_i,   //Read enable when ResultSrcM_i = 2'b01

    input   logic [ADDRESS_WIDTH-1:0]   addr_i,         //input address
    input   logic [DATA_WIDTH-1:0]      data_i,         //input data

    //memory interface
    input   logic [DATA_WIDTH-1:0]      mem_rd_data_i,  //data from main memory
    output  logic [ADDRESS_WIDTH-1:0]   mem_addr_o,     //address to main memory
    output  logic                       mem_wr_en_o,    //write enable to main memory
    output  logic [DATA_WIDTH-1:0]      mem_wr_data_o,  //data to write to main memory **rename

    output  logic [DATA_WIDTH-1:0]      data_o,         //output data
    output  logic                       cache_miss_o,   //cache_miss = 1 if didnt find in cache
    output  logic                       stall_o         //if cache missed we need a stall: stall_o = 1
);
    logic wr_en;
    assign wr_en = MemWriteM_i;
    logic rd_en;
    assign rd_en = ResultSrcM_i == 2'b01;
    logic cache_en;
    assign cache_en = (rd_en || wr_en);

    //state machine states
    typedef enum {IDLE, WRITEBACK, FETCH, UPDATE} my_state;
    my_state current_state, next_state;
    
    // U | V1 | Dirty1 | Tag1(22 bits) | Data 1 (32 bits) | V2 | Dirty2 | Tag2 (22 bits) | Data 2 (32 bits)
    logic [CACHE_WIDTH-1:0] cache_array [2**SET_SIZE-1:0];
    
    logic [SET_SIZE-1:0] set_addr;
    logic [TAG_SIZE-1:0] tag_addr;

    assign tag_addr = addr_i[ADDRESS_WIDTH -1 : ADDRESS_WIDTH - TAG_SIZE];
    assign set_addr = addr_i[SET_SIZE + BYTE_OFFSET_WIDTH -1 : BYTE_OFFSET_WIDTH];

    logic cache_valid_0;
    logic cache_valid_1;
    logic cache_dirty_0;
    logic cache_dirty_1;

    logic [WAY_WIDTH-1:0] cache_way_0;
    logic [WAY_WIDTH-1:0] cache_way_1;
    
    logic [TAG_SIZE-1:0] cache_tag_0;
    logic [TAG_SIZE-1:0] cache_tag_1;
    
    logic [DATA_WIDTH-1:0] cache_data_0;
    logic [DATA_WIDTH-1:0] cache_data_1;
    
    logic [CACHE_WIDTH-1:0] cache_set;
    logic lru_bit;

    assign cache_set = cache_array[set_addr];
    assign cache_way_0 = cache_set[WAY_WIDTH-1:0];
    assign cache_way_1 = cache_set[2*WAY_WIDTH-1:WAY_WIDTH];
    assign lru_bit = cache_set[CACHE_WIDTH-1];

    assign cache_valid_0 = cache_way_0[WAY_WIDTH-1];
    assign cache_dirty_0 = cache_way_0[WAY_WIDTH-2];
    assign cache_tag_0 = cache_way_0[WAY_WIDTH-3:DATA_WIDTH];
    assign cache_data_0 = cache_way_0[DATA_WIDTH-1:0];

    assign cache_valid_1 = cache_way_1[WAY_WIDTH-1];
    assign cache_dirty_1 = cache_way_1[WAY_WIDTH-2];
    assign cache_tag_1 = cache_way_1[WAY_WIDTH-3:DATA_WIDTH];
    assign cache_data_1 = cache_way_1[DATA_WIDTH-1:0];

    logic tag_0_hit;
    logic tag_1_hit;
    logic cache_miss;
    logic cache_hit;
    logic target_way;       //which way to replace (from LRU)
    logic target_dirty;     //is target dirty?
    logic [TAG_SIZE-1:0] target_tag;
    logic [DATA_WIDTH-1:0] target_data;

    //hit or miss detection
    always_comb begin
        tag_0_hit = (tag_addr == cache_tag_0) && cache_valid_0;
        tag_1_hit = (tag_addr == cache_tag_1) && cache_valid_1;
        cache_hit = (tag_0_hit || tag_1_hit) && cache_en;
        cache_miss = cache_en && !cache_hit;
    end

    //target selection based on LRU (lru_bit=0: replace way0, lru_bit=1: replace way1)
    always_comb begin
        target_way = lru_bit;
        if (lru_bit == 1'b0) begin
            if (cache_valid_0) begin
                target_dirty = cache_dirty_0;
            end
            else begin
                target_dirty = 0;
            end
            target_tag = cache_tag_0;
            target_data = cache_data_0;
        end else begin
            if (cache_valid_1) begin
                target_dirty = cache_dirty_1;
            end
            else begin
                target_dirty = 0;
            end
            target_tag = cache_tag_1;
            target_data = cache_data_1;
        end
    end

    //output data
    always_comb begin
        if (current_state == IDLE && cache_hit) begin
            data_o = tag_1_hit ? cache_data_1 : cache_data_0;
        end else if (current_state == UPDATE) begin
            data_o = mem_rd_data_i;
        end else begin
            data_o = 32'b0;
        end
    end

    //memory interface outputs
    always_comb begin
        mem_addr_o = addr_i;
        mem_wr_en_o = 1'b0;
        mem_wr_data_o = 32'b0;
        
        case (current_state)
            WRITEBACK: begin
                //writeback dirty target to memory
                mem_addr_o = {target_tag, set_addr, {BYTE_OFFSET_WIDTH{1'b0}}};
                mem_wr_en_o = 1'b1;
                mem_wr_data_o = target_data;
            end
            FETCH: begin
                //fetch new data from memory
                mem_addr_o = addr_i;
                mem_wr_en_o = 1'b0;
            end
            default: begin
                mem_addr_o = addr_i;
                mem_wr_en_o = 1'b0;
            end
        endcase
    end

    //stall when not in IDLE or when theres a miss in IDLE
    assign stall_o = (current_state != IDLE) || (current_state == IDLE && cache_miss);
    assign cache_miss_o = cache_miss;

    //state machine next state logic
    always_comb begin
        case (current_state)
            IDLE: begin
                if (cache_miss) begin
                    if (target_dirty)
                        next_state = WRITEBACK;
                    else
                        next_state = FETCH;
                end
            end
            WRITEBACK: begin
                next_state = FETCH;
            end
            FETCH: begin
                next_state = UPDATE;
            end
            UPDATE: begin
                next_state = IDLE;
            end
            default:
                next_state = current_state;
        endcase
    end

    //cache update logic
    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            current_state <= IDLE;

            for (int i = 0; i < 2**SET_SIZE; i++) begin
                cache_array[i] = '0;
            end
        end else begin
            current_state <= next_state;

            case (current_state)
                IDLE: begin
                    if (cache_en && cache_hit) begin
                        if (wr_en) begin
                            //write hit update data and set LRU and dirty bit (already set data out)
                            if (tag_0_hit) begin
                                cache_array[set_addr][DATA_WIDTH-1:0] <= data_i;
                                cache_array[set_addr][DATA_WIDTH + TAG_SIZE] <= 1'b1;
                                cache_array[set_addr][CACHE_WIDTH-1] <= 1'b1;
                            end else if (tag_1_hit) begin
                                cache_array[set_addr][WAY_WIDTH + DATA_WIDTH - 1 : WAY_WIDTH] <= data_i;
                                cache_array[set_addr][WAY_WIDTH + DATA_WIDTH + TAG_SIZE] <= 1'b1;
                                cache_array[set_addr][CACHE_WIDTH-1] <= 1'b0;
                            end
                        end else if (rd_en) begin
                            //read hit: update LRU only
                            if (tag_0_hit)
                                cache_array[set_addr][CACHE_WIDTH-1] <= 1'b1;
                            else if (tag_1_hit)
                                cache_array[set_addr][CACHE_WIDTH-1] <= 1'b0;
                        end
                    end
                end
                UPDATE: begin
                    //fill cache with fetched data
                    if (target_way == 1'b0) begin
                        //update way 0: {valid, dirty, tag, data}
                        cache_array[set_addr][DATA_WIDTH-1:0] <= wr_en ? data_i : mem_rd_data_i; //data
                        cache_array[set_addr][WAY_WIDTH-3:DATA_WIDTH] <= tag_addr; //tag
                        cache_array[set_addr][DATA_WIDTH + TAG_SIZE] <= wr_en ? 1'b1 : 1'b0; //dirty
                        cache_array[set_addr][WAY_WIDTH-1] <= 1'b1; //valid
                        cache_array[set_addr][CACHE_WIDTH-1] <= 1'b1; //LRU
                    end else begin
                        //update way 1
                        cache_array[set_addr][WAY_WIDTH + DATA_WIDTH - 1 : WAY_WIDTH] <= wr_en ? data_i : mem_rd_data_i; //data
                        cache_array[set_addr][WAY_WIDTH + WAY_WIDTH - 3 : WAY_WIDTH + DATA_WIDTH] <= tag_addr; //tag
                        cache_array[set_addr][WAY_WIDTH + DATA_WIDTH + TAG_SIZE] <= wr_en ? 1'b1 : 1'b0; //dirty
                        cache_array[set_addr][2*WAY_WIDTH-1] <= 1'b1; //valid
                        cache_array[set_addr][CACHE_WIDTH-1] <= 1'b0; //LRU
                    end
                end
                default: ;//ignore
            endcase
        end
    end

endmodule
