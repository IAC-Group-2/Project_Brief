#include "Vdut.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <csignal>

#define MAX_SIMULATION_CYCLE 1000000

const std::string DISTRIBUTION_TYPE = "noisy"; // select distribution to plot

// ctrl c interrupt cleanup
void cleanup_files(int signum) {
    std::cout << "\nRemoving simulation files" << std::endl;
    std::ignore = system("rm -f program.hex data.hex");
    if (signum != 0) exit(signum);
}

int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    signal(SIGINT, cleanup_files); 

    // create data.hex from the correct reference file
    std::string data_command = "cat ./reference/" + DISTRIBUTION_TYPE + ".mem > data.hex";
    // run assemble script (creates program.hex) and make sure 'assemble.sh' exists and is executable
    if (system("./assemble.sh asm/5_pdf.s") != 0) {
        std::cout << "Assembly failed" << std::endl;
        return -1;
    }

    // make sure data.hex exists, then fill with content
    std::ignore = system("touch data.hex");
    if (system(data_command.c_str()) != 0) {
        std::cout << "Failed to find data.hex" << std::endl;
        return -1;
    }

    Verilated::commandArgs(argc, argv);
    Vdut* top = new Vdut;
    if (vbdOpen()!=1) return(-1);
    vbdHeader(DISTRIBUTION_TYPE.c_str());

    top->clk=0;
    top->rst=0;
    top->trigger=0;

    bool changed = false;
    int original_a0 = top->a0;
    int instr_counter = 0;

    for (i=0; i < MAX_SIMULATION_CYCLE; i++) {
        for (clk = 0; clk < 2; clk++) {
            top->clk = !top->clk;
            top->eval();
        }

        if (!changed && top->a0 != original_a0) {
            changed = true;
        }

        if (changed) {
            // a0 value only changes every 4 instructions, addi and bne don't affect value of a0
            instr_counter++;
            changed = true;
            if (instr_counter % 4 == 0) {
                vbdCycle(instr_counter);
                vbdPlot(top->a0, 0, 255);
            }
        }
        if (Verilated::gotFinish() || vbdGetkey() == 'q') {
            break;
        }
    }
    vbdClose();
    cleanup_files(0);
    exit(0);
}