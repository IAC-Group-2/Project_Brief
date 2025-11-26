module pip_reg_w #(
    DATA_WIDTH = 32,
    PC_WIDTH = 32,
    REGISTER_ADDRESS_WIDTH = 5
)(
    input   logic                           clk_i,

    input   logic                           RegWriteM_i, //Memory
    output  logic                           RegWriteW_o, //Writeback
    
    input   logic [1:0]                     ResultSrcM_i, //Memory
    output  logic [1:0]                     ResultSrcW_o, //Writeback

    input   logic[DATA_WIDTH-1:0]           ALUResultM_i, //Memory
    output  logic[DATA_WIDTH-1:0]           ALUResultW_o, //WriteBack

    input   logic[DATA_WIDTH-1:0]           ReadDataM_i, //Memory
    output  logic[DATA_WIDTH-1:0]           ReadDataW_o, //WriteBack
    
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]  RdM_i,
    output  logic [REGISTER_ADDRESS_WIDTH-1:0]  RdW_o,

    input   logic [PC_WIDTH-1:0]            pcPlus4M_i,
    output  logic [PC_WIDTH-1:0]            pcPlus4W_o
);

always_ff @(posedge clk_i) begin
    RegWriteW_o     <= RegWriteM_i;
    ResultSrcW_o    <= ResultSrcM_i;
    ALUResultW_o    <= ALUResultM_i;
    ReadDataW_o     <= ReadDataM_i;
    RdW_o           <= RdM_i;
    pcPlus4W_o      <= pcPlus4M_i;
end
endmodule
