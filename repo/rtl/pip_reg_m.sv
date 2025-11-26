module pip_reg_m #( //Execute to memory stage
    PC_WIDTH = 32,
    INSTRUCTION_WIDTH = 32
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

    input   logic [INSTRUCTION_WIDTH-1:0]   ALUResultE_i, //Execute
    output  logic [INSTRUCTION_WIDTH-1:0]   ALUResultM_o, //Memory

    input   logic [INSTRUCTION_WIDTH-1:0]   WriteDataE_i, //Execute
    output  logic [INSTRUCTION_WIDTH-1:0]   WriteDataM_o, //Memory
    
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]  RdE_i, //Execute
    output  logic [REGISTER_ADDRESS_WIDTH-1:0]  RdM_o, //Memory
    
    input   logic [PC_WIDTH-1:0]            PCPlus4E_i, //Execute
    output  logic [PC_WIDTH-1:0]            PCPlus4M_o, //Memory
    
);

always_ff @(posedge clk_i) begin
    if (en_i) begin
        RegWriteE_i     <= RegWriteM_o;
        ResultSrcE_i    <= ResultSrcM_o;
        MemWriteE_i     <= MemWriteM_o;
        ALUResultE_i    <= ALUResultM_o;
        WriteDataE_i    <= WriteDataM_o;
        RdE_i           <= RdM_o;
        PCPlus4E_i      <= PCPlus4M_o; 
    end
    else begin//freeze
        RegWriteE_i     <= RegWriteE_i;
        ResultSrcE_i    <= ResultSrcE_i;
        MemWriteE_i     <= MemWriteE_i;
        ALUResultE_i    <= ALUResultE_i;
        WriteDataE_i    <= WriteDataE_i;
        RdE_i           <= RdE_i;
        PCPlus4E_i      <= PCPlus4E_i; 
      
    end
end
endmodule
