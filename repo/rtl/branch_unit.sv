module branch_unit #(
    parameter DATA_WIDTH = 32
)(
    input  logic [2:0]            funct3_i,
    input  logic                  Zero_i,
    input  logic [DATA_WIDTH-1:0] ALUResult_i,
    output logic                  BranchTaken_o
);

    always_comb begin
        case(funct3_i)
            3'b000: BranchTaken_o = Zero_i;          // BEQ
            3'b001: BranchTaken_o = !Zero_i;         // BNE
            3'b100: BranchTaken_o = ALUResult_i[31]; // BLT
            3'b101: BranchTaken_o = !ALUResult_i[31];// BGE
            default: BranchTaken_o = 1'b0;
        endcase
    end

endmodule
