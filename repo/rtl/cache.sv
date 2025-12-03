/* verilator lint_off UNUSED */
module cache #(
    parameter   ADDRESS_WIDTH = 32,
                DATA_WIDTH = 32, 
                BYTE_WIDTH = 8,
                SET_SIZE = 8,
                TAG_SIZE = 22,
                CACHE_WIDTH = 123,
                BYTE_OFFSET_WIDTH = 2,
                WAY_WIDTH = 55

)(
    input   logic                       clk_i,
    input   logic                       rst_i,
    
    input   logic                       MemWriteM_i,    //write enable
    input   logic [1:0]                 ResultSrcM_i,   //Read enable when ResultSrcM_i = 2'b01

    input   logic [ADDRESS_WIDTH-1:0]   addr_i,         //input address
    input   logic [DATA_WIDTH-1:0]      data_i,         //input data 

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
    

    
    // U | V1 | Tag1(22 bits) | Data 1 (32 bits) | V2 | Tag2 (22 bits) | Data 2 (32 bits)
    logic [CACHE_WIDTH-1:0] cache_array [2**SET_SIZE-1:0];
    
    logic [SET_SIZE-1:0] set_addr;
    logic [TAG_SIZE-1:0] tag_addr;

    assign tag_addr = addr_i[ADDRESS_WIDTH -1 : ADDRESS_WIDTH - TAG_SIZE];
    assign set_addr = addr_i[SET_SIZE + BYTE_OFFSET_WIDTH -1 : BYTE_OFFSET_WIDTH];

    logic cache_valid_0;
    logic cache_valid_1;

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
    assign cache_valid_1 = cache_way_1[WAY_WIDTH-1];

    assign cache_tag_0 = cache_way_0[WAY_WIDTH-2:DATA_WIDTH];
    assign cache_tag_1 = cache_way_1[WAY_WIDTH-2:DATA_WIDTH];

    assign cache_data_0 = cache_way_0[DATA_WIDTH-1:0];
    assign cache_data_1 = cache_way_1[DATA_WIDTH-1:0];

    logic tag_0_hit;
    logic tag_1_hit;
    logic cache_miss;
    logic cache_hit;

    //hit or miss detection
    always_comb begin
        tag_0_hit = (tag_addr == cache_tag_0) && cache_valid_0;
        tag_1_hit = (tag_addr == cache_tag_1) && cache_valid_1;
        cache_hit = (tag_0_hit || tag_1_hit) && cache_en;
        cache_miss = cache_en && !cache_hit;
    end

    //output data on cache hit
    always_comb begin
        if (cache_hit) begin
            data_o = tag_1_hit ? cache_data_1 : cache_data_0;
        end else begin
            data_o = 32'b0; //default val on miss
        end
    end

    //stall if cache miss
    assign stall_o = cache_miss;
    assign cache_miss_o = cache_miss;

    //cache update logic
    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            //on reset set everything to 0
            for (int i = 0; i < 2**SET_SIZE; i++) begin
                cache_array[i] <= '0;
            end
        end else if (cache_en) begin
            if (wr_en && cache_hit) begin
                //write hit update data and set LRU (already set data out)
                if (tag_0_hit) begin
                    cache_array[set_addr][DATA_WIDTH-1:0] <= data_i;
                    cache_array[set_addr][CACHE_WIDTH-1] <= 1'b1;
                end else if (tag_1_hit) begin
                    cache_array[set_addr][WAY_WIDTH + DATA_WIDTH - 1 : WAY_WIDTH] <= data_i;
                    cache_array[set_addr][CACHE_WIDTH-1] <= 1'b0;
                end
            end else if (rd_en && cache_hit) begin
                //read data set LRU (already set data out)
                if (tag_0_hit) begin
                    cache_array[set_addr][CACHE_WIDTH-1] <= 1'b1;
                end else if (tag_1_hit) begin
                    cache_array[set_addr][CACHE_WIDTH-1] <= 1'b0;
                end
            end
            // on cache miss, the data will be loaded from main memory
            // this part will be implemented when connecting to data_memory
            // for now, the stall signal will tell the pipeline to wait
        end
    end

endmodule
