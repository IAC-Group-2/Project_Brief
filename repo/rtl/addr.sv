module addr #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0]        PCF_i,
    input logic [DATA_WIDTH-1:0]        PCE_i,

    input logic [DATA_WIDTH-1:0]        ImmOp_i,
    output logic [DATA_WIDTH-1:0]       PCTarget_o,
    output logic [DATA_WIDTH-1:0]       PCPlus4_o
);
    always_comb begin
        PCTarget_o  = PCE_i + ImmOp_i;
        PCPlus4_o   = PCF_i + 'd4;
    end

endmodule
