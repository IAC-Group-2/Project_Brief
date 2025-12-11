module branch_predict #(
    parameter PC_WIDTH = 32,
              TABLE_BITS = 8 //256 table entries
)(
    input   logic                   clk_i,
    input   logic                   rst_i,
    input   logic [PC_WIDTH-1:0]    PCF_i,
    input   logic [PC_WIDTH-1:0]    PCE_i,
    output  logic                   predictTakenF_o,
    output  logic [PC_WIDTH-1:0]    predictTargetF_o,    
    input   logic [PC_WIDTH-1:0]    PCTargetE_i, 
    input   logic                   BranchE_i,   
    input   logic                   TakenE_i
);

    //table acts as 2 bit branch target buffer
    //11: strongly taken, 10: weakly taken, 01: weakly not taken, 00: strongly not taken
    logic [1:0]          state_table  [2**TABLE_BITS-1:0];
    logic [PC_WIDTH-1:0] target_table [2**TABLE_BITS-1:0];

    //use bits [9:2] to index table
    //ignore [1:0] = 00, word aligned PC
    logic [TABLE_BITS-1:0] index_f;
    logic [TABLE_BITS-1:0] index_e;

    assign index_f = PCF_i[TABLE_BITS+1:2];
    assign index_e = PCE_i[TABLE_BITS+1:2];

    //prediction
    always_comb begin
        //predict taken if the counter is 10 or 11
        //only need to check MSB
        predictTakenF_o  = state_table[index_f][1]; 

        predictTargetF_o = target_table[index_f];
    end

    //branch table buffer update
    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            for (int i = 0; i < 2**TABLE_BITS; i++) begin
                state_table[i] = 2'b01;
                target_table[i] = {PC_WIDTH{1'b0}};
            end
        end 
        else if (BranchE_i) begin
            // update branch table buffer with actual target
            target_table[index_e] <= PCTargetE_i;

            //update saturating counter
            if (TakenE_i) begin
                //increment until 11 (strongly taken)
                if (state_table[index_e] != 2'b11)
                    state_table[index_e] <= state_table[index_e] + 1;
            end else begin
                //decrement until 00 (strongly not taken)
                if (state_table[index_e] != 2'b00)
                    state_table[index_e] <= state_table[index_e] - 1;
            end
        end
    end

endmodule
