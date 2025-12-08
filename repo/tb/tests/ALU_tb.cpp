/*
 *  TEST BENCH COPY CODE 
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
    top->ALUControl_i = 0b0000;   
    top->SrcA_i = 10;
    top->SrcB_i = 20;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 30);
    EXPECT_EQ(top->Zero_o, 0);
}

// SUB
TEST_F(TB_NAME, SubWorksTest)
{
    top->ALUControl_i = 0b0001;   
    top->SrcA_i = 20;
    top->SrcB_i = 5;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 15);
    EXPECT_EQ(top->Zero_o, 0);
}

// AND
TEST_F(TB_NAME, AndWorksTest)
{
    top->ALUControl_i = 0b0010;   
    top->SrcA_i = 0b1100;
    top->SrcB_i = 0b1010;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 0b1000);
}

// OR
TEST_F(TB_NAME, OrWorksTest)
{
    top->ALUControl_i = 0b0011;   
    top->SrcA_i = 0b1100;
    top->SrcB_i = 0b0110;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 0b1110);
}

// SLL
TEST_F(TB_NAME, SllWorksTest)
{
    top->ALUControl_i = 0b0101;   
    top->SrcA_i = 1;
    top->SrcB_i = 4;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 16);
}

// SRL
TEST_F(TB_NAME, SrlWorksTest)
{
    top->ALUControl_i = 0b0110;
    top->SrcA_i = 0xF0000000;
    top->SrcB_i = 4;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 0x0F000000);
}

// SRA
TEST_F(TB_NAME, SraWorksTest)
{
    top->ALUControl_i = 0b0111;
    top->SrcA_i = 0xF0000000;
    top->SrcB_i = 4;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 0xFF000000);
}

// SLT (1000)
TEST_F(TB_NAME, SltWorksTest)
{
    top->ALUControl_i = 0b1000;   
    top->SrcA_i = 5;
    top->SrcB_i = 9;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 1);
    EXPECT_EQ(top->Zero_o, 0);
}

// SLTU
TEST_F(TB_NAME, SltuWorksTest)
{
    top->ALUControl_i = 0b1001;   
    top->SrcA_i = 1;
    top->SrcB_i = -1; 

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 1);
}

// LUI Pass-Through (1111)
TEST_F(TB_NAME, LuiWorksTest)
{
    top->ALUControl_i = 0b1111;   
    top->SrcA_i = 0x12345678; // Should be ignored
    top->SrcB_i = 0xABCDEF00; // Should be passed

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 0xABCDEF00);
}

// undefined opcode
TEST_F(TB_NAME, DefaultCaseTest)
{
    top->ALUControl_i = 0b111;   
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
