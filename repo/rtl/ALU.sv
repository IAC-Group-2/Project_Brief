module ALU #(
    parameter DATA_WIDTH = 32
)(
    input   logic [DATA_WIDTH-1:0]  SrcA_i,
    input   logic [DATA_WIDTH-1:0]  SrcB_i,
    input   logic [3:0]             ALUControl_i,
    output  logic [DATA_WIDTH-1:0]  ALUResult_o,
    output  logic                   Zero_o
);
    //64 bit extended operands to have full multiplication precision
    logic signed [2*DATA_WIDTH-1:0] sign_ext_A;
    logic signed [2*DATA_WIDTH-1:0] sign_ext_B;
    logic signed [2*DATA_WIDTH-1:0] zero_ext_A;
    logic signed [2*DATA_WIDTH-1:0] zero_ext_B;

    logic signed [2*DATA_WIDTH-1:0] signed_product;
    logic [2*DATA_WIDTH-1:0] unsigned_product;
    logic signed [2*DATA_WIDTH-1:0] signed_unsigned_product;


    always_comb begin
        //prepare sign extended operands
        sign_ext_A = {{DATA_WIDTH{SrcA_i[DATA_WIDTH-1]}}, SrcA_i}; // Sign Extend
        sign_ext_B = {{DATA_WIDTH{SrcB_i[DATA_WIDTH-1]}}, SrcB_i}; 
        zero_ext_A = {{DATA_WIDTH{1'b0}}, SrcA_i};                 // Zero Extend
        zero_ext_B = {{DATA_WIDTH{1'b0}}, SrcB_i};

        //64 bit multiplcation
        signed_product          = sign_ext_A * sign_ext_B;
        unsigned_product        = zero_ext_A * zero_ext_B;
        signed_unsigned_product = sign_ext_A * zero_ext_B; // Signed * Unsigned

        ALUResult_o = {DATA_WIDTH{1'b0}};
        
        case (ALUControl_i)
            4'b0001: ALUResult_o = SrcA_i - SrcB_i; // SUB
            4'b0000: ALUResult_o = SrcA_i + SrcB_i; // ADD
            4'b0010: ALUResult_o = SrcA_i & SrcB_i; // AND
            4'b0011: ALUResult_o = SrcA_i | SrcB_i; // OR
            4'b0100: ALUResult_o = SrcA_i ^ SrcB_i; // XOR
            
            4'b0101: ALUResult_o = SrcA_i << SrcB_i[4:0]; // SLL
            4'b0110: ALUResult_o = SrcA_i >> SrcB_i[4:0]; // SRL
            4'b0111: ALUResult_o = $signed(SrcA_i) >>> SrcB_i[4:0]; // SRA

            4'b1000: begin // SLT
                if ($signed(SrcA_i) < $signed(SrcB_i)) 
                    ALUResult_o = {{DATA_WIDTH-1{1'b0}}, 1'b1};
                else 
                    ALUResult_o = {DATA_WIDTH{1'b0}};
            end
            
            4'b1001: begin // SLTU
                if (SrcA_i < SrcB_i) 
                    ALUResult_o = {{DATA_WIDTH-1{1'b0}}, 1'b1};
                else 
                    ALUResult_o = {DATA_WIDTH{1'b0}};
            end
            
            4'b1010: ALUResult_o = unsigned_product[DATA_WIDTH-1:0]; // MUL
            4'b1011: ALUResult_o = signed_product[2*DATA_WIDTH-1:DATA_WIDTH]; // MULH
            4'b1100: ALUResult_o = signed_unsigned_product[2*DATA_WIDTH-1:DATA_WIDTH]; // MULHSU
            4'b1101: ALUResult_o = unsigned_product[2*DATA_WIDTH-1:DATA_WIDTH]; // MULHU
            
            4'b1111: ALUResult_o = SrcB_i; // LUI (Pass B)
            
            default: ALUResult_o = {DATA_WIDTH{1'b0}};
        endcase
    end

    // Zero flag: only if result is exactly zero
    assign Zero_o = (ALUResult_o == {DATA_WIDTH{1'b0}});

endmodule
