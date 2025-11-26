module pc_reg #(
    parameter DATA_WIDTH = 32
)(
    input logic                     clk_i,
    input logic                     rst_i,
    input logic                     en_i,
    input logic  [DATA_WIDTH-1:0]   PCNext_i,
    output logic [DATA_WIDTH-1:0]   PC_o
);

always_ff @(posedge clk_i, posedge rst_i) 
    if (rst_i) 
        PC_o    <= 0;
    else if (en_i)
        PC_o    <= PCNext_i;
    else //freeze
        PC_o    <= PC_o; 

endmodule
