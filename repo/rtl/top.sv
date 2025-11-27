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
    logic [PC_WIDTH-1:0]            PCNext;
    
    //shift register
    logic [PC_WIDTH-1:0]            PCF; //Fetch
    logic [PC_WIDTH-1:0]            PCE; //Execute
    logic [PC_WIDTH-1:0]            PCD; //Decode
    
    //Instruction Memory Outputs
    logic[INSTRUCTION_WIDTH-1:0]    InstrF; //Fetch
    logic[INSTRUCTION_WIDTH-1:0]    InstrD; //Decode

    //PC adder
    logic [PC_WIDTH-1:0]            PCPlus4F; //Fetch
    logic [PC_WIDTH-1:0]            PCPlus4D; //Decode
    logic [PC_WIDTH-1:0]            PCPlus4E; //Decode
    logic [PC_WIDTH-1:0]            PCPlus4M; //Memory
    logic [PC_WIDTH-1:0]            PCPlus4W; //Writeback


    //Control block outputs
    logic                           PCSrcE;
    logic                           RegWriteD;
    logic                           RegWriteE;
    logic                           RegWriteM;
    logic                           RegWriteW;
    logic [1:0]                     ResultSrcD;
    logic [1:0]                     ResultSrcE;
    logic [1:0]                     ResultSrcM;
    logic [1:0]                     ResultSrcW;
    logic                           MemWriteD;
    logic                           MemWriteE;
    logic                           MemWriteM;
    logic                           JumpD;
    logic                           JumpE;
    logic                           BranchD;
    logic                           BranchE;
    logic [2:0]                     ALUControlD;
    logic [2:0]                     ALUControlE;
    logic                           ALUSrcD;
    logic                           ALUSrcE;
    logic [2:0]                     ImmSrcD;


    //Register File Outputs
    logic[DATA_WIDTH-1:0]           RD1D;
    logic[DATA_WIDTH-1:0]           RD1E;
    logic[DATA_WIDTH-1:0]           RD2D;
    logic[DATA_WIDTH-1:0]           RD2E;


    //Extend Output
    logic[DATA_WIDTH-1:0]           ImmExtD;
    logic[DATA_WIDTH-1:0]           ImmExtE;


    //ALU Input Wires
    logic[DATA_WIDTH-1:0]           WriteDataE;
    logic[DATA_WIDTH-1:0]           WriteDataM;
    logic[DATA_WIDTH-1:0]           SrcAE;
    logic[DATA_WIDTH-1:0]           SrcBE;
   
    //ALU Output
    logic[DATA_WIDTH-1:0]           ALUResultE; //Execute
    logic[DATA_WIDTH-1:0]           ALUResultM; //Memory
    logic[DATA_WIDTH-1:0]           ALUResultW; //Writeback
    logic                           ZeroE;

    //Adder
    logic [PC_WIDTH-1:0]            PCTargetE;
    
    //Data Memory
    logic[DATA_WIDTH-1:0]           ReadDataM; //Memory
    logic[DATA_WIDTH-1:0]           ReadDataW; //Writeback

    //Mux 2
    logic[DATA_WIDTH-1:0]           ResultW;

    //Hazard Unit
    logic                           StallF;
    logic                           StallD;
    logic                           FlushD;
    logic                           FlushE;
    logic[1:0]                      ForwardAE;
    logic[1:0]                      ForwardBE;

    //Control block inputs 
    logic [6:0]                     op;
    logic [2:0]                     funct3;
    logic                           funct7;

    assign PCSrcE = JumpE || (BranchE && ZeroE);
    assign PCNext = PCSrcE ? PCTargetE : PCPlus4F;
    // NOTE: after control block changes PCSrcE, make PCSrcE = the or stuff in diag

    pc_reg pc_reg (
        .clk_i(clk),
        .rst_i(rst),
        .PCNext_i(PCNext),
        .en_i(!StallF), //from Hazard Unit
        .PC_o(PCF)
    );

    hazard_unit hazard_unit(
        .Rs1D_i(Rs1D),
        .Rs2D_i(Rs2D),
        .Rs1E_i(Rs1E),
        .Rs2E_i(Rs2E),
        .RdE_i(RdE),
        .ResultSrcE0_i(ResultSrcE[0]),
        .RdM_i(RdM),
        .RegWriteM_i(RegWriteM),
        .RdW_i(RdW),
        .RegWriteW_i(RegWriteW),
        .PCSrcE_i(PCSrcE),
        .ForwardAE_o(ForwardAE),
        .ForwardBE_o(ForwardBE),
        .StallF_o(StallF),
        .StallD_o(StallD),
        .FlushD_o(FlushD),
        .FlushE_o(FlushE)
    );

    instr_mem instr_mem (
        .A_i(PCF),
        .RD_o(InstrF)
    );

    addr addr(
        .PCF_i(PCF),
        .PCE_i(PCE),
        .ImmOp_i(ImmExtE),
        .PCTarget_o(PCTargetE),
        .PCPlus4_o(PCPlus4F)
    );

    pip_reg_d pip_reg_d (
        .clk_i(clk),
        .en_i(!StallD),
        .clr_i(FlushD),
        .PCF_i(PCF),
        .InstrF_i(InstrF),
        .PCPlus4F_i(PCPlus4F),
        .PCD_o(PCD),
        .InstrD_o(InstrD),
        .PCPlus4D_o(PCPlus4D)
    );

    assign op = InstrD[6:0];
    assign funct3 = InstrD[14:12];
    assign funct7 = InstrD[30];


    logic [REGISTER_ADDRESS_WIDTH-1:0] Rs1D;
    logic [REGISTER_ADDRESS_WIDTH-1:0] Rs1E;
    logic [REGISTER_ADDRESS_WIDTH-1:0] Rs2D;
    logic [REGISTER_ADDRESS_WIDTH-1:0] Rs2E;
    logic [REGISTER_ADDRESS_WIDTH-1:0] RdD;
    logic [REGISTER_ADDRESS_WIDTH-1:0] RdE;
    logic [REGISTER_ADDRESS_WIDTH-1:0] RdM;
    logic [REGISTER_ADDRESS_WIDTH-1:0] RdW;


    assign Rs1D = InstrD[19:15];
    assign Rs2D = InstrD[24:20];
    assign RdD = InstrD[11:7];


    //Control unit needs to be modified to have JumpD, BranchD
    //Control unit must not take input from zeroE, get rid of PCSrcE output pls
    control_unit control_unit(
        .op_i(op),
        .Zero_i(ZeroE),
        .funct3_i(funct3),
        .funct7_i(funct7),
        .RegWrite_o(RegWriteD),
        .MemWrite_o(MemWriteD),
        .ALUControl_o(ALUControlD),
        .ALUSrc_o(ALUSrcD),
        .ImmSrc_o(ImmSrcD),
        .ResultSrc_o(ResultSrcD),
        .PCSrc_o(JumpD) // CHANGE CU TO OUTPUT JUMP, BRANCH STUFF INSTEAD 
        // SHOULD ALSO HAVE A BRANCHD OUTPUT HERE
    );

    //variable changing is needed
    sign_extend sign_extend (
        .imm_src_i(ImmSrcD),
        .imm_instr_i(InstrD), //input
        .imm_ext_o(ImmExtD)
    );
    

    regfile regfile(
        .clk_i(!clk),
        .A1_i(Rs1D),
        .A2_i(Rs2D),
        .A3_i(RdW),
        .WD3_i(ResultW),
        .WE3_i(RegWriteW),
        .RD1_o(RD1D),
        .RD2_o(RD2D),
        .A0_o(a0) 
    );


    pip_reg_e pip_reg_e(
        .clk_i(clk),
        .clr_i(FlushE),
        .RegWriteD_i(RegWriteD),
        .RegWriteE_o(RegWriteE),
        .ResultSrcD_i(ResultSrcD),
        .ResultSrcE_o(ResultSrcE),
        .MemWriteD_i(MemWriteD),
        .MemWriteE_o(MemWriteE),
        .JumpD_i(JumpD),
        .JumpE_o(JumpE),
        .BranchD_i(BranchD),
        .BranchE_o(BranchE),
        .ALUControlD_i(ALUControlD),
        .ALUControlE_o(ALUControlE),
        .ALUSrcD_i(ALUSrcD),
        .ALUSrcE_o(ALUSrcE),
        .RD1D_i(RD1D),
        .RD1E_o(RD1E),
        .RD2D_i(RD2D),
        .RD2E_o(RD2E),
        .PCD_i(PCD),
        .PCE_o(PCE),
        .Rs1D_i(Rs1D),
        .Rs1E_o(Rs1E),
        .Rs2D_i(Rs2D),
        .Rs2E_o(Rs2E),
        .RdD_i(RdD),
        .RdE_o(RdE),
        .ImmExtD_i(ImmExtD),
        .ImmExtE_o(ImmExtE),
        .PCPlus4D_i(PCPlus4D),
        .PCPlus4E_o(PCPlus4E)
    );

    //3way mux so assumes ForwardAE != 11
    assign SrcAE = ForwardAE[1] ? (ForwardAE[0] ? 'b0 : ALUResultM) : (ForwardAE[0] ? ResultW : RD1E); 
    //3way mux so assumes ForwardBE != 11
    assign WriteDataE = ForwardBE[1] ? (ForwardBE[0] ? 'b0 : ALUResultM) : (ForwardBE[0] ? ResultW : RD2E);
    assign SrcBE = ALUSrcE ? ImmExtE : WriteDataE; 

    ALU ALU (
        .SrcA_i(SrcAE),
        .SrcB_i(SrcBE),
        .ALUControl_i(ALUControlE),
        .ALUResult_o(ALUResultE),
        .Zero_o(ZeroE)
    );    


    pip_reg_m pip_reg_m(
        .clk_i(clk),
        .RegWriteE_i(RegWriteE),
        .RegWriteM_o(RegWriteM),
        .ResultSrcE_i(ResultSrcE),
        .ResultSrcM_o(ResultSrcM),
        .MemWriteE_i(MemWriteE),
        .MemWriteM_o(MemWriteM),
        .ALUResultE_i(ALUResultE),
        .ALUResultM_o(ALUResultM),
        .WriteDataE_i(WriteDataE), 
        .WriteDataM_o(WriteDataM), 
        .RdE_i(RdE),
        .RdM_o(RdM),
        .PCPlus4E_i(PCPlus4E),
        .PCPlus4M_o(PCPlus4M)
    );

    data_memory data_memory(
        .clk_i(clk),
        .wr_en_i(MemWriteM),
        .addr_i(ALUResultM),
        .data_i(WriteDataM),
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
        .RdM_i(RdM),
        .RdW_o(RdW),
        .PCPlus4M_i(PCPlus4M),
        .PCPlus4W_o(PCPlus4W)
    );

    //mux 3

    assign ResultW = ResultSrcW[1] ? (ResultSrcW[0] ? 'b0 : PCPlus4W) : (ResultSrcW[0] ? ReadDataW : ALUResultW);


endmodule
