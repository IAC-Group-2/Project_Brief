/*
 *  Component testbench for pip_reg_d
 */

#include "base_testbench.h"

#define TB_NAME PipRegDTestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk_i = 0;
        top->en_i = 1;
        top->clr_i = 0;
        top->PCF_i = 0;
        top->InstrF_i = 0;
        top->PCPlus4F_i = 0;
    }
};

//pass values if enable is high
TEST_F(TB_NAME, PassThroughOnEnable)
{
    top->PCF_i = 0x10;
    top->InstrF_i = 0x12345678;
    top->PCPlus4F_i = 0x14;

    top->clk_i = 0; top->eval();
    top->clk_i = 1; top->eval();

    EXPECT_EQ(top->PCD_o, 0x10);
    EXPECT_EQ(top->InstrD_o, 0x12345678);
    EXPECT_EQ(top->PCPlus4D_o, 0x14);
}

//output 0 when clear is high
TEST_F(TB_NAME, ClearZerosOutputs)
{
    top->PCF_i = 0xAA;
    top->InstrF_i = 0xBB;
    top->PCPlus4F_i = 0xCC;
    top->clr_i = 1;

    top->clk_i = 0; top->eval();
    top->clk_i = 1; top->eval();

    EXPECT_EQ(top->InstrD_o, 0);
    EXPECT_EQ(top->PCPlus4D_o, 0);
}

//hold values on stall
TEST_F(TB_NAME, HoldOnStall)
{
    top->PCF_i = 0x10;
    top->InstrF_i = 0x2222;
    top->PCPlus4F_i = 0x14;

    top->clk_i = 0; top->eval();
    top->clk_i = 1; top->eval();

    // stall
    top->en_i = 0;
    top->PCF_i = 0x30;
    top->InstrF_i = 0x4444;

    top->clk_i = 0; top->eval();
    top->clk_i = 1; top->eval();

    EXPECT_EQ(top->PCD_o, 0x10);
    EXPECT_EQ(top->InstrD_o, 0x2222);
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

