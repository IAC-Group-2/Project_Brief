/* verilator lint_off UNUSED */
module data_memory #(
    parameter   ADDRESS_WIDTH = 32,
                DATA_WIDTH = 32,
                BYTE_WIDTH = 8
)(
    input  logic                   clk_i,
    input  logic                   wr_en_i,
    input  logic [2:0]             funct3_i,
    input  logic [ADDRESS_WIDTH-1:0] addr_i,
    input  logic [DATA_WIDTH-1:0]  data_i,
    output logic [DATA_WIDTH-1:0]  data_o
);

    // 0x00000 to 0x1FFFF
    logic [BYTE_WIDTH-1:0] ram_array [32'h1FFFF:0]; 

    initial begin
        // load data.hex starting at address 0x10000 for pdf function
        $readmemh("data.hex", ram_array, 32'h10000); 
    end

    // memory read
    always_comb begin
        // funct3 010: load word
        // funct3 000/100: byte
        if (funct3_i == 3'b010) begin // load word
            data_o = {
                ram_array[addr_i[16:0] + 3], 
                ram_array[addr_i[16:0] + 2], 
                ram_array[addr_i[16:0] + 1], 
                ram_array[addr_i[16:0]]
            };
        end else begin // load byte (zero extended)
            data_o = {24'b0, ram_array[addr_i[16:0]]};
        end
    end

    // memory write
    always @(posedge clk_i) begin
        if (wr_en_i) begin
            if (funct3_i == 3'b010) begin // store word
                ram_array[addr_i[16:0]]     <= data_i[7:0];
                ram_array[addr_i[16:0] + 1] <= data_i[15:8];
                ram_array[addr_i[16:0] + 2] <= data_i[23:16];
                ram_array[addr_i[16:0] + 3] <= data_i[31:24];
            end else begin // store byte
                ram_array[addr_i[16:0]] <= data_i[7:0];
            end
        end
    end

endmodule
