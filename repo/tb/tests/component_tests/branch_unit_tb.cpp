/*
 *  Component testbench for branch_unit
 */

#include "base_testbench.h"

#define TB_NAME BranchUnitTestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->funct3_i = 0;
        top->Zero_i = 0;
        top->SrcA_i = 0;
        top->SrcB_i = 0;
        // output: BranchTaken_o
    }
};

// BEQ taken
TEST_F(TB_NAME, BeqTaken)
{
    top->funct3_i = 0b000;
    top->Zero_i = 1;
    top->eval();
    EXPECT_EQ(top->BranchTaken_o, 1);
}

// BNE not equal
TEST_F(TB_NAME, BneTaken)
{
    top->funct3_i = 0b001;
    top->Zero_i = 0;
    top->eval();
    EXPECT_EQ(top->BranchTaken_o, 1);
}

// BLT negative result
TEST_F(TB_NAME, BltTaken)
{
    top->funct3_i = 0b100;
    top->SrcA_i = 0x80000000; // negative
    top->SrcB_i = 0x00000000;
    top->eval();
    EXPECT_EQ(top->BranchTaken_o, 1);
}

// BGE non-negative
TEST_F(TB_NAME, BgeTaken)
{
    top->funct3_i = 0b101;
    top->SrcA_i = 0x00000001;
    top->SrcB_i = 0x00000000;
    top->eval();
    EXPECT_EQ(top->BranchTaken_o, 1);
}

// default path
TEST_F(TB_NAME, DefaultNotTaken)
{
    top->funct3_i = 0b111;
    top->Zero_i = 0;
    top->SrcA_i = 0x00000000;
    top->SrcB_i = 0x00000001;
    top->eval();
    EXPECT_EQ(top->BranchTaken_o, 0);
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

