/*
 *  Component testbench for ALU
 */

#include "base_testbench.h"

#define TB_NAME ALUTestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->SrcA_i = 0;
        top->SrcB_i = 0;
        top->ALUControl_i = 0;
        // outputs: ALUResult_o, Zero_o
    }
};

// ADD
TEST_F(TB_NAME, AddWorksTest)
{
    top->ALUControl_i = 0b0000; // ADD
    top->SrcA_i = 10;
    top->SrcB_i = 20;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 30);
    EXPECT_EQ(top->Zero_o, 0);
}

// SUB
TEST_F(TB_NAME, SubWorksTest)
{
    top->ALUControl_i = 0b0001; // SUB
    top->SrcA_i = 20;
    top->SrcB_i = 5;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 15);
}

// AND
TEST_F(TB_NAME, AndWorksTest)
{
    top->ALUControl_i = 0b0010; // AND
    top->SrcA_i = 0b1100;
    top->SrcB_i = 0b1010;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 0b1000);
}

// OR
TEST_F(TB_NAME, OrWorksTest)
{
    top->ALUControl_i = 0b0011; // OR
    top->SrcA_i = 0b1100;
    top->SrcB_i = 0b0110;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 0b1110);
}

// SLT (a < b)
TEST_F(TB_NAME, SltWorksTest)
{
    top->ALUControl_i = 0b1000; // SLT
    top->SrcA_i = 5;
    top->SrcB_i = 9;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 1);
    EXPECT_EQ(top->Zero_o, 0);
}

// undefined opcode
TEST_F(TB_NAME, DefaultCaseTest)
{
    top->ALUControl_i = 0b1100; // unused -> default
    top->SrcA_i = 1234;
    top->SrcB_i = 5678;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 0);
    EXPECT_EQ(top->Zero_o, 1);
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

