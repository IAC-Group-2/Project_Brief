module top #(
    ADDRESS_WIDTH = 5,
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
    logic [PC_WIDTH-1:0]            pcF; //Fetch
    logic [PC_WIDTH-1:0]            pcD; //Decode
    
    //Instruction Memory Outputs
    logic[INSTRUCTION_WIDTH-1:0]    InstrF; //Fetch
    logic[INSTRUCTION_WIDTH-1:0]     InstrD; //Decode

    //PC adder
    logic [PC_WIDTH-1:0]            pcPlus4F; //Fetch
    logic [PC_WIDTH-1:0]            pcPlus4D; //Decode

    logic [PC_WIDTH-1:0]            pcPlus4M; //Memory
    logic [PC_WIDTH-1:0]            pcPlus4W; //Writeback


    //Control block outputs
    logic                           PCSrc;
    logic                           ResultSrcW;
    logic                           ResultSrcM;
    logic                           MemWrite;
    logic [2:0]                     ALUControl;
    logic                           ALUSrc;
    logic [1:0]                     ImmSrc;
    logic                           RegWriteM;
    logic                           RegWriteW;

    //Register File Outputs
    logic[DATA_WIDTH-1:0]           SrcA;
    logic[DATA_WIDTH-1:0]           WriteData;

    //Extend Output
    logic[DATA_WIDTH-1:0]           ImmExt;

    //MUX 1
    logic[DATA_WIDTH-1:0]           SrcB;
   
    //ALU Output
    logic[DATA_WIDTH-1:0]           ALUResultE; //Execute
    logic[DATA_WIDTH-1:0]           ALUResultM; //Memory
    logic[DATA_WIDTH-1:0]           ALUResultW; //Writeback
    logic                           Zero;

    //Adder
    logic [PC_WIDTH-1:0]            pcTarget;
    
    //Data Memory
    logic[DATA_WIDTH-1:0]           ReadDataM; //Memory
    logic[DATA_WIDTH-1:0]           ReadDataW; //Writeback

    //Mux 2
    logic[DATA_WIDTH-1:0]           Result;

    //Control block inputs 
    logic [6:0]                     op;
    logic [2:0]                     funct3;
    logic                           funct7;
    
    logic                           en;

    assign en = 1;

    assign pcNext = PCSrc ? pcTarget : pcPlus4;
 
    pc_reg pc_reg (
        .clk_i(clk),
        .rst_i(rst),
        .pcNext_i(pcNext),
        .en_i(en), //from Hazard Unit
        .pc_o(pc)
    );

    instr_mem instr_mem (
        .A_i(pc),
        .RD_o(InstrF)
    );

    addr addr(
        .PC_i(pcF),
        .ImmOp_i(ImmExt),
        .pcTarget_o(pcTarget),
        .pcPlus4_o(pcPlus4F)
    );

    pip_reg_d pip_reg_d (
    .clk_i(clk),
    .en_i(en),
    .pcF_i(pcF),
    .InstrF_i(InstrF),
    .pcPlus4F_i(pcPlus4F),
    .pcD_o(pcD),
    .InstrD_o(InstrD),
    .pcPlus4D_o(pcPlus4D)
);

    assign op = InstrD[6:0];
    assign funct3 = InstrD[14:12];
    assign funct7 = InstrD[30];

    logic [4:0] rs1;
    logic [4:0] rs2;
    logic [4:0] rs3;
    logic [4:0] rs3W;
    logic [4:0] rs3M;
    
    assign rs1 = InstrD[19:15];
    assign rs2 = InstrD[24:20];
    assign rs3D = InstrD[11:7];

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
        .imm_instr_i(InstrD), //input
        .imm_ext_o(ImmExt)
    );
    
    

    regfile regfile(
        .clk_i(clk),
        .A1_i(rs1),
        .A2_i(rs2),
        .A3_i(rs3W),
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
        .addr_i(ALUResultM),
        .data_i(WriteData),
        .data_o(ReadDataM)
    );

    pip_reg_w pip_reg_w(
        .clk_i(clk),
        .RegWriteM_i(RegWriteM),
        .RegWriteW_o(RegWriteW),
        .ResultSrcM_i(ResultSrcM),
        .ResultSrcW_o(ResultSrcW),
        .ALUResultM_i(ALUResultM),
        .ALUResultW_o(ALUResultW),
        .ReadDataM_i(ReadDataM),
        .ReadDataW_o(ReadDataW),
        .RdM_i(rs3M),
        .RdW_o(rs3W),
        .pcPlus4M_i(pcPlus4M),
        .pcPlus4W_o(pcPlus4W)
    );

    //mux 3
    assign Result = ResultSrcW ? ReadDataW : ALUResultW;

endmodule
