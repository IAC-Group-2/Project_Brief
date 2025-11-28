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
    output  logic           ResultSrc_o,
    output  logic           PCSrc_o
);

logic branch;
logic jump;
logic [1:0] ALUOp;

// Main Decoder
always_comb begin
    // Default values
    RegWrite_o = 0;
    MemWrite_o = 0;
    ALUSrc_o = 0;
    ResultSrc_o = 0;
    ImmSrc_o = 3'b000; // I-type immediate
    branch = 0;
    jump = 0;
    ALUOp = 2'b00;

    case (op_i) 
        // R-Type
        7'b0110011: begin
            RegWrite_o = 1;
            ALUOp = 2'b10;
        end

        // I-Type (Arithmetic)
        7'b0010011: begin
            RegWrite_o = 1;
            ALUSrc_o = 1;
            ALUOp = 2'b10;
        end

        // I-Type (Load)
        7'b0000011: begin
            RegWrite_o = 1;
            ALUSrc_o = 1;
            ResultSrc_o = 1;  
            ALUOp = 2'b00;
        end

        // B-Type
        7'b1100011: begin
            ImmSrc_o = 3'b001; 
            branch = 1;
            ALUOp = 2'b01;
        end

        // S-Type (Store)
        7'b0100011: begin
            MemWrite_o = 1;
            ALUSrc_o = 1;
            ImmSrc_o = 3'b010; 
            ALUOp = 2'b00;
        end

        // J-Type (JAL)
        7'b1101111: begin
            RegWrite_o = 1;
            ImmSrc_o = 3'b100;
            ALUOp = 2'b00; 
            jump = 1;
        end
        
        default: ; // already defined above
    endcase
end

// ALU decoder
always_comb begin
    case(ALUOp)
        2'b00: ALUControl_o = 3'b000;
        2'b01: ALUControl_o = 3'b001;
        default: ALUControl_o = 3'b000;
    endcase
end

// PC Source Selector
always_comb begin
    if (jump) begin
        // JAL or JALR: Always take the jump
        PCSrc_o = 1'b1;
    end else if (branch) begin
        // B-Type: Conditional branch decision
        if (ALUControl_o == 3'b001 && ALUOp == 2'b01) 
            PCSrc_o = ~Zero_i; // BNE (branch is not zero)
        else                     
            PCSrc_o = Zero_i; // BEQ (branch if zero)
    end else begin
        // R/I/S-Type
        PCSrc_o = 1'b0;
    end
end

endmodule
