module control_unit(
    input   logic   [6:0]   op_i,
    input   logic   [2:0]   funct3_i,
    input   logic           funct7_i,
    output  logic           RegWrite_o,
    output  logic           MemWrite_o,
    output  logic   [2:0]   ALUControl_o,
    output  logic           ALUSrc_o,
    output  logic   [2:0]   ImmSrc_o,
    output  logic   [1:0]   ResultSrc_o,
    output  logic           Jump_o,
    output  logic           Branch_o
);

    logic [1:0] ALUOp;
    logic       jalr;

    // Main Decoder
    always_comb begin
        RegWrite_o  = 0;
        MemWrite_o  = 0;
        ALUSrc_o    = 0;
        ResultSrc_o = 0;
        ImmSrc_o    = 3'b000;
        Branch_o      = 0;
        Jump_o        = 0;
        jalr        = 0;
        ALUOp       = 2'b00;

        case (op_i) 
            // R-Type
            7'b0110011: begin
                RegWrite_o = 1;
                ALUOp      = 2'b10;
            end
            // I-Type (Arithmetic)
            7'b0010011: begin
                RegWrite_o = 1;
                ALUSrc_o   = 1;
                ALUOp      = 2'b10;
            end
            // I-Type (Load)
            7'b0000011: begin
                RegWrite_o  = 1;
                ALUSrc_o    = 1;
                ResultSrc_o = 1;  
                ALUOp       = 2'b00;
            end
            // S-Type
            7'b0100011: begin
                MemWrite_o = 1;
                ALUSrc_o   = 1;
                ImmSrc_o   = 3'b010; 
                ALUOp      = 2'b00;
            end
            // B-Type
            7'b1100011: begin
                ImmSrc_o = 3'b001;
                Branch_o   = 1;
                ALUOp    = 2'b01;
            end
            // JAL
            7'b1101111: begin
                RegWrite_o  = 1;
                ImmSrc_o    = 3'b100;
                ALUOp       = 2'b00; 
                Jump_o        = 1;
                ResultSrc_o = 2'b10; 
            end
            // JALR
            7'b1100111: begin
                RegWrite_o  = 1;
                ALUSrc_o    = 1;
                ImmSrc_o    = 3'b000;
                ALUOp       = 2'b00;
                jalr        = 1;
                Jump_o        = 1;
                ResultSrc_o = 2'b10;
            end
            // LUI
            7'b0110111: begin
                RegWrite_o = 1;
                ALUSrc_o   = 1;
                ImmSrc_o   = 3'b011;
                ALUOp      = 2'b11; 
            end
            default: ;
        endcase
    end

    // ALU Decoder
    always_comb begin
        case(ALUOp)
            2'b00: ALUControl_o = 3'b000; // ADD
            2'b01: ALUControl_o = 3'b001; // SUB 
            2'b11: ALUControl_o = 3'b100; // LUI 
            // R-Type or I-Type, decided by funct3
            2'b10: begin
                case (funct3_i)
                    // ADD or SUB/ADDI, decided by funct7 and op_i[5]
                    3'b000: ALUControl_o = (funct7_i && op_i[5]) ? 3'b001 : 3'b000;
                    3'b001: ALUControl_o = 3'b110; // SLL
                    3'b010: ALUControl_o = 3'b101; // SLT
                    3'b110: ALUControl_o = 3'b011; // OR
                    3'b111: ALUControl_o = 3'b010; // AND
                    default: ALUControl_o = 3'b000;
                endcase
            end
            default: ALUControl_o = 3'b000;
        endcase
    end

    
    

endmodule
