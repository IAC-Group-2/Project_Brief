/*
 *  Component testbench for regfile
 */

#include "base_testbench.h"

#define TB_NAME RegfileTestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk_i = 0;
        top->A1_i = 0;
        top->A2_i = 0;
        top->A3_i = 0;
        top->WD3_i = 0;
        top->WE3_i = 0;
    }

    void tick()
    {
        top->clk_i = 0;
        top->eval();
        top->clk_i = 1;
        top->eval();
    }
};

// writing to a register
TEST_F(TB_NAME, WriteRegisterTest)
{
    top->A3_i = 5;      // address
    top->WD3_i = 1234;  // data
    top->WE3_i = 1;     // write enable

    tick();  // posedge write

    top->A1_i = 5;
    top->eval();

    EXPECT_EQ(top->RD1_o, 1234);
}

// test simultaneous read of two registers
TEST_F(TB_NAME, DualReadTest)
{
    // reg 3 = 1111
    top->A3_i = 3;
    top->WD3_i = 1111;
    top->WE3_i = 1;
    tick();

    // reg 7 = 2222
    top->A3_i = 7;
    top->WD3_i = 2222;
    top->WE3_i = 1;
    tick();

    // read both
    top->A1_i = 3;
    top->A2_i = 7;
    top->eval();

    EXPECT_EQ(top->RD1_o, 1111);
    EXPECT_EQ(top->RD2_o, 2222);
}

// write disabled so no memory change
TEST_F(TB_NAME, WriteEnableOffTest)
{
    // addr 4 write
    top->A3_i = 4;
    top->WD3_i = 5555;
    top->WE3_i = 1;
    tick();

    // overwrite with write disabled
    top->A3_i = 4;
    top->WD3_i = 9999;
    top->WE3_i = 0;
    tick();

    top->A1_i = 4;
    top->eval();

    EXPECT_EQ(top->RD1_o, 5555);
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