module pip_reg_m #( //Execute to memory stage
    PC_WIDTH = 32,
    INSTRUCTION_WIDTH = 32,
    REGISTER_ADDRESS_WIDTH = 5
)( 
    input   logic                           clk_i,
    input   logic                           en_i,

    input   logic                           RegWriteE_i, //Execute
    output  logic                           RegWriteM_o, //Memory
    
    input   logic[1:0]                      ResultSrcE_i, //Execute
    output  logic[1:0]                      ResultSrcM_o, //Memory

    input   logic                           MemWriteE_i, //Execute
    output  logic                           MemWriteM_o, //Memory

    input   logic [2:0]                     funct3E_i, // Execute
    output  logic [2:0]                     funct3M_o, // Memory

    input   logic [INSTRUCTION_WIDTH-1:0]   ALUResultE_i, //Execute
    output  logic [INSTRUCTION_WIDTH-1:0]   ALUResultM_o, //Memory

    input   logic [INSTRUCTION_WIDTH-1:0]   WriteDataE_i, //Execute
    output  logic [INSTRUCTION_WIDTH-1:0]   WriteDataM_o, //Memory
    
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]  RdE_i, //Execute
    output  logic [REGISTER_ADDRESS_WIDTH-1:0]  RdM_o, //Memory
    
    input   logic [PC_WIDTH-1:0]            PCPlus4E_i, //Execute
    output  logic [PC_WIDTH-1:0]            PCPlus4M_o //Memory
    
);

always_ff @(posedge clk_i) begin
    if (en_i) begin
        RegWriteM_o     <= RegWriteE_i;     
        ResultSrcM_o    <= ResultSrcE_i;    
        MemWriteM_o     <= MemWriteE_i; 
        funct3M_o       <= funct3E_i;    
        ALUResultM_o    <= ALUResultE_i;    
        WriteDataM_o    <= WriteDataE_i;    
        RdM_o           <= RdE_i;
        PCPlus4M_o      <= PCPlus4E_i;
    end

end
endmodule
