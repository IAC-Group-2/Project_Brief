module pip_reg_d #(
    PC_WIDTH = 32,
    INSTRUCTION_WIDTH = 32
)(
    input   logic                           clk_i,
    input   logic                           en_i,
    input   logic [PC_WIDTH-1:0]            pcF_i, //Fetch
    output  logic [PC_WIDTH-1:0]            pcD_o, //Decode
    
    input   logic[INSTRUCTION_WIDTH-1:0]    InstrF_i, //Fetch
    output  logic[INSTRUCTION_WIDTH-1:0]    InstrD_o, //Decode

    input   logic [PC_WIDTH-1:0]            pcPlus4F_i, //Fetch
    output  logic [PC_WIDTH-1:0]            pcPlus4D_o  //Decode
);

always_ff @(posedge clk_i) begin
    if (en_i) begin
        pcD_o       <= pcF_i;
        InstrD_o    <= InstrF_i;
        pcPlus4D_o  <= pcPlus4F_i;
    end
    else begin//freeze
        pcD_o       <= pcD_o;
        InstrD_o    <= InstrD_o;
        pcPlus4D_o  <= pcPlus4D_o;
    end
end
endmodule
