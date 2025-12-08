/*
 *  Component testbench for sign_extend
 */

#include "base_testbench.h"

#define TB_NAME SignExtendTestbench  

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->imm_src_i   = 0;
        top->imm_instr_i = 0;
    }
};

// I-type sign-extension: imm = instr[31:20]
TEST_F(TB_NAME, ITypeSignExtendPositive)
{
    // imm_instr_i[31:20] = 0x123 (positive)
    top->imm_src_i   = 0;
    top->imm_instr_i = 0x12300000;   // bits 31:20 = 0001 0010 0011

    top->eval();

    int32_t expected = 0x0000123;  // 0x123 sign-extended
    EXPECT_EQ(top->imm_ext_o, expected);
}

// I-type negative immediate (sign bit = 1)
TEST_F(TB_NAME, ITypeSignExtendNegative)
{
    // imm_instr_i[31] = 1 → negative
    // imm_instr_i[31:20] = 0xFFF
    top->imm_src_i   = 0;
    top->imm_instr_i = 0xFFF00000;

    top->eval();

    int32_t expected = (int32_t)0xFFFFFFFF;  // -1 in 32-bit
    EXPECT_EQ((int32_t)top->imm_ext_o, expected);
}

// B-type example: construct a known immediate
TEST_F(TB_NAME, BTypeSignExtendTest)
{
    /*
        Construct a B-type immediate manually
        B-type immediate is assembled as:

        imm[12] = instr[31]
        imm[11] = instr[7]
        imm[10:5] = instr[30:25]
        imm[4:1] = instr[11:8]
        imm[0] = 0

        choose:
            imm[12] = 1
            imm[11] = 0
            imm[10:5] = 0b101010 (0x2A)
            imm[4:1] = 0b1100 (0xC)
            imm[0] = 0
    */

    uint32_t instr = 0;

    // imm[12]
    instr |= (1 << 31);

    // imm[11] already 0

    // imm[10:5]
    instr |= (0b101010 << 25);

    // imm[4:1]
    instr |= (0b1100 << 8);

    top->imm_src_i   = 1; // B-type
    top->imm_instr_i = instr;
    top->eval();

    int32_t expected = (1 << 12) | (0 << 11) | (0b101010 << 5) | (0b1100 << 1) | 0;                     

    // sign-extended (imm[12] = 1)
    expected |= 0xFFFFE000;

    EXPECT_EQ((int32_t)top->imm_ext_o, expected);
}

// default behaviour
TEST_F(TB_NAME, NoChangeWhenInputsZero)
{
    top->imm_src_i   = 0;
    top->imm_instr_i = 0;
    top->eval();

    EXPECT_EQ(top->imm_ext_o, 0u);
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
