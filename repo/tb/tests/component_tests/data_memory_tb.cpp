/*
 *  Component testbench for data_memory
 */

#include "base_testbench.h"

#define TB_NAME DataMemoryTestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk_i = 0;
        top->wr_en_i = 0;
        top->funct3_i = 0b010;
        top->addr_i = 0;
        top->data_i = 0;
    }
};

// store/load word round trip
TEST_F(TB_NAME, StoreLoadWord)
{
    top->wr_en_i = 1;
    top->funct3_i = 0b010;
    top->addr_i = 0x00000010;
    top->data_i = 0xDEADBEEF;

    top->clk_i = 0; top->eval();
    top->clk_i = 1; top->eval();

    top->wr_en_i = 0;
    top->funct3_i = 0b010;
    top->eval();
    EXPECT_EQ(top->data_o, 0xDEADBEEF);
}

// store/load byte
TEST_F(TB_NAME, StoreLoadByte)
{
    top->wr_en_i = 1;
    top->funct3_i = 0b000;
    top->addr_i = 0x00000020;
    top->data_i = 0x000000AA;

    top->clk_i = 0; top->eval();
    top->clk_i = 1; top->eval();

    top->wr_en_i = 0;
    top->funct3_i = 0b100; 
    top->eval();
    EXPECT_EQ(top->data_o, 0xAAu);
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

