/*
 * Component testbench for mux_reg
 */

#include "base_testbench.h"

#define TB_NAME MuxRegTestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->PCPlus4F_i = 0;
        top->PredictTargetF_i = 0;
        top->PredictTakenF_i = 0;
        top->MispredictE_i = 0;
        top->PCTargetE_i = 0;
        top->ALUResultE_i = 0;
        top->PCPlus4E_i = 0;
        top->PCSrcE_i = 0;
        top->JalrE_i = 0;
    }
};

// default: no prediction, no branch - PC advance normally
TEST_F(TB_NAME, DefaultTakesPcPlus4)
{
    top->PCPlus4F_i = 0x10;
    top->MispredictE_i = 0;
    top->PredictTakenF_i = 0;
    
    top->eval();
    EXPECT_EQ(top->PCNext_o, 0x10u);
}

// prediction taken: pipeline should follow the predicte dtaken
TEST_F(TB_NAME, PredictionTakesPredictTarget)
{
    top->PredictTargetF_i = 0x400;
    top->PredictTakenF_i = 1;
    top->MispredictE_i = 0;
    
    top->eval();
    EXPECT_EQ(top->PCNext_o, 0x400u);
}

// mispredicted branch: PC corrected to actual branch target
TEST_F(TB_NAME, BranchCorrectionTakesTarget)
{
    top->PCTargetE_i = 0x200;
    top->PCSrcE_i = 1;
    top->JalrE_i = 0;
    top->MispredictE_i = 1;
    
    top->eval();
    EXPECT_EQ(top->PCNext_o, 0x200u);
}

//mispredicted JALR: PC take ALU result (reutrn address)
TEST_F(TB_NAME, JalrCorrectionUsesAluResult)
{
    top->ALUResultE_i = 0xDEADBEEF;
    top->PCTargetE_i = 0x12340000; //should ignore this
    
    top->PCSrcE_i = 1;
    top->JalrE_i = 1;
    top->MispredictE_i = 1;

    top->eval();
    EXPECT_EQ(top->PCNext_o, 0xDEADBEEF);
}

//mispredicted not taken branch: PC+4E
TEST_F(TB_NAME, MispredictRevertToFallthrough)
{
    top->PCPlus4E_i = 0x88;
    top->PCSrcE_i = 0;
    top->MispredictE_i = 1;
    
    top->eval();
    EXPECT_EQ(top->PCNext_o, 0x88u);
}

int main(int argc, char **argv)
{
    top = new Vdut;
    tfp = new VerilatedVcdC;

    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("mux_reg.vcd");

    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    top->final();
    tfp->close();

    delete top;
    delete tfp;

    return res;
}