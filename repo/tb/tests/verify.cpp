#include <cstdlib>
#include <utility>

#include "cpu_testbench.h"

#define CYCLES 10000

TEST_F(CpuTestbench, TestAddiBne)
{
    setupTest("1_addi_bne");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 254);
}

TEST_F(CpuTestbench, TestLiAdd)
{
    setupTest("2_li_add");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 1000);
}

TEST_F(CpuTestbench, TestLbuSb)
{
    setupTest("3_lbu_sb");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 300);
}

TEST_F(CpuTestbench, TestJalRet)
{
    setupTest("4_jal_ret");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 53);
}

TEST_F(CpuTestbench, TestPdf)
{
    setupTest("5_pdf");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES * 100);
    EXPECT_EQ(top_->a0, 15363);
}

TEST_F(CpuTestbench, BaseProgramTest)
{
    bool success = false;
    setupTest("6_program");
    system("./assemble.sh asm/6_program.s");
    initSimulation();
    for (int i = 0; i < CYCLES; i++)
    {
        runSimulation(1);
        if (top_->a0 == 254)
        {
            SUCCEED();
            success = true;
            break;
        }
    }
    if (!success)
    {
        FAIL() << "Counter did not reach 254";
    }
}

TEST_F(CpuTestbench, TestPipelineProgram)
{
    bool success = false;
    setupTest("7_pipeline_program");
    system("./assemble.sh asm/7_pipeline_program.s");
    initSimulation();
    for (int i = 0; i < CYCLES; i++)
    {
        runSimulation(1);
        if (top_->a0 == 9)
        {
            SUCCEED();
            success = true;
            break;
        }
    }
    if (!success)
    {
        FAIL() << "a0 did not reach 9 a0:" <<  top_->a0;
    }
}


TEST_F(CpuTestbench, Program8CpyReplaceTest)
{
    bool success = false;
    setupTest("8_program_6_cpy_replace");
    system("./assemble.sh asm/8_program_6_cpy_replace.s");
    initSimulation();

    // After one full inner-loop cycle, a0 should equal 100
    const int expectedA0 = 100;

    for (int i = 0; i < CYCLES; i++)
    {
        runSimulation(1);

        if (top_->a0 == expectedA0)
        {
            SUCCEED();
            success = true;
            break;
        }
    }

    if (!success)
    {
        FAIL() << "a0 never reached expected value 100";
    }
}

TEST_F(CpuTestbench, TestITypeALU)
{
    setupTest("9_itype_alu");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 16);
}

TEST_F(CpuTestbench, TestLoadVariants)
{
    setupTest("10_itype_load");
    setData("reference/data_load.mem");
    initSimulation();
    runSimulation(CYCLES * 2);
}


TEST_F(CpuTestbench, TestJALR)
{
    setupTest("11_jalr");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 99);
}

TEST_F(CpuTestbench, TestBranchInstructions)
{
    setupTest("12_branch_test");
    initSimulation();
    runSimulation(2000);
    EXPECT_EQ(top_->a0, 100);
}

TEST_F(CpuTestbench, TestMultiplyInstructions)
{
    setupTest("13_mul");
    initSimulation();
    runSimulation(5000);

    EXPECT_EQ(top_->a0, 42);   // or checksum from your asm
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
