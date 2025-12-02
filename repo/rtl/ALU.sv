module ALU #(
    parameter DATA_WIDTH = 32
)(
    input   logic [DATA_WIDTH-1:0]  SrcA_i,
    input   logic [DATA_WIDTH-1:0]  SrcB_i,
    input   logic [2:0]             ALUControl_i,
    output  logic [DATA_WIDTH-1:0]  ALUResult_o,
    output  logic                   Zero_o
);

    always_comb begin
        ALUResult_o = {DATA_WIDTH{1'b0}};
        case (ALUControl_i)
            3'b000: ALUResult_o = SrcA_i + SrcB_i; // ADD
            3'b001: ALUResult_o = SrcA_i - SrcB_i; // SUB
            3'b010: ALUResult_o = SrcA_i & SrcB_i; // AND
            3'b011: ALUResult_o = SrcA_i | SrcB_i; // OR            
            3'b100: ALUResult_o = SrcB_i;// LUI
            3'b110: ALUResult_o = SrcA_i << SrcB_i[4:0]; // SLLI
            3'b101: begin // SLT
                if ($signed(SrcA_i) < $signed(SrcB_i)) 
                    ALUResult_o = {{DATA_WIDTH-1{1'b0}}, 1'b1};
                else 
                    ALUResult_o = {DATA_WIDTH{1'b0}};
            end
            default: ALUResult_o = {DATA_WIDTH{1'b0}};
        endcase
    end

    assign Zero_o = (ALUResult_o == {DATA_WIDTH{1'b0}});

endmodule