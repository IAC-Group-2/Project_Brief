module top #(
    parameter DATA_WIDTH = 32
)(
    input   logic                   clk,
    input   logic                   rst,
    /* verilator lint_off UNUSED */
    input   logic                   trigger,
    /* verilator lint_on UNUSED */
    output  logic [DATA_WIDTH-1:0]  a0    
);

    logic [DATA_WIDTH-1:0]  PC;
    logic [DATA_WIDTH-1:0]  PCNext;
    logic [DATA_WIDTH-1:0]  PCPlus4;
    logic [DATA_WIDTH-1:0]  branch_target;

    logic [DATA_WIDTH-1:0]  Instr;
    logic [DATA_WIDTH-1:0]  ImmExt;
    logic [DATA_WIDTH-1:0]  SrcA;
    logic [DATA_WIDTH-1:0]  SrcB;
    logic [DATA_WIDTH-1:0]  ReadData2;
    logic [DATA_WIDTH-1:0]  ALUResult;
    logic [DATA_WIDTH-1:0]  ReadData;
    logic [DATA_WIDTH-1:0]  Result;
    logic                   Zero;
    logic                   RegWrite;
    logic                   MemWrite;
    
    logic                   ALUSrc;
    logic [1:0]             PCSrc;
    logic [1:0]             ResultSrc;
    logic [2:0]             ALUControl;
    logic [2:0]             ImmSrc;

    addr PC_arithmetic (
        .PC_i(PC), 
        .ImmOp_i(ImmExt), 
        .branch_PC_o(branch_target), 
        .inc_PC_o(PCPlus4)
    );

    mux_reg PC_mux (
        .inc_PC_i(PCPlus4), 
        .branch_PC_i(branch_target), 
        .jalr_PC_i(ALUResult), 
        .PC_src_i(PCSrc),
        .next_pc_o(PCNext)
    );

    pc_reg program_counter (
        .clk_i(clk),
        .rst_i(rst),
        .next_pc_i(PCNext),
        .PC_o(PC)
    );

    instr_mem Instruction_Memory (
        .A_i(PC),
        .RD_o(Instr)
    );

    control_unit control_unit (
        .op_i(Instr[6:0]),
        .funct3_i(Instr[14:12]),
        .funct7_i(Instr[30]), 
        .Zero_i(Zero),
        .RegWrite_o(RegWrite),
        .MemWrite_o(MemWrite), 
        .ALUControl_o(ALUControl),
        .ALUSrc_o(ALUSrc),
        .ImmSrc_o(ImmSrc), 
        .ResultSrc_o(ResultSrc),
        .PCSrc_o(PCSrc)
    );

    regfile register_file (
        .clk_i(clk),
        .A1_i(Instr[19:15]),
        .A2_i(Instr[24:20]),
        .A3_i(Instr[11:7]),  
        .WD3_i(Result),
        .WE3_i(RegWrite),
        .RD1_o(SrcA),
        .RD2_o(ReadData2),
        .A0_o(a0)            
    );

    sign_extend sign_extend (
        .ImmSrc_i(ImmSrc),
        .ImmInstr_i(Instr),
        .ImmExt_o(ImmExt)
    );

    // ALU mux
    assign SrcB = ALUSrc ? ImmExt : ReadData2;

    ALU ALU (
        .SrcA_i(SrcA),
        .SrcB_i(SrcB),
        .ALUControl_i(ALUControl), 
        .ALUResult_o(ALUResult),
        .Zero_o(Zero)
    );

    data_memory data_memory (
        .clk_i(clk), 
        .wr_en_i(MemWrite), 
        .funct3_i(Instr[14:12]),
        .addr_i(ALUResult), 
        .data_i(ReadData2), 
        .data_o(ReadData)
    );

    // writeback mux
    assign Result = (ResultSrc == 2'b01) ? ReadData : 
                    (ResultSrc == 2'b10) ? PCPlus4  : ALUResult;

endmodule
