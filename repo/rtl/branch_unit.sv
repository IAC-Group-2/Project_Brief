module branch_unit #(
    parameter DATA_WIDTH = 32
)(
    input  logic [2:0]            funct3_i,
    input  logic                  Zero_i,
    input  logic [DATA_WIDTH-1:0] SrcA_i,
    input  logic [DATA_WIDTH-1:0] SrcB_i,
    output logic                  BranchTaken_o
);

    always_comb begin
        unique case(funct3_i)                                   // We use unique case to ensure only one case matches
            3'b000: BranchTaken_o = Zero_i;                     // BEQ
            3'b001: BranchTaken_o = !Zero_i;                    // BNE

            3'b100: BranchTaken_o = ($signed(SrcA_i) < $signed(SrcB_i));   // BLT (signed)
            3'b101: BranchTaken_o = ($signed(SrcA_i) >= $signed(SrcB_i));   // BGE (signed)

            3'b110: BranchTaken_o = (SrcA_i < SrcB_i);           // BLTU (unsigned)
            3'b111: BranchTaken_o = (SrcA_i >= SrcB_i);          // BGEU (unsigned)
            
            default: BranchTaken_o = 1'b0;
        endcase
    end

endmodule
