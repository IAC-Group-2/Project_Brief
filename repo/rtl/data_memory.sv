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
    logic [16:0] addr_idx;

    assign addr_idx = addr_i[16:0];

    initial begin
        // load data.hex starting at address 0x10000 for pdf function
        $readmemh("data.hex", ram_array, 32'h10000); 
    end

    // memory read
    always_comb begin
        case(funct3_i)
            3'b010: // LW
                data_o = {
                    ram_array[addr_idx + 3], 
                    ram_array[addr_idx + 2], 
                    ram_array[addr_idx + 1], 
                    ram_array[addr_idx]
                };

            3'b000: //LB
                data_o = {
                    {24{ram_array[addr_idx][7]}}, 
                    ram_array[addr_idx]
                };

            3'b100: 
                data_o = {24'b0, ram_array[addr_idx]}; // LBU
            
            // Halfwords
            3'b001: // LH
                data_o = {
                    {16{ram_array[addr_idx+1][7]}}, 
                    ram_array[addr_idx+1], 
                    ram_array[addr_idx]
                };
            3'b101: // LHU
                data_o = {16'b0, ram_array[addr_idx+1], 
                ram_array[addr_idx]
                };
            default: data_o = 32'b0;
        endcase
    end

    // memory write
    always @(posedge clk_i) begin
        if (wr_en_i) begin
            case (funct3_i)
                3'b010: begin // SW
                    ram_array[addr_idx] <= data_i[7:0]; 
                    ram_array[addr_idx + 1] <= data_i[15:8];
                    ram_array[addr_idx + 2] <= data_i[23:16]; 
                    ram_array[addr_idx + 3] <= data_i[31:24];
                end

                3'b000: ram_array[addr_idx] <= data_i[7:0]; // SB
                
                3'b001: begin // SH
                    ram_array[addr_idx] <= data_i[7:0]; 
                    ram_array[addr_idx+1] <= data_i[15:8]; 
                end
                default: ;
            endcase
        end
    end

endmodule
