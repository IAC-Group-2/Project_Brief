/*
 *  Component testbench for pc_reg
 */

#include "base_testbench.h"

#define TB_NAME PCRegTestbench 

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk_i     = 0;
        top->rst_i     = 0;
        top->en_i      = 0;
        top->PCNext_i  = 0;
    }

    // toggle clock
    void tick()
    {
        top->clk_i = 0;
        top->eval();
        top->clk_i = 1;
        top->eval();
        ticks++;
    }
};

// reset behaviour: PC_o should go to 0
TEST_F(TB_NAME, ResetClearsPC)
{
    top->rst_i = 1;
    tick();
    EXPECT_EQ(top->PC_o, 0);

    top->rst_i = 0; // release reset
}

// PC should update to PCNext_i when en_i = 1
TEST_F(TB_NAME, PCUpdatesWhenEnabled)
{
    top->PCNext_i = 4;
    top->en_i = 1;

    tick();   // clock
    EXPECT_EQ(top->PC_o, 4);

    top->PCNext_i = 8;
    tick();
    EXPECT_EQ(top->PC_o, 8);
}

// PC should freeze when en_i = 0
TEST_F(TB_NAME, PCFreezesWhenDisabled)
{
    top->PCNext_i = 12;
    top->en_i = 0;

    uint32_t prev = top->PC_o;
    tick();
    EXPECT_EQ(top->PC_o, prev);  // PC_o should not change
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
