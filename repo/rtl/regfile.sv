module regfile #(
    ADDRESS_WIDTH = 5,
    DATA_WIDTH = 32
) (
    input   logic                       clk_i,
    input   logic [ADDRESS_WIDTH-1:0]   A1_i,
    input   logic [ADDRESS_WIDTH-1:0]   A2_i,
    input   logic [ADDRESS_WIDTH-1:0]   A3_i,
    input   logic [DATA_WIDTH-1:0]      WD3_i,
    input   logic                       WE3_i,
    output  logic [DATA_WIDTH-1:0]      RD1_o,
    output  logic [DATA_WIDTH-1:0]      RD2_o,
);
    //create ram with the defined logic
    logic [DATA_WIDTH-1:0] mem [2**ADDRESS_WIDTH-1:0];

    //write on posedge of clock
    always_ff@(posedge clk_i) begin
        if (WE3_i)
            mem[A3_i] <= WD3_i;
    end

    //read commands
    assign RD1_o = mem[A1_i];
    assign RD2_o = mem[A2_i];
endmodule