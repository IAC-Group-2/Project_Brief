module hazard_unit#(
    REGISTER_ADDRESS_WIDTH = 5
)(
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]      Rs1D_i,
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]      Rs2D_i,
  
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]      Rs1E_i,
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]      Rs2E_i,
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]      RdE_i,
    input   logic                                   ResultSrcE0_i,

    input   logic [REGISTER_ADDRESS_WIDTH-1:0]      RdM_i,
    input   logic                                   RegWriteM_i,
 
    input   logic [REGISTER_ADDRESS_WIDTH-1:0]      RdW_i,
    input   logic                                   RegWriteW_i,

    input   logic                                   PCSrcE_i,

    output  logic [1:0]                             ForwardAE_o,
    output  logic [1:0]                             ForwardBE_o,

    output  logic                                   StallF_o,
    output  logic                                   StallD_o,
    output  logic                                   FlushD_o,
    output  logic                                   FlushE_o
);
    logic                                           lwStall;
    always_comb begin
        ForwardAE_o = 2'b00;
        ForwardBE_o = 2'b00;
        StallF_o    = 1'b0;
        StallD_o    = 1'b0;
        FlushD_o    = 1'b0;
        FlushE_o    = 1'b0;
        lwStall     = 1'b0;
        
        if (((Rs1E_i == RdM_i) && RegWriteM_i) && (Rs1E_i != '0)) begin //Forward from Memory Stage
            ForwardAE_o = 2'b10;
        end
        else if (((Rs1E_i == RdW_i) && RegWriteW_i) && (Rs1E_i != '0)) begin //Forward from Writeback stage
            ForwardAE_o = 2'b01;
        end
        else begin
            ForwardAE_o = 2'b00; //no forwarding
        end

        if (((Rs2E_i == RdM_i) && RegWriteM_i) && (Rs2E_i != '0)) begin //Forward from Memory Stage
            ForwardBE_o = 2'b10;
        end
        else if (((Rs2E_i == RdW_i) && RegWriteW_i) && (Rs2E_i != '0)) begin
            ForwardBE_o = 2'b01; //Forward from Writeback stage
        end
        else begin
            ForwardBE_o = 2'b00; //no forwarding
        end

        lwStall = ResultSrcE0_i && ((Rs1D_i == RdE_i) || (Rs2D_i == RdE_i)); //logic to determine if stall is needed

        //Stall logic (Stall for one clock cycle at a time)
        StallF_o = lwStall;
        StallD_o = lwStall;

        //Flush logic
        FlushD_o = PCSrcE_i;
        FlushE_o = lwStall || PCSrcE_i;
    end

endmodule
