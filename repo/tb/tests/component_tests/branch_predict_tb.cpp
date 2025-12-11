/*
 * Component testbench for branch predictor (2 bit saturating counter)
 */

#include "base_testbench.h"

// Ensure we are testing the specific module
#define TB_NAME BranchPredictTestbench

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class TB_NAME : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk_i = 0;
        top->rst_i = 1; // Start in reset
        top->PCF_i = 0;
        top->PCE_i = 0;
        top->BranchE_i = 0;
        top->TakenE_i = 0;
        top->PCTargetE_i = 0;
    }

    // Helper: Toggles clock to generate a posedge
    void tick()
    {
        top->clk_i = 0;
        top->eval();
        top->clk_i = 1;
        top->eval();
        ticks++;
    }

    // Helper: Simulates one Execute Stage update cycle
    void clock_update(uint32_t pc, bool taken) {
        // 1. Setup Execute Stage Signals
        top->PCE_i = pc;
        top->BranchE_i = 1;      // Valid Branch
        top->TakenE_i = taken;   // Outcome
        top->PCTargetE_i = 0x80; // Dummy target

        // 2. Clock it in (Update happens on posedge)
        tick();

        // 3. Clear Control Signals for next cycle
        top->BranchE_i = 0; 
    }
};

// Test 1: Reset Behaviour
// Expectation: Reset initializes table to 01 (Weakly Not Taken) -> Predicts 0
TEST_F(TB_NAME, ResetStateTest)
{
    // Apply Reset
    top->rst_i = 1;
    tick(); // Clock edge needed for sync reset!
    
    // Release Reset
    top->rst_i = 0;

    // Check Prediction at PC 0x10
    top->PCF_i = 0x10;
    top->eval(); // Combinational read
    EXPECT_EQ(top->predictTakenF_o, 0);
}

// Test 2: Training (01 -> 10)
// Expectation: Taking a branch once promotes Weakly Not Taken -> Weakly Taken
TEST_F(TB_NAME, TrainTakenTest)
{
    // Reset
    top->rst_i = 1; tick(); top->rst_i = 0;

    // Verify initial state (0)
    top->PCF_i = 0x20; top->eval();
    EXPECT_EQ(top->predictTakenF_o, 0);

    // Update: Branch Taken
    // Transition: 01 (WNT) -> 10 (WT)
    clock_update(0x20, true); 

    // Verify New State (1)
    top->PCF_i = 0x20; top->eval();
    EXPECT_EQ(top->predictTakenF_o, 1);
}

// Test 3: Saturation (00 -> 11)
// Expectation: Repeatedly taking branch saturates counter at 11
TEST_F(TB_NAME, SaturationTest)
{
    top->rst_i = 1; tick(); top->rst_i = 0;

    // We assume worst case start: 00 (Strongly Not Taken)
    
    // 00 -> 01 (WNT)
    clock_update(0x30, true);
    
    // 01 -> 10 (WT)
    clock_update(0x30, true);
    
    // 10 -> 11 (ST)
    clock_update(0x30, true);

    // Check Prediction
    top->PCF_i = 0x30; top->eval();
    EXPECT_EQ(top->predictTakenF_o, 1);

    // Update again: 11 -> 11 (Should Stay Saturated)
    clock_update(0x30, true);
    top->eval();
    EXPECT_EQ(top->predictTakenF_o, 1);
}

// Test 4: Hysteresis (11 -> 10 -> 01)
// Expectation: One miss does not flip prediction immediately
TEST_F(TB_NAME, HysteresisTest)
{
    top->rst_i = 1; tick(); top->rst_i = 0;

    // Train to Strongly Taken (11)
    clock_update(0x40, true);
    clock_update(0x40, true);
    clock_update(0x40, true);

    // Verify Strong State
    top->PCF_i = 0x40; top->eval();
    EXPECT_EQ(top->predictTakenF_o, 1);

    // Update: NOT TAKEN (Anomaly)
    // Transition: 11 (ST) -> 10 (WT)
    clock_update(0x40, false);

    // Verify: Should STILL predict Taken (because state is 10)
    top->eval();
    EXPECT_EQ(top->predictTakenF_o, 1);

    // Update: NOT TAKEN Again
    // Transition: 10 (WT) -> 01 (WNT)
    clock_update(0x40, false);

    // Verify: Now predicts Not Taken
    top->eval();
    EXPECT_EQ(top->predictTakenF_o, 0);
}

int main(int argc, char **argv)
{
    top = new Vdut; 
    tfp = new VerilatedVcdC;

    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("branch_predict.vcd");

    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    top->final();
    tfp->close();

    delete top;
    delete tfp;

    return res;
}