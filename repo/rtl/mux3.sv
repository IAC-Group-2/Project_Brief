// generic mux3 to help cleanup top.sv file
module mux3 #(
    parameter DATA_WIDTH = 32
)(
    input  logic [DATA_WIDTH-1:0] in0_i,
    input  logic [DATA_WIDTH-1:0] in1_i,
    input  logic [DATA_WIDTH-1:0] in2_i,
    input  logic [1:0]            sel_i,
    output logic [DATA_WIDTH-1:0] out_o
);

    always_comb begin
        case (sel_i)
            2'b00: out_o = in0_i;
            2'b01: out_o = in1_i;
            2'b10: out_o = in2_i;
            default: out_o = in0_i;
        endcase
    end

endmodule