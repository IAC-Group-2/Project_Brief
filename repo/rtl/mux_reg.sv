module mux_reg #(
    parameter DATA_WIDTH = 32
)(
    input   logic [DATA_WIDTH-1:0]  inc_PC_i,
    input   logic [DATA_WIDTH-1:0]  branch_PC_i,
    input   logic [DATA_WIDTH-1:0]  jalr_PC_i,
    input   logic [1:0]             PC_src_i,
    output  logic [DATA_WIDTH-1:0]  next_pc_o
);
    always_comb begin
        case (PC_src_i)
            2'b00: next_pc_o = inc_PC_i; // next instruction
            2'b01: next_pc_o = branch_PC_i; // branch or JAL
            2'b10: next_pc_o = jalr_PC_i; // JALR
            default: next_pc_o = inc_PC_i; // PC + 4
        endcase
    end
endmodule
