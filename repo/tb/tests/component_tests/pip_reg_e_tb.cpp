/*
 *  Component testbench for pip_reg_e
 */

#include "base_testbench.h"

#define TB_NAME PipRegETestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk_i = 0;
        top->clr_i = 0;
        top->RegWriteD_i = 0;
        top->ResultSrcD_i = 0;
        top->MemWriteD_i = 0;
        top->JumpD_i = 0;
        top->BranchD_i = 0;
        top->ALUControlD_i = 0;
        top->funct3D_i = 0;
        top->ALUSrcD_i = 0;
        top->RD1D_i = 0;
        top->RD2D_i = 0;
        top->PCD_i = 0;
        top->Rs1D_i = 0;
        top->Rs2D_i = 0;
        top->RdD_i = 0;
        top->ImmExtD_i = 0;
        top->PCPlus4D_i = 0;
    }
};

//flushing clears all outputs
TEST_F(TB_NAME, FlushClearsState)
{
    top->RegWriteD_i = 1;
    top->ResultSrcD_i = 0b11;
    top->MemWriteD_i = 1;
    top->clr_i = 1;

    top->clk_i = 0; top->eval();
    top->clk_i = 1; top->eval();

    EXPECT_EQ(top->RegWriteE_o, 0);
    EXPECT_EQ(top->MemWriteE_o, 0);
    EXPECT_EQ(top->ResultSrcE_o, 0);
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

