module control_unit(
    input   logic   [6:0]   op_i,
    input   logic   [2:0]   funct3_i,
    input   logic   [6:0]   funct7_i,
    output  logic           RegWrite_o,
    output  logic           MemWrite_o,
    output  logic   [3:0]   ALUControl_o, // 4 bit for full ISA
    output  logic           ALUSrc_o,
    output  logic           ALUSrcA_o,    // AUIPC flag
    output  logic   [2:0]   ImmSrc_o,
    output  logic   [1:0]   ResultSrc_o,
    output  logic           Jump_o,
    output  logic           Branch_o
);

    logic       branch;
    logic [1:0] ALUOp;
    logic       jump;
    logic       jalr;

    assign Jump_o = jump || jalr;
    assign Branch_o = branch;

    // Main Decoder
    always_comb begin
        RegWrite_o = 0;
        MemWrite_o = 0;
        ALUSrc_o = 0;
        ALUSrcA_o = 0;
        ResultSrc_o = 0;
        ImmSrc_o = 3'b000;
        branch = 0;
        jump = 0;
        jalr = 0;
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
                
                if (funct3_i == 3'b001 || funct3_i == 3'b101)
                    ImmSrc_o = 3'b101; //shamt
                else 
                    ImmSrc_o = 3'b000; // normal itype
                    
            end
            // I-Type (Load)
            7'b0000011: begin
                RegWrite_o = 1;
                ALUSrc_o = 1;
                ResultSrc_o = 1;  
                ALUOp = 2'b00;
            end
            // S-Type
            7'b0100011: begin
                MemWrite_o = 1;
                ALUSrc_o = 1;
                ImmSrc_o = 3'b010; 
                ALUOp = 2'b00;
            end
            // B-Type
            7'b1100011: begin
                ImmSrc_o = 3'b001;
                branch = 1;
                ALUOp = 2'b01;
            end
            // JAL
            7'b1101111: begin
                RegWrite_o = 1;
                ImmSrc_o = 3'b100;
                ALUOp = 2'b00; 
                jump = 1;
                ResultSrc_o = 2'b10;
            end
            // JALR
            7'b1100111: begin
                RegWrite_o = 1;
                ALUSrc_o = 1;
                ImmSrc_o = 3'b000;
                ALUOp = 2'b00;
                jalr = 1;
                ResultSrc_o = 2'b10;
            end
            // LUI
            7'b0110111: begin
                RegWrite_o = 1;
                ALUSrc_o = 1;
                ImmSrc_o = 3'b011;
                ALUOp = 2'b11; 
            end
            
            // AUIPC
            7'b0010111: begin
                RegWrite_o = 1;
                ALUSrc_o = 1;
                ALUSrcA_o = 1;
                ImmSrc_o = 3'b011;
                ALUOp = 2'b00;
            end
            default: ;
        endcase
    end

    // ALU Decoder
    always_comb begin
        case (ALUOp)
            2'b00: ALUControl_o = 4'b0000; // ADD (LW/SW/JAL/AUIPC)
            2'b01: ALUControl_o = 4'b0001; // SUB (branches)
            2'b11: ALUControl_o = 4'b1111; // LUI

            // R-Type / I-Type / M-Extension
            2'b10: begin
                unique case (funct3_i)
                    3'b000: begin
                        if (op_i == 7'b0110011 && funct7_i == 7'b0000001)
                            ALUControl_o = 4'b1010;   // MUL
                        else if (op_i == 7'b0110011 && funct7_i == 7'b0100000)
                            ALUControl_o = 4'b0001;   // SUB
                        else
                            ALUControl_o = 4'b0000;   // ADD / ADDI
                    end
                    3'b001: begin
                        if (op_i == 7'b0110011 && funct7_i == 7'b0000001)
                            ALUControl_o = 4'b1011;   // MULH 
                        else
                            ALUControl_o = 4'b0101;   // SLL / SLLI
                    end
                    3'b010: begin
                        if (op_i == 7'b0110011 && funct7_i == 7'b0000001)
                            ALUControl_o = 4'b1100;   // MULHSU 
                        else
                            ALUControl_o = 4'b1000;   // SLT / SLTI
                    end
                    3'b011: begin
                        if (op_i == 7'b0110011 && funct7_i == 7'b0000001)
                            ALUControl_o = 4'b1101;   // MULHU 
                        else
                            ALUControl_o = 4'b1001;   // SLTU / SLTIU
                    end
                    3'b100: ALUControl_o = 4'b0100;   // XOR
                    3'b101: begin
                        if (funct7_i == 7'b0100000)
                            ALUControl_o = 4'b0111;   // SRA / SRAI
                        else
                            ALUControl_o = 4'b0110;   // SRL / SRLI
                    end
                    3'b110: ALUControl_o = 4'b0011;   // OR
                    3'b111: ALUControl_o = 4'b0010;   // AND

                    default: ALUControl_o = 4'b0000;
                endcase
            end
            default: ALUControl_o = 4'b0000;
        endcase
    end
endmodule
