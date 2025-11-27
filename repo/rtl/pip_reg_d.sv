module pip_reg_d #(
    PC_WIDTH = 32,
    INSTRUCTION_WIDTH = 32
)(
    input   logic                           clk_i,
    input   logic                           en_i,
    input   logic                           clr_i,

    input   logic [PC_WIDTH-1:0]            PCF_i, //Fetch
    output  logic [PC_WIDTH-1:0]            PCD_o, //Decode
    
    input   logic[INSTRUCTION_WIDTH-1:0]    InstrF_i, //Fetch
    output  logic[INSTRUCTION_WIDTH-1:0]    InstrD_o, //Decode

    input   logic [PC_WIDTH-1:0]            PCPlus4F_i, //Fetch
    output  logic [PC_WIDTH-1:0]            PCPlus4D_o  //Decode
);

always_ff @(posedge clk_i) begin
    if (clr_i) begin
        PCD_o       <= 'b0;
        InstrD_o    <= 'b0;
        PCPlus4D_o  <= 'b0;
    end
    else if (en_i) begin
        PCD_o       <= PCF_i;
        InstrD_o    <= InstrF_i;
        PCPlus4D_o  <= PCPlus4F_i;
    end
    else begin//freeze
        PCD_o       <= PCD_o;
        InstrD_o    <= InstrD_o;
        PCPlus4D_o  <= PCPlus4D_o;
    end
end
endmodule
