module Data_Memory #(
    parameter ADDRESS_WIDTH = 8,
              DATA_WIDTH = 8
)(
    //diagram specifies wr_en_i only so will always be reading/ writing. No re_en_i.
    //also specifies one address in
    input logic clk_i,
    input logic wr_en_i,
    input logic [ADDRESS_WIDTH-1:0] addr_i,
    input logic [DATA_WIDTH-1:0] data_i,
    output logic [DATA_WIDTH-1:0] data_o
);

logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

always_ff @(posedge clk_i) begin
    if (wr_en_i == 1'b1)
        ram_array[addr_i] <= data_i;
    else
        // output is synchronous
        data_o <= ram_array[addr_i];
end

endmodule
