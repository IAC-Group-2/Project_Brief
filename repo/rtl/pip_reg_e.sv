module pip_reg_e #( //Decode to execute stage
    PC_WIDTH = 32,
    INSTRUCTION_WIDTH = 32,
    REGISTER_ADDRESS_WIDTH = 5
)(
    input   logic                           clk_i,
    input   logic                           clr_i,

    input   logic                           RegWriteD_i, //Decode
    output  logic                           RegWriteE_o, //Execute
    
    input   logic[1:0]                      ResultSrcD_i, //Decode
    output  logic[1:0]                      ResultSrcE_o, //Execute

    input   logic                           MemWriteD_i, //Decode
    output  logic                           MemWriteE_o, //Execute

    input   logic                           JumpD_i, //Decode
    output  logic                           JumpE_o, //Execute

    input   logic                           BranchD_i, //Decode
    output  logic                           BranchE_o, //Execute

    input   logic [2:0]                     ALUControlD_i, //Decode
    output  logic [2:0]                     ALUControlE_o, //Execute

    input   logic                           ALUSrcD_i, //Decode
    output  logic                           ALUSrcE_o, //Execute
    
    input   logic [INSTRUCTION_WIDTH-1:0]   RD1D_i, //Decode
    output  logic [INSTRUCTION_WIDTH-1:0]   RD1E_o, //Execute
    
    input   logic [INSTRUCTION_WIDTH-1:0]   RD2D_i, //Decode
    output  logic [INSTRUCTION_WIDTH-1:0]   RD2E_o, //Execute
    
    input   logic [PC_WIDTH-1:0]            PCD_i, //Decode
    output  logic [PC_WIDTH-1:0]            PCE_o, //Execute
    
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]   Rs1D_i, //Decode
    output  logic [REGISTER_ADDRESS_WIDTH-1:0]   Rs1E_o, //Execute
    
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]   Rs2D_i, //Decode
    output  logic [REGISTER_ADDRESS_WIDTH-1:0]   Rs2E_o, //Execute

    input   logic [REGISTER_ADDRESS_WIDTH-1:0]  RdD_i, //Decode
    output  logic [REGISTER_ADDRESS_WIDTH-1:0]  RdE_o, //Execute
    
    input   logic [INSTRUCTION_WIDTH-1:0]   ImmExtD_i, //Decode
    output  logic [INSTRUCTION_WIDTH-1:0]   ImmExtE_o, //Execute
    
    input   logic [PC_WIDTH-1:0]            PCPlus4D_i, //Decode
    output  logic [PC_WIDTH-1:0]            PCPlus4E_o //Execute
    
);

always_ff @(posedge clk_i) begin
    if (clr_i) begin
        RegWriteE_o     <= RegWriteD_i;
        ResultSrcE_o    <= ResultSrcD_i;
        MemWriteE_o     <= MemWriteD_i;
        JumpE_o         <= JumpD_i;
        BranchE_o       <= BranchD_i;
        ALUControlE_o   <= ALUControlD_i;
        ALUSrcE_o       <= ALUSrcD_i;
        RD1E_o          <= RD1D_i;
        RD2E_o          <= RD2D_i;
        PCE_o           <= PCD_i;
        Rs1E_o          <= Rs1D_i;
        Rs2E_o          <= Rs2D_i;
        RdE_o           <= RdD_i;
        ImmExtE_o       <= ImmExtD_i;
        PCPlus4E_o      <= PCPlus4D_i;
    end
    else begin//flush logic ... tbc
        RegWriteE_o     <= 'b0;
        ResultSrcE_o    <= 'b0;
        MemWriteE_o     <= 'b0;
        JumpE_o         <= 'b0;
        BranchE_o       <= 'b0;
        ALUControlE_o   <= 'b0;
        ALUSrcE_o       <= 'b0;
        RD1E_o          <= 'b0;
        RD2E_o          <= 'b0;
        PCE_o           <= 'b0;
        Rs1E_o          <= 'b0;
        Rs2E_o          <= 'b0;
        RdE_o           <= 'b0;
        ImmExtE_o       <= 'b0;
        PCPlus4E_o      <= 'b0;
    end
end
endmodule
