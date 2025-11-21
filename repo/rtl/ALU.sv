module ALU #(
    DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  SrcA,
    input   logic [DATA_WIDTH-1:0]  SrcB,
    input   logic [2:0]             ALUControl,
    output  logic [DATA_WIDTH-1:0]  ALUResult,
    output  logic                   Zero
);
always_comb begin
    ALUResult = 0;
    Zero = 0;
    case (ALUControl) //codes given in lecture notes
        3'b000: ALUResult = SrcA + SrcB; //add
        3'b001: ALUResult = SrcA - SrcB; //subtract
        3'b101: Zero = SrcA < SrcB; //set less than
        3'b011: ALUResult = SrcA | SrcB; //bitwise or
        3'b010: ALUResult = SrcA & SrcB; //bitwise and
        default:
            begin
            Zero = 0;
            ALUResult = 0;
            end
    endcase
end

endmodule
