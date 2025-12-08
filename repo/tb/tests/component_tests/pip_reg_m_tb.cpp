/*
 *  Component testbench for pip_reg_m
 */

#include "base_testbench.h"

#define TB_NAME PipRegMTestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk_i = 0;
        top->RegWriteE_i = 0;
        top->ResultSrcE_i = 0;
        top->MemWriteE_i = 0;
        top->funct3E_i = 0;
        top->ALUResultE_i = 0;
        top->WriteDataE_i = 0;
        top->RdE_i = 0;
        top->PCPlus4E_i = 0;
    }
};

TEST_F(TB_NAME, PipelineMTest)
{
    top->RegWriteE_i = 1;
    top->ResultSrcE_i = 0b01;
    top->MemWriteE_i = 1;
    top->funct3E_i = 0x010;
    top->ALUResultE_i = 0xAAAABBBB;
    top->WriteDataE_i = 0xCCCCDDDD;
    top->RdE_i = 0x1A;
    top->PCPlus4E_i = 0x20;

    top->clk_i = 0; top->eval();
    top->clk_i = 1; top->eval();

    EXPECT_EQ(top->RegWriteM_o, 1);
    EXPECT_EQ(top->ResultSrcM_o, 1);
    EXPECT_EQ(top->MemWriteM_o, 1);
    EXPECT_EQ(top->funct3M_o, 0x010);
    EXPECT_EQ(top->ALUResultM_o, 0xAAAABBBB);
    EXPECT_EQ(top->WriteDataM_o, 0xCCCCDDDD);
    EXPECT_EQ(top->RdM_o, 0x1A);
    EXPECT_EQ(top->PCPlus4M_o, 0x20);
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

