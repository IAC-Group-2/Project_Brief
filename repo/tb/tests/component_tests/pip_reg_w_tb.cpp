/*
 *  Component testbench for pip_reg_w
 */

#include "base_testbench.h"

#define TB_NAME PipRegWTestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk_i = 0;
        top->RegWriteM_i = 0;
        top->ResultSrcM_i = 0;
        top->ALUResultM_i = 0;
        top->ReadDataM_i = 0;
        top->RdM_i = 0;
        top->PCPlus4M_i = 0;
    }
};

TEST_F(TB_NAME, PipelineWTest)
{
    top->RegWriteM_i = 1;
    top->ResultSrcM_i = 0b10;
    top->ALUResultM_i = 0xDEADBEEF;
    top->ReadDataM_i = 0xA5A5A5A5;
    top->RdM_i = 0x0F;
    top->PCPlus4M_i = 0x40;
    top->en_i = 1;

    top->clk_i = 0; top->eval();
    top->clk_i = 1; top->eval();

    EXPECT_EQ(top->RegWriteW_o, 1);
    EXPECT_EQ(top->ResultSrcW_o, 2);
    EXPECT_EQ(top->ALUResultW_o, 0xDEADBEEF);
    EXPECT_EQ(top->ReadDataW_o, 0xA5A5A5A5);
    EXPECT_EQ(top->RdW_o, 0x0F);
    EXPECT_EQ(top->PCPlus4W_o, 0x40);
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

