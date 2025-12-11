module mux_reg #(
    parameter DATA_WIDTH = 32
)(
    input  logic [DATA_WIDTH-1:0] PCPlus4F_i,
    input  logic [DATA_WIDTH-1:0] PredictTargetF_i, //prediction target
    input  logic                  PredictTakenF_i,  //predictor decision
    input  logic                  MispredictE_i,
    input  logic [DATA_WIDTH-1:0] PCTargetE_i,
    input  logic [DATA_WIDTH-1:0] ALUResultE_i,
    input  logic [DATA_WIDTH-1:0] PCPlus4E_i, //correction address for misprediction
    input  logic                  PCSrcE_i,
    input  logic                  JalrE_i,
    output logic [DATA_WIDTH-1:0] PCNext_o
);

    logic [DATA_WIDTH-1:0] ActualTargetE;

    always_comb begin
        //select correct branch or jump target in execution stage
        //JALR uses ALU result, others use PCTargetE
        ActualTargetE = (JalrE_i) ? ALUResultE_i : PCTargetE_i;

        if (MispredictE_i) begin
            if (PCSrcE_i) 
                PCNext_o = ActualTargetE; //predicted: not taken, but should have taken
            else          
                PCNext_o = PCPlus4E_i;    //predict: taken, but should have fall through (not taken)
        end
        else if (PredictTakenF_i) begin
            //prediction taken
            PCNext_o = PredictTargetF_i;
        end
        else begin
            //default
            PCNext_o = PCPlus4F_i;
        end
    end

endmodule
