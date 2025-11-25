module addr #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0] PC_i,
    input logic [DATA_WIDTH-1:0] ImmOp_i,

    output logic [DATA_WIDTH-1:0] branch_PC_o,
    output logic [DATA_WIDTH-1:0] inc_PC_o

);

    always_comb begin
        branch_PC_o = PC_i + ImmOp_i;
        inc_PC_o    = PC_i + 'd4;
    end
    
endmodule
