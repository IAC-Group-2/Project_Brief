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
        Zero_o = 1'b0;
        case (ALUControl_i)

            3'b000: begin
                ALUResult_o = SrcA_i + SrcB_i; // ADD
            end
            3'b001: begin 
                ALUResult_o = SrcA_i - SrcB_i; // SUB
                Zero_o = (SrcA_i == SrcB_i);
            end
            3'b010: begin
                ALUResult_o = SrcA_i & SrcB_i; // AND
            end
            3'b011: begin
                ALUResult_o = SrcA_i | SrcB_i; // OR  
            end          
            3'b100: begin
                ALUResult_o = SrcB_i;// LUI
            end
            3'b110: begin
                ALUResult_o = SrcA_i << SrcB_i[4:0]; // SLL
            end
            3'b101: begin // SLT
                ALUResult_o = ($signed(SrcA_i) < $signed(SrcB_i)) ? 32'd1 : 32'd0;
                Zero_o      = ($signed(SrcA_i) < $signed(SrcB_i));  
            end
            default: begin
                ALUResult_o = 0;
                Zero_o = 0;
            end

        endcase
    end

endmodule
