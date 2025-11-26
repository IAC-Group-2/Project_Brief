module control_unit(
    input   logic   [6:0]   op_i,
    input   logic           Zero_i,
    input   logic   [2:0]   funct3_i,
    input   logic           funct7_i,
    output  logic           RegWrite_o,
    output  logic           MemWrite_o,
    output  logic   [2:0]   ALUControl_o,
    output  logic           ALUSrc_o,
    output  logic   [2:0]   ImmSrc_o,
    output  logic   [1:0]   ResultSrc_o,
    output  logic           PCSrc_o
);

logic branch;
logic [1:0] ALUOp;

// Main Decoder
always_comb begin
    RegWrite_o = 0;
    MemWrite_o = 0;
    ALUSrc_o = 0;
    ResultSrc_o = 2'b00;
    ImmSrc_o = 3'b000;
    branch = 0;
    ALUOp = 2'b00;

    case (op_i) 
        // R-Type
        7'b0110011: begin
            RegWrite_o = 1;
            ALUSrc_o = 0;
            MemWrite_o = 0;
            ResultSrc_o = 2'b00;  // ALU result
            branch = 0;
            ALUOp = 2'b10;
        end

        // I-Type (Arithmetic)
        7'b0010011: begin
            RegWrite_o = 1;
            ALUSrc_o = 1;
            ResultSrc_o = 2'b00;  // ALU result
            ImmSrc_o = 3'b000;
            branch = 0;
            ALUOp = 2'b10;
        end

        // I-Type (Load)
        7'b0000011: begin
            RegWrite_o = 1;
            ALUSrc_o = 1;
            ResultSrc_o = 2'b01;  // Memory data
            ImmSrc_o = 3'b000; 
            branch = 0;
            ALUOp = 2'b00;
        end
         // B-Type
        7'b1100011: begin 
            RegWrite_o = 0;
            MemWrite_o = 0;
            ALUSrc_o = 0;
            ImmSrc_o = 3'b001; 
            branch = 1;
            ALUOp = 2'b01;
        end
        
        default: begin
            RegWrite_o = 0;
            MemWrite_o = 0;
            ALUSrc_o = 0;
            ResultSrc_o = 2'b00;
            ImmSrc_o = 3'b000;
            branch = 0;
            ALUOp = 2'b00;
        end
    endcase
    PCSrc_o = branch & ~Zero_i;
end

// ALU decoder
always_comb begin
    case(ALUOp)
        2'b00: ALUControl_o = 3'b000;
        2'b01: ALUControl_o = 3'b001;

        // R-Type and I-Type
        2'b10: begin
            case (funct3_i)
                3'b000: begin
                    if (op_i[5] & funct7_i) ALUControl_o = 3'b001; // sub
                    else ALUControl_o = 3'b000; // add
                end
                3'b010:  ALUControl_o = 3'b101; // slt
                3'b110:  ALUControl_o = 3'b011; // or
                3'b111:  ALUControl_o = 3'b010; // and

                default: ALUControl_o = 3'b000;
            endcase
        end
        default: ALUControl_o = 3'b000;
    endcase
end

always_comb begin
        if (branch) begin
            if (funct3_i[0] == 1'b1) 
                PCSrc_o = ~Zero_i; // BNE (Branch if Not Zero)
            else                     
                PCSrc_o = Zero_i;  // BEQ (Branch if Zero)
        end else begin
            PCSrc_o = 0;
        end
    end

endmodule
