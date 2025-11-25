module sign_extend #(
    parameter DATA_WIDTH = 32
)(
    input  logic [2:0]            imm_src_i, // 3 bits: 5 sign extending instructions
    input  logic [DATA_WIDTH-1:0] imm_instr_i,
    output logic [DATA_WIDTH-1:0] imm_ext_o
);

always_comb begin
    case (imm_src_i)
        // I-type
        3'b000: imm_ext_o = {
            {20{imm_instr_i[31]}},
            imm_instr_i[31:20]
        };

        // B-type
        3'b001: imm_ext_o = {
            {19{imm_instr_i[31]}}, 
            imm_instr_i[31],
            imm_instr_i[7],         
            imm_instr_i[30:25],     
            imm_instr_i[11:8],        
            1'b0                      
        };

        // S-type
        3'b010: imm_ext_o = {
            {20{imm_instr_i[31]}},
            imm_instr_i[31:25],
            imm_instr_i[11:7]
        };

        // U-type
        3'b011: imm_ext_o = { 
            imm_instr_i[31:12], 12'b0 
        };

        // J-type
        3'b100: imm_ext_o = {
            {11{imm_instr_i[31]}},
            imm_instr_i[31],
            imm_instr_i[19:12],
            imm_instr_i[20],
            imm_instr_i[30:21],
            1'b0         
        };
        default: imm_ext_o = {DATA_WIDTH{1'b0}};
    endcase
end

endmodule
