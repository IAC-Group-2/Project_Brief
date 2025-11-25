module addr #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0]        PC_i,
    input logic [DATA_WIDTH-1:0]        ImmOp_i,
    output logic [DATA_WIDTH-1:0]       pcTarget_o,
    output logic [DATA_WIDTH-1:0]       pcPlus4_o
);
    always_comb begin
        pcTarget_o  = PC_i + ImmOp_i;
        pcPlus4_o   = PC_i + 'd4;
    end

endmodule
