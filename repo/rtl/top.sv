module top #(
    REGISTER_ADDRESS_WIDTH = 5,
    DATA_WIDTH = 32,
    INSTRUCTION_WIDTH = 32,
    PC_WIDTH = 32
) (
    input   logic                   clk,
    input   logic                   rst,
    input   logic                   trigger,
    output  logic [DATA_WIDTH-1:0]  a0
);

    //mux 0
    logic [PC_WIDTH-1:0]            pcNext;
    
    //shift register
    logic [PC_WIDTH-1:0]            pc;
    
    //Instruction Memory Outputs
    logic[INSTRUCTION_WIDTH-1:0]    Instr;

    //PC adder
    logic [PC_WIDTH-1:0]            pcPlus4;

    //Control block outputs
    logic                           PCSrc;
    logic                           ResultSrc;
    logic                           MemWrite;
    logic [2:0]                     ALUControl;
    logic                           ALUSrc;
    logic [1:0]                     ImmSrc;
    logic                           RegWrite;

    //Register File Outputs
    logic[DATA_WIDTH-1:0]           SrcA;
    logic[DATA_WIDTH-1:0]           WriteData;

    //Extend Output
    logic[DATA_WIDTH-1:0]           ImmExt;

    //MUX 1
    logic[DATA_WIDTH-1:0]           SrcB;
   
    //ALU Output
    logic[DATA_WIDTH-1:0]           ALUResult;
    logic                           Zero;

    //Adder
    logic [PC_WIDTH-1:0]            pcTarget;
    
    //Data Memory
    logic[DATA_WIDTH-1:0]           ReadData;

    //Mux 2
    logic[DATA_WIDTH-1:0]           Result;

    //Control block inputs 
    logic [6:0]                     op;
    logic [2:0]                     funct3;
    logic                           funct7;
    
    assign pcNext = PCSrc ? pcTarget : pcPlus4;
 
    pc_reg pc_reg (
        .clk_i(clk),
        .rst_i(rst),
        .pcNext_i(pcNext),
        .pc_o(pc)
    );

    instr_mem instr_mem (
        .A_i(pc),
        .RD_o(Instr)
    );

    addr addr(
        .PC_i(pc),
        .ImmOp_i(ImmExt),
        .pcTarget_o(pcTarget),
        .pcPlus4_o(pcPlus4)
    );

    assign op = Instr[6:0];
    assign funct3 = Instr[14:12];
    assign funct7 = Instr[30];

    logic [REGISTER_ADDRESS_WIDTH-1:0] rs1;
    logic [REGISTER_ADDRESS_WIDTH-1:0] rs2;
    logic [REGISTER_ADDRESS_WIDTH-1:0] rs3;
    
    assign rs1 = Instr[19:15];
    assign rs2 = Instr[24:20];
    assign rs3 = Instr[11:7];

    control_unit control_unit(
        .op_i(op),
        .Zero_i(Zero),
        .funct3_i(funct3),
        .funct7_i(funct7),
        .RegWrite_o(RegWrite),
        .ALUControl_o(ALUControl),
        .ALUSrc_o(ALUSrc),
        .ImmSrc_o(ImmSrc),
        .PCSrc_o(PCSrc)
    );

    //variable changing is needed
    sign_extend sign_extend (
        .imm_src_i(ImmSrc),
        .imm_instr_i(Instr), //input
        .imm_ext_o(ImmExt)
    );
    
    

    regfile regfile(
        .clk_i(clk),
        .A1_i(rs1),
        .A2_i(rs2),
        .A3_i(rs3),
        .WD3_i(Result),
        .WE3_i(RegWrite),
        .RD1_o(SrcA),
        .RD2_o(WriteData),
        .A0_o(a0)
    );

    assign SrcB = ALUSrc ? ImmExt : WriteData;

    ALU ALU (
        .SrcA_i(SrcA),
        .SrcB_i(SrcB),
        .ALUControl_i(ALUControl),
        .ALUResult_o(ALUResult),
        .Zero_o(Zero)
        );    

    data_memory data_memory(
        .clk_i(clk),
        .wr_en_i(MemWrite),
        .addr_i(ALUResult),
        .data_i(WriteData),
        .data_o(ReadData)
    );

    //mux 3
    assign Result = ResultSrc ? ReadData : ALUResult;

endmodule
