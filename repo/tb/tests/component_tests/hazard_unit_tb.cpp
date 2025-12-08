/*
 *  Component testbench for hazard_unit
 */

#include "base_testbench.h"

#define TB_NAME HazardUnitTestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->Rs1D_i = 0;
        top->Rs2D_i = 0;
        top->Rs1E_i = 0;
        top->Rs2E_i = 0;
        top->RdE_i = 0;
        top->ResultSrcE0_i = 0;
        top->RdM_i = 0;
        top->RegWriteM_i = 0;
        top->RdW_i = 0;
        top->RegWriteW_i = 0;
        top->PCSrcE_i = 0;
    }
};

TEST_F(TB_NAME, ForwardFromMemory)
{
    top->Rs1E_i = 5;
    top->RdM_i = 5;
    top->RegWriteM_i = 1;
    top->eval();
    EXPECT_EQ(top->ForwardAE_o, 2);
}

TEST_F(TB_NAME, ForwardFromWriteback)
{
    top->Rs2E_i = 3;
    top->RdW_i = 3;
    top->RegWriteW_i = 1;
    top->eval();
    EXPECT_EQ(top->ForwardBE_o, 1);
}

TEST_F(TB_NAME, LoadUseStall)
{
    top->ResultSrcE0_i = 1;
    top->RdE_i = 8;
    top->Rs1D_i = 8;
    top->eval();
    EXPECT_EQ(top->StallD_o, 1);
    EXPECT_EQ(top->StallF_o, 1);
}

// lw stall flush behavior
TEST_F(TB_NAME, LoadUseStallFlushesExecute)
{
    top->ResultSrcE0_i = 1;
    top->RdE_i = 4;
    top->Rs1D_i = 4;
    top->PCSrcE_i = 0;
    top->eval();
    EXPECT_EQ(top->StallD_o, 1);
    EXPECT_EQ(top->StallF_o, 1);
    EXPECT_EQ(top->FlushE_o, 1);
}

int main(int argc, char **argv)
{
    top = new Vdut;
    tfp = new VerilatedVcdC;

    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    top->final();
    tfp->close();

    delete top;
    delete tfp;

    return res;
}

