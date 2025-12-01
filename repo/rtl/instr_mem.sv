module instr_mem #(
    parameter ADDRESS_WIDTH = 32,
              BYTE_WIDTH = 8,
              INSTR_WIDTH = 32
)(
    input  logic [ADDRESS_WIDTH-1:0]    A_i,
    output logic [INSTR_WIDTH-1:0]      RD_o
);

    logic [BYTE_WIDTH-1:0] rom_array [4095:0]; 

    initial begin
        $readmemh("program.hex", rom_array); 
    end

    always_comb begin
        // piece together 32 bit word from 4 bytes (little endian)
        RD_o = {
            rom_array[A_i + 3], 
            rom_array[A_i + 2], 
            rom_array[A_i + 1], 
            rom_array[A_i + 0]
        }; 
    end

endmodule
