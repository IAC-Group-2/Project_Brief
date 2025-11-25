module pc_reg #(
    parameter DATA_WIDTH = 32
)(
    input logic                     clk_i,
    input logic                     rst_i,
    input logic                     en_i,
    input logic  [DATA_WIDTH-1:0]   pcNext_i,
    output logic [DATA_WIDTH-1:0]   pc_o
);

always_ff @(posedge clk_i, posedge rst_i) 
    if (rst_i) 
        pc_o <= 0;
    else if (en_i)
        pc_o <= pcNext_i;
    else
        pc_o <= pc_o; //freeze

endmodule
