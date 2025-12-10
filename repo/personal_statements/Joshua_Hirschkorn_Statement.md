# **RISC-V RV32I Processor Coursework**

#### *Joshua Hirschkorn | CID: 02378306 | GitHub: vortexisalpha

# Personal Statement

  

## Overview of Contributions

  

### [**Pipelined Processor**](#pipelined-processor-1)

- Pipeline Registers

    - Fetch-Decode Pipeline Register (`pip_reg_d.sv`)

    - Decode-Execute Pipeline Register (`pip_reg_e.sv`)

    - Execute-Memory Pipeline Register (`pip_reg_m.sv`)

    - Memory-Writeback Pipeline Register (`pip_reg_w.sv`)

    - Flush and stall logic implementation

- Hazard Unit

    - Data forwarding logic

    - Load word stalling

    - Control hazard flushing

- Top level Integration

    - Refactoring and naming conventions for pipeline stages

    - Module interconnection and signal routing

  

### [**Cache Implementation**](#cache-implementation-1)

- Cache Design

    - 2-way set associative cache architecture design (Co-authored with Yichan)

    - State machine for cache miss handling (IDLE $\rightarrow$ WRITEBACK $\rightarrow$ FETCH $\rightarrow$ UPDATE)

- Cache Stalling Integration

    - Modified hazard unit for cache miss stalling

    - Updated all pipeline registers to support cache stall signals

- Funct3 Byte Offset Logic

    - Implemented byte/word operation handling in cache

    - Byte offset extraction for LBU/SB instructions

  

### [**Testing & Verification**](#testing-verification-1)

- Component Test Benches

    - Created testbenches for pipeline and cache components

- Integration Testing

    - Full system verification with provided test programs

  

### [**Project Management**](#project-management-1)

- Version Control

    - Merge conflict resolution

    - Release tagging for milestone versions

- Team Coordination

    - Task allocation and versioning principles

  

## Pipelined Processor

### Overview

To start we made this diagram and took inspiration from the textbook: : Digital Design and Computer Architecture (RISC-V Edition) by Sarah Harris and David Harris.

In blue below is each component that we added to the single cycle CPU for pipelining purposes.

![pipeline_diagram](./personal_statement_assets/pipeline_diagram.png)

[See full image here](https://ibb.co/7tk689jL)
### Pipeline Registers  

The transition from single cycle (mostly done in Lab4) to pipelined architecture required the addition of pipeline registers between each stage to separate instructions and allow multiple instructions to be processed simultaneously. I implemented 2 of the 5 pipeline registers with clear naming conventions following the standard pipeline stage suffixes (F, D, E, M, W) and i and o for labelling logic as input/output logic. Discussing and preparing these naming conventions and the diagram was a key part of the success of our development because when it came to linking everything up in the top.sv file the filesystem was much easier to navigate.

#### Execute-Memory Pipeline Register (`pip_reg_m.sv`)

Commits:
1. [Create Pip_reg_m logic](https://github.com/IAC-Group-2/Project_Brief/commit/19dae8ffcb1ffbe384e245f408a015a291f42cde)
2. [Bugfixes](https://github.com/IAC-Group-2/Project_Brief/commit/1dda7adaea5d9082cc44c41c22263f1247d2a83f)

The first pipeline register separates the execute and memory stages passing through some ALU, Control Unit, PC+4 and Extend logic some of which was taken directly from the Execute stage register:


```verilog

module pip_reg_m #( //Execute to memory stage

    PC_WIDTH = 32,

    INSTRUCTION_WIDTH = 32,

    REGISTER_ADDRESS_WIDTH = 5

)(

    input   logic                           clk_i,

    input   logic                           en_i,

  

    input   logic                           RegWriteE_i, //Execute

    output  logic                           RegWriteM_o, //Memory

    input   logic[1:0]                      ResultSrcE_i, //Execute

    output  logic[1:0]                      ResultSrcM_o, //Memory

  

    input   logic                           MemWriteE_i, //Execute

    output  logic                           MemWriteM_o, //Memory

  

    input   logic [2:0]                     funct3E_i, // Execute

    output  logic [2:0]                     funct3M_o, // Memory

  

    input   logic [INSTRUCTION_WIDTH-1:0]   ALUResultE_i, //Execute

    output  logic [INSTRUCTION_WIDTH-1:0]   ALUResultM_o, //Memory

  

    input   logic [INSTRUCTION_WIDTH-1:0]   WriteDataE_i, //Execute

    output  logic [INSTRUCTION_WIDTH-1:0]   WriteDataM_o, //Memory

    input   logic [REGISTER_ADDRESS_WIDTH-1:0]  RdE_i, //Execute

    output  logic [REGISTER_ADDRESS_WIDTH-1:0]  RdM_o, //Memory

    input   logic [PC_WIDTH-1:0]            PCPlus4E_i, //Execute

    output  logic [PC_WIDTH-1:0]            PCPlus4M_o //Memory

);

  

always_ff @(posedge clk_i) begin

    if (en_i) begin

        RegWriteM_o     <= RegWriteE_i;    

        ResultSrcM_o    <= ResultSrcE_i;    

        MemWriteM_o     <= MemWriteE_i;

        funct3M_o       <= funct3E_i;    

        ALUResultM_o    <= ALUResultE_i;    

        WriteDataM_o    <= WriteDataE_i;    

        RdM_o           <= RdE_i;

        PCPlus4M_o      <= PCPlus4E_i;

    end

  

end

endmodule

```


Key design choices in this register:

- **Clear (`clr_i`)**: Implements flush functionality for control hazards. When a branch is taken, the incorrect instruction in the decode stage must be flushed.

- **Enable (`en_i`)**: Implements stall functionality. When disabled, the register "freezes" and maintains its current values.

- **Positive edge triggering**: All pipeline registers operate on `posedge clk` for synchronous operation.

#### Decode-Execute Pipeline Register (`pip_reg_e.sv`)

Commits:

1. [Pip_reg_e inputs and outputs](https://github.com/IAC-Group-2/Project_Brief/commit/98a2255c7b9087bf6f090a174b38698708106fdd)
2. [Finished pip_reg_e](https://github.com/IAC-Group-2/Project_Brief/commit/bddcf08ff7b07e48f8bffce31953b735fa7e0b18)
3. [Adding extra read signals](https://github.com/IAC-Group-2/Project_Brief/commit/9516af7cd4802e1755be34f28b7347329679b99d)
4. [Bugfixes](https://github.com/IAC-Group-2/Project_Brief/commit/720117e1b7f1f30cc8e490294635a5153fe106da)

The largest pipeline register, carrying all control signals and data from decode to execute:


```verilog
//declared all the logic with input and output prefixes as you see below up here...

always_ff @(posedge clk_i) begin

    if (clr_i) begin //flush logic

        RegWriteE_o     <= 'b0;

        ResultSrcE_o    <= 'b0;

        MemWriteE_o     <= 'b0;

        JumpE_o         <= 'b0;

        BranchE_o       <= 'b0;

        ALUControlE_o   <= 'b0;

        ALUSrcE_o       <= 'b0;

        funct3E_o       <= 'b0;

        RD1E_o          <= 'b0;

        RD2E_o          <= 'b0;

        PCE_o           <= 'b0;

        Rs1E_o          <= 'b0;

        Rs2E_o          <= 'b0;

        RdE_o           <= 'b0;

        ImmExtE_o       <= 'b0;

        PCPlus4E_o      <= 'b0;

    end

    else if (en_i) begin  // Normal operation: pass data through

        RegWriteE_o     <= RegWriteD_i;

        ResultSrcE_o    <= ResultSrcD_i;

        // ...remaining signals passed through

    end

end

```

  
A critical design decision was passing `funct3` through the pipeline register. This is necessary because:

1. **Branch resolution**: The branch unit in the execute stage needs `funct3` to determine the branch type (BEQ, BNE, BLT, BGE).

2. **Memory operations**: The memory stage needs `funct3` to distinguish between byte and word load/store operations.

This was a factor that we overlooked and it came to stab us in the back when implementing cache. We ended up having to add this input/output whilst implementing the cache due to the byte operations. More on this later...

### Hazard Unit

commits:
1. [Inputs and outputs](https://github.com/IAC-Group-2/Project_Brief/commit/9c41cf618f6efe82ae965efb0adff5d4c2c10fbe)
2. [Implemented hazard unit logic over video call (should say co authored but doesn't)](https://github.com/IAC-Group-2/Project_Brief/commit/ec11d6203acb80434e8b76b2aa0688220696f0b6)
3. [Updated to take in Resultsrc0 and bug fixes](https://github.com/IAC-Group-2/Project_Brief/commit/4904dff0fe6f591be21338bf04f0953b4f14f477)
4. [Fixing outputs from control unit](https://github.com/IAC-Group-2/Project_Brief/commit/6b2f32bf66120548aeb677744c074cabbb05ceed)
5. [Fixing outputs from ALU](https://github.com/IAC-Group-2/Project_Brief/commit/1d5736b2c884c582da339a3b78e2b68dfd1c2bba)

The hazard unit was one of my contributions, implementing data forwarding, stalling, and flushing logic. I co-authored this with Yichan over video call, carefully designing the logic to handle all hazard scenarios.

Planning on video call diagram:

![](./personal_statement_assets/Pasted%20image%2020251209214840.png)

We used the Digital Design and Computer Architecture text book as a guide to the top level units and base naming conventions for this stage. We also spoke about how we were going to deal with all the stalls and flushing logic.
#### Data Forwarding Logic

The core forwarding logic detects Read After Write (RAW) hazards and forwards data from later pipeline stages.

An example of a data hazard is:


```
Cycle n:
  instr1: ADD x5, x1, x2   // produces x5
Cycle n+1:
  instr2: SUB x6, x5, x3   // needs x5
```

The way we use forward logic is dependant on signals `ForwardAE` and `ForwardBE` outputted from the hazard unit. We can control the input to the ALU with MUXs to give us signals from later stages `ALUResultM` or `ResultW`:

![](./personal_statement_assets/Pasted%20image%2020251209224754.png)

The following logic will detect if a register in the previous cycle needs a value that is already calculated in a further stage, we then "forward" the signal such that the stage executing the command is aware of this update:

```verilog

always_comb begin

    // Forward A (Rs1)

    if (((Rs1E_i == RdM_i) && RegWriteM_i) && (Rs1E_i != '0)) begin

        ForwardAE_o = 2'b10;  // Forward from Memory Stage

    end

    else if (((Rs1E_i == RdW_i) && RegWriteW_i) && (Rs1E_i != '0)) begin

        ForwardAE_o = 2'b01;  // Forward from Writeback stage

    end

    else begin

        ForwardAE_o = 2'b00;  // No forwarding

    end

  

    // Forward B (Rs2) similar logic

    if (((Rs2E_i == RdM_i) && RegWriteM_i) && (Rs2E_i != '0)) begin

        ForwardBE_o = 2'b10;

    end

    else if (((Rs2E_i == RdW_i) && RegWriteW_i) && (Rs2E_i != '0)) begin

        ForwardBE_o = 2'b01;

    end

    else begin

        ForwardBE_o = 2'b00;

    end

```


Key considerations:

- **Register x0 check**: The condition `Rs1E_i != '0` ensures we don't forward when reading from x0 (which is always zero).

- **Priority**: Memory stage forwarding takes priority over writeback stage (checked first) because it has more recent data.

- **RegWrite check**: Only forward if the source stage will actually write to the register.

#### Load-Word Stall Detection 

Load instructions create a special hazard because the data isn't available until after the memory stage. 

An example of this behaviour would be:

```
I1: lw x5, 0(x1)
I2: add x6, x5, x2 // we need x5 here
```

This requires stalling in the hazard unit to detect if we need a stall based on `ResultSrcE0` and weather we are using the same register as being written to memory.

![](./personal_statement_assets/Pasted%20image%2020251209225057.png)

Note that `ResultSRC0` is the first bit of `ResultSRC` which controls weather we are reading or writing to the register file. We need this to detect load and write instructions with the following logic:

```verilog

lwStall = ResultSrcE0_i && ((Rs1D_i == RdE_i) || (Rs2D_i == RdE_i));

```

When `ResultSrcE0` is high, it indicates a load instruction in the execute stage. If either source register in the decode stage matches the load's destination, we must stall.

#### Cache Stall Integration

A significant modification I made was integrating cache miss handling into the hazard unit with Yichan.

In our design, cache miss handling is integrated directly into the hazard unit rather than treated as a separate control path. This is because a cache miss behaves like a global hazard: it affects not just one instruction, but the correctness of the entire pipeline.

When a cache miss occurs, the cache asserts `CacheStall_i`, which freezes all pipeline stages:

- The **Fetch and Decode stages** are stalled to prevent the PC from advancing and new instructions from entering the pipeline.

- The **Execute, Memory, and Writeback stages** are also frozen so that instructions that are trying to use memory do not partially execute or commit results while waiting for memory.

```verilog

// Stall logic:

// stall on regular stall or cache stall

StallF_o = lwStall || CacheStall_i;

StallD_o = lwStall || CacheStall_i;

// freeze on cache stall only

StallE_o = CacheStall_i;  

StallM_o = CacheStall_i;  

StallW_o = CacheStall_i;  

  

// Flush logic

if (!CacheStall_i) begin // don't flush on cache stall

    FlushD_o = PCSrcE_i;

    FlushE_o = (lwStall || PCSrcE_i);

end

else begin

    FlushD_o = 'b0;

    FlushE_o = 'b0;

end

```

The `CacheStall_i` is given by the cache memory directly into the hazard unit. The cache has a logic called `CacheMiss_o` which will be set to 1 if it has a cache miss. This becomes `CacheStall_i` in the hazard unit.

Key design ideas:

- **Cache stall freezes everything**: When the cache misses, all stages must freeze to keep the pipeline functional.

- **No flush during cache stall**: We must not flush valid instructions while waiting for cache.

- **Independent stall signals**: Each stage gets its own stall signal, allowing more control over what stages need to be stalled in what scenarios.

### Top-Level Integration

Each person was responsible for integrating all their own modules into `top.sv` and establishing consistent naming conventions. The signal naming follows the pattern `SignalName` + `Stage` (e.g. `RegWriteD`, `RegWriteE`, `RegWriteM`, `RegWriteW`), making it easy to trace signals through the pipeline. For the parts I designed with Yichan, we did it together and the parts I did individually I did alone.

Commits:
1. [Name changing from Lab 4 for good programming practice](https://github.com/IAC-Group-2/Project_Brief/commit/6b5f5f9c1c8a94c92d54c2e445dcab0c24e4eeed)
2. [Editing sign extend for good variable names](https://github.com/IAC-Group-2/Project_Brief/commit/b1ce0aab12490d46f7875915647b01732e71a663)
3. [Editing control unit for good variable names](https://github.com/IAC-Group-2/Project_Brief/commit/8507b13ce8879a42c33d22784f433a49ddada3f8)
4. [Adding RD outputs for pipelining](https://github.com/IAC-Group-2/Project_Brief/commit/9516af7cd4802e1755be34f28b7347329679b99d)
5. [Finalised pipeline level top.sv with comments on needed components](https://github.com/IAC-Group-2/Project_Brief/commit/8dacf4162a2540413f5d7b8a625ad324ac0ce4f3)
6. +lots more bug fixes and testing logic
  
#### Pipeline Stage Signal Flow


```verilog

// Control signals carried across pipeline stages

logic                           RegWriteD;

logic                           RegWriteE;

logic                           RegWriteM;

logic                           RegWriteW;

logic [1:0]                     ResultSrcD;

logic [1:0]                     ResultSrcE;

logic [1:0]                     ResultSrcM;

logic [1:0]                     ResultSrcW;

```

#### Forwarding Multiplexer Integration

The forwarding multiplexers use the hazard unit outputs to select the correct data source:

```verilog

// Execute stage

mux3 ForwardMuxA (

    .in0_i(RD1E),

    .in1_i(ResultW),

    .in2_i(ALUResultM),

    .sel_i(ForwardAE),

    .out_o(SrcAE)

);

  

mux3 ForwardMuxB (

    .in0_i(RD2E),

    .in1_i(ResultW),

    .in2_i(ALUResultM),

    .sel_i(ForwardBE),

    .out_o(WriteDataE)

);

```


## Cache Implementation

### Cache Design

Commits:
1. [Implemented foundation](https://github.com/IAC-Group-2/Project_Brief/commit/1c3814169b7821c2c43910d29bca54ec97e2e802)
2. [Cache hit/miss and stall logic](https://github.com/IAC-Group-2/Project_Brief/commit/f99109ae9b3483744283b375d64afa09d1d1fbde)
3. [Finite state machine implementation](https://github.com/IAC-Group-2/Project_Brief/commit/f68281c6742a50c3a7f018799b260cfa654498b1)



Working with Yichan, we designed and implemented a 2-way set associative write back cache with 4096 bytes capacity and a least recently used value. We first created a diagram during our December 2nd meeting, then implemented it in live video calls.

Here are a few sketches from our video calls:

![](./personal_statement_assets/Pasted%20image%2020251209191802.png)

![](./personal_statement_assets/Pasted%20image%2020251209191830.png)

We iterated our initial design quite a few times and came up with this finalised diagram for our cache memory:

![](./personal_statement_assets/Pasted%20image%2020251209231525.png)

#### Cache Structure

We decided to alter the design of the provided example in the lectures as we thought that we wanted more capacity which meant that we needed a larger set bits allocation to allow for the width of the cache to increase.


```

Set Format:

| LRU Bit (1) | Way0 (56 bits) | Way1 (56 bits) |

  

Way Format:

| Valid (1) | Dirty (1) | Tag (22 bits) | Data (32 bits) |

  

Parameters:

- Total capacity: 2048 bytes of actual data

- Number of sets: 256 (2^8)

- Ways per set: 2

- Tag bits: 22

- Set index bits: 8

- Byte offset bits: 2

```

#### State Machine Design

The cache uses a finite state machine to handle cache misses. This is the structure I decided on implementing for the cache miss:

![](./personal_statement_assets/Pasted%20image%2020251210183600.png)

The state transitions are:

1. **IDLE -> WRITEBACK**: On miss, if the LRU way is dirty, write it back to memory first.

2. **IDLE -> FETCH**: On miss, if the LRU way is clean, skip directly to fetching.

3. **WRITEBACK -> FETCH**: After writeback, fetch the new data.

4. **FETCH -> UPDATE**: After fetching, update the cache with new data.

5. **UPDATE -> IDLE**: Return to idle, ready for next access.

  This structure makes sense because each state corresponds to a distinct stall condition: the cache does not stall on hits in IDLE, stalls during WRITEBACK to prevent the processor from accessing a line being evicted, stalls during FETCH while waiting for memory to return a new line, and only releases the stall once the cache line has been fully updated and marked valid, ensuring the CPU never observes a partially updated cache state.


```verilog

typedef enum {IDLE, WRITEBACK, FETCH, UPDATE} my_state;

  

always_comb begin

    next_state = current_state;

    case (current_state)

        IDLE: begin

            if (cache_miss) begin

                if (target_dirty)

                    next_state = WRITEBACK;

                else

                    next_state = FETCH;

            end

        end

        WRITEBACK: next_state = FETCH;

        FETCH:     next_state = UPDATE;

        UPDATE:    next_state = IDLE;

    endcase

end

```

### Funct3 Byte Offset Logic

Commits:
1. [Changing all pipeline registers to pass in funct3](https://github.com/IAC-Group-2/Project_Brief/commit/92ab66b01cc30fb4e1767286990e8a657df98702)
2. [Changed hazard unit to take in cache stall and removed unnecessary pipeline logic](https://github.com/IAC-Group-2/Project_Brief/commit/8cb9922fe9db95b04b0bb51063a78b41ab97f896)
3. [Edited top.sv to allow these changes](https://github.com/IAC-Group-2/Project_Brief/commit/ef0e6997f6bcb0ea2af41dc4fa17f2f7d8261211)
4. [Fixing state machine logic for funct3 enabling on writeback state](https://github.com/IAC-Group-2/Project_Brief/commit/b36de610f9add0eb8a00b4b6e9193eb7245bb953)
5. [Add Update state logic](https://github.com/IAC-Group-2/Project_Brief/commit/0329dbddd1f92bf8d369686493ef0be024acd5b0)
6. [Bug fix, funct3_o needs to be set on update state too](https://github.com/IAC-Group-2/Project_Brief/commit/b2451317c464fa61c01d36547a86483c28bf676d)

One of my key contributions was implementing the `funct3` logic to handle byte operations correctly. This was particularly challenging because the cache operates on word aligned addresses, but byte operations (`LBU`, `SB`) need to access specific bytes within a word.

#### The Problem

Initially, our cache would fail on tests like [`3_lbu_sb.s`](https://github.com/IAC-Group-2/Project_Brief/blob/main/repo/tb/asm/3_lbu_sb.s) because:

- The cache always reads/writes full 32 bit words

- Byte operations need to extract or modify specific bytes based on the address

- The byte offset (bits [1:0] of the address) determines which byte to access

#### The Solution

I implemented byte offset extraction in the cache module:


```verilog

// Byte offset from address for byte operations

logic [1:0] byte_offset;

assign byte_offset = addr_i[1:0];

  

// Check if it's a word operation with funct3

logic is_word_op;

assign is_word_op = (funct3_i == 3'b010);

```

  
For read operations, the byte offset selects the correct byte from the cached word:


```verilog

if (is_word_op) begin

    data_o = raw_cache_data;

end

else begin

    if (byte_offset == 2'b00)

        data_o = {24'b0, raw_cache_data[7:0]};

    else if (byte_offset == 2'b01)

        data_o = {24'b0, raw_cache_data[15:8]};

    else if (byte_offset == 2'b10)

        data_o = {24'b0, raw_cache_data[23:16]};

    else

        data_o = {24'b0, raw_cache_data[31:24]};

end

```


For write operations, only the specific byte is modified while preserving the rest:


```verilog

// On cache hit with byte write

if (byte_offset == 2'b00)

    cache_array[set_addr][7:0] <= data_i[7:0];

else if (byte_offset == 2'b01)

    cache_array[set_addr][15:8] <= data_i[7:0];

else if (byte_offset == 2'b10)

    cache_array[set_addr][23:16] <= data_i[7:0];

else

    cache_array[set_addr][31:24] <= data_i[7:0];

```

#### Funct3 Passthrough

An important detail was ensuring `funct3` is passed through the cache to memory for operations that miss:

![](./personal_statement_assets/Pasted%20image%2020251210183251.png)

![](./personal_statement_assets/Pasted%20image%2020251210183416.png)


The following logic updates funct3_o to the memory based on which state it is. If we are in IDLE state we need it to pass through. All the other ones we can set it to the previous default value of 0b010:

```verilog

// Pass funct3 to memory and force word access on fill/writeback/update

assign funct3_o = (current_state == FETCH ||

                   current_state == WRITEBACK ||

                   current_state == UPDATE) ? 3'b010 : funct3_i;

```

During cache fill operations, we always access memory as words (32 bits), but for direct cache access, we pass through the original `funct3` to enable byte operations.

### Cache-Pipeline Integration

Integrating the cache with the pipeline required modifications to the hazard unit and all pipeline registers:
  
```verilog

// In top.sv

cache cache(

    .clk_i(clk),

    .rst_i(rst),

    .MemWriteM_i(MemWriteM),

    .ResultSrcM_i(ResultSrcM),

    .funct3_i(funct3M),

    .addr_i(ALUResultM),

    .data_i(WriteDataM),

    .mem_rd_data_i(MemRdData),

    .mem_addr_o(CacheMemAddr),

    .mem_wr_en_o(CacheMemWrEn),

    .mem_wr_data_o(CacheMemWrData),

    .funct3_o(CacheFunct3), // Note this line

    .data_o(ReadDataM),

    .cache_miss_o(CacheMiss),

    .stall_o(CacheStall)

);

```

  
The stall signal propagates through the hazard unit to freeze all pipeline stages during a cache miss. We discussed this above.

## Testing & Verification
1. [Create runtests.sh](https://github.com/IAC-Group-2/Project_Brief/commit/420d425a5870c7e00be8c17defe104e4fbcb71f3)
2. [Bugfix runtests.sh](https://github.com/IAC-Group-2/Project_Brief/commit/3a22dd0eeac52beccdd2c7461d02372ae3187efb)
  
As mentioned in my project log, I created testbenches for half of the components in our project, splitting the workload with Yichan. This section details the comprehensive component testing framework I developed.
### Component Testbench Framework

I created a modular testing framework in `tb/tests/component_tests/` that allows isolated testing of individual RTL modules using Google Test and Verilator. The framework includes:
#### Base Testbench Class (`base_testbench.h`)

This was provided and designed for us by Peter. (Thanks Peter).
  
#### Test Runner Script (`runtests.sh`)
  
I wrote a shell script to automate running all component tests, this is similar to the one provided by Peter for the main testing framework that runs verify.cpp but this one works such that it runs the component test benches in the `tb/tests/component_tests/` folder:


```bash

#!/bin/bash
#run all component testbenches under component_tests/

SCRIPT_DIR=$(dirname "$(realpath "$0")")

RTL_FOLDER=$(realpath "$SCRIPT_DIR/../../../rtl")

OUT_FOLDER="$SCRIPT_DIR/../test_out/component_tests"

  

passes=0

fails=0

  

mkdir -p "$OUT_FOLDER"

  

for file in "${TEST_FOLDER}"/*_tb.cpp; do

    name=$(basename "$file" _tb.cpp)

  

    verilator -Wall -trace \

        -cc "${RTL_FOLDER}/${name}.sv" \

        -exe "${file}" \

        -y "${RTL_FOLDER}" \

        -prefix "Vdut" \

        -o Vdut \

        -LDFLAGS "-lgtest -lgtest_main -lpthread"

  

    make -j -C obj_dir/ -f Vdut.mk

    ./obj_dir/Vdut

  

    if [ $? -eq 0 ]; then

        ((passes++))

        echo "${GREEN}PASS${RESET} ${name}"

    else

        ((fails++))

        echo "${RED}FAIL${RESET} ${name}"

    fi

  

    # Stash build output per test

    mv obj_dir "${OUT_FOLDER}/${name}_obj_dir"

done

```


The script:

- Automatically discovers all `*_tb.cpp` files

- Compiles each component with its corresponding RTL module

- Reports pass/fail status with coloured output

- Preserves build artefacts for debugging

### Individual Component Testbenches

Commits:
1. [ALU test bench](https://github.com/IAC-Group-2/Project_Brief/commit/ee139ee42cba8442b9a21877d59e4441fed5a42a)
2. [Branch unit test bench](https://github.com/IAC-Group-2/Project_Brief/commit/83dfb5a10c38cbf132027152e10d48a4fc226a02)
3. [Control unit test bench](https://github.com/IAC-Group-2/Project_Brief/commit/ca050b79af7e2b528673c36435a57e605f6c4869)
4. [Bugfix control unit test bench](https://github.com/IAC-Group-2/Project_Brief/commit/b0c65cf1b8c9a9dd921fef9d5f3557a5f9794a1d)
5. [Data Memory test bench](https://github.com/IAC-Group-2/Project_Brief/commit/70d52b6418f2d8f142acfd9a493cbad89ce3c011)
6. [Hazard unit test bench](https://github.com/IAC-Group-2/Project_Brief/commit/ef9a1d96b8b08a5f257e73519f1a72428d62494a)
7. [Instruction memory test bench](https://github.com/IAC-Group-2/Project_Brief/commit/eed01ac8f6e77da9e8a3de5a4970f8df6dba79f5)
8. [Mux reg test bench](https://github.com/IAC-Group-2/Project_Brief/commit/4608020e19b2c75cdb112019389e938e4193f7ab)
9. [Cache test bench](https://github.com/IAC-Group-2/Project_Brief/commit/ac1aa166744916d2823846e828435205f3b1bacc)
10. [Changed pipeline register test benches for new cache](https://github.com/IAC-Group-2/Project_Brief/commit/e011c75a590c770076962beb86ed496cbd3e4b88)

#### Hazard Unit Testbench (`hazard_unit_tb.cpp`)

The hazard unit is critical for correct pipeline operation, so I created comprehensive tests covering all hazard scenarios:

  

```cpp

class HazardUnitTestbench : public BaseTestbench

{

protected:

    void initializeInputs() override

    {

        top->Rs1D_i = 0;

        top->Rs2D_i = 0;

        top->Rs1E_i = 0;

        top->Rs2E_i = 0;

        top->RdE_i = 0;

        top->ResultSrcE0_i = 0;

        top->RdM_i = 0;

        top->RegWriteM_i = 0;

        top->RdW_i = 0;

        top->RegWriteW_i = 0;

        top->PCSrcE_i = 0;

    }

};

  

// Test forwarding from Memory stage

TEST_F(HazardUnitTestbench, ForwardFromMemory)

{

    top->Rs1E_i = 5;      // Source register 1 in Execute = x5

    top->RdM_i = 5;       // Destination in Memory = x5

    top->RegWriteM_i = 1; // Memory stage will write

    top->eval();

    EXPECT_EQ(top->ForwardAE_o, 2); // Should forward from Memory (2'b10)

}

  

// Test forwarding from Writeback stage

TEST_F(HazardUnitTestbench, ForwardFromWriteback)

{

    top->Rs2E_i = 3;      // Source register 2 in Execute = x3

    top->RdW_i = 3;       // Destination in Writeback = x3

    top->RegWriteW_i = 1; // Writeback stage will write

    top->eval();

    EXPECT_EQ(top->ForwardBE_o, 1); // Should forward from Writeback (2'b01)

}

  

// Test load-use hazard detection

TEST_F(HazardUnitTestbench, LoadUseStall)

{

    top->ResultSrcE0_i = 1; // Load instruction in Execute

    top->RdE_i = 8;         // Loading into x8

    top->Rs1D_i = 8;        // Decode needs x8

    top->eval();

    EXPECT_EQ(top->StallD_o, 1); // Should stall Decode

    EXPECT_EQ(top->StallF_o, 1); // Should stall Fetch

}

  

// Test that load-use stall also flushes Execute

TEST_F(HazardUnitTestbench, LoadUseStallFlushesExecute)

{

    top->ResultSrcE0_i = 1;

    top->RdE_i = 4;

    top->Rs1D_i = 4;

    top->PCSrcE_i = 0;

    top->eval();

    EXPECT_EQ(top->StallD_o, 1);

    EXPECT_EQ(top->StallF_o, 1);

    EXPECT_EQ(top->FlushE_o, 1); // Must flush to insert bubble

}

```

  

These tests verify:

- **ForwardFromMemory**: Detects RAW hazard and forwards from Memory stage

- **ForwardFromWriteback**: Detects RAW hazard and forwards from Writeback stage

- **LoadUseStall**: Detects load-use hazard requiring a stall

- **LoadUseStallFlushesExecute**: Ensures stall inserts a bubble by flushing Execute


#### Branch Unit Testbench (`branch_unit_tb.cpp`)

Tests all branch condition types:

```cpp

// BEQ: Branch if equal (Zero flag set)

TEST_F(BranchUnitTestbench, BeqTaken)

{

    top->funct3_i = 0b000;  // BEQ encoding

    top->Zero_i = 1;        // Operands are equal

    top->eval();

    EXPECT_EQ(top->BranchTaken_o, 1);

}

  

// BNE: Branch if not equal (Zero flag clear)

TEST_F(BranchUnitTestbench, BneTaken)

{

    top->funct3_i = 0b001;  // BNE encoding

    top->Zero_i = 0;        // Operands are not equal

    top->eval();

    EXPECT_EQ(top->BranchTaken_o, 1);

}

  

// BLT: Branch if less than (negative result)

TEST_F(BranchUnitTestbench, BltTaken)

{

    top->funct3_i = 0b100;       // BLT encoding

    top->ALUResult_i = 0x80000000; // MSB set = negative

    top->eval();

    EXPECT_EQ(top->BranchTaken_o, 1);

}

  

// BGE: Branch if greater or equal (non-negative result)

TEST_F(BranchUnitTestbench, BgeTaken)

{

    top->funct3_i = 0b101;  // BGE encoding

    top->ALUResult_i = 0x00000001; // Positive

    top->eval();

    EXPECT_EQ(top->BranchTaken_o, 1);

}

  

// Default case: unknown funct3 should not branch

TEST_F(BranchUnitTestbench, DefaultNotTaken)

{

    top->funct3_i = 0b111;  // Invalid/unused encoding

    top->Zero_i = 0;

    top->ALUResult_i = 0;

    top->eval();

    EXPECT_EQ(top->BranchTaken_o, 0);

}

```

  
#### Control Unit Testbench (`control_unit_tb.cpp`)

Verifies correct decoding for each instruction type:

```cpp

// ADDI: I-type immediate arithmetic

TEST_F(ControlUnitTestbench, AddiDecodeTest)

{

    top->op_i = 0b0010011;    // I-type ALU opcode

    top->funct3_i = 0b000;    // ADD function

    top->eval();

  

    EXPECT_EQ(top->RegWrite_o, 1);    // Will write to register

    EXPECT_EQ(top->ALUControl_o, 0b000); // ADD operation

    EXPECT_EQ(top->ALUSrc_o, 1);      // Use immediate

    EXPECT_EQ(top->ImmSrc_o, 0b000);  // I-type immediate

    EXPECT_EQ(top->ResultSrc_o, 0b00); // Result from ALU

    EXPECT_EQ(top->Branch_o, 0);      // Not a branch

}

  

// LW: Load word

TEST_F(ControlUnitTestbench, LoadDecodeTest)

{

    top->op_i = 0b0000011;    // Load opcode

    top->funct3_i = 0b010;    // Word access

    top->eval();

  

    EXPECT_EQ(top->RegWrite_o, 1);    // Will write to register

    EXPECT_EQ(top->ResultSrc_o, 0b01); // Result from memory

    EXPECT_EQ(top->ALUSrc_o, 1);      // Use immediate for address

    EXPECT_EQ(top->MemWrite_o, 0);    // Not writing to memory

}

  

// SW: Store word

TEST_F(ControlUnitTestbench, StoreDecodeTest)

{

    top->op_i = 0b0100011;    // Store opcode

    top->funct3_i = 0b010;    // Word access

    top->eval();

  

    EXPECT_EQ(top->RegWrite_o, 0);    // No register write

    EXPECT_EQ(top->MemWrite_o, 1);    // Writing to memory

    EXPECT_EQ(top->ALUSrc_o, 1);      // Use immediate for address

    EXPECT_EQ(top->ImmSrc_o, 0b010);  // S-type immediate

}

  

// BNE: Branch if not equal

TEST_F(ControlUnitTestbench, BneDecodeTest)

{

    top->op_i = 0b1100011;    // Branch opcode

    top->funct3_i = 0b001;    // BNE function

    top->eval();

  

    EXPECT_EQ(top->Branch_o, 1);      // Is a branch

    EXPECT_EQ(top->ALUControl_o, 0b001); // SUB for comparison

    EXPECT_EQ(top->ALUSrc_o, 0);      // Compare registers

    EXPECT_EQ(top->ImmSrc_o, 0b001);  // B-type immediate

}

```

  
  

#### Data Memory Testbench (`data_memory_tb.cpp`)

Tests both word and byte memory operations:

  
```cpp

// Store and load a full word

TEST_F(DataMemoryTestbench, StoreLoadWord)

{

    top->wr_en_i = 1;

    top->funct3_i = 0b010;         // Word operation

    top->addr_i = 0x00000010;

    top->data_i = 0xDEADBEEF;

  

    top->clk_i = 0; top->eval();

    top->clk_i = 1; top->eval();   // Rising edge writes

  

    top->wr_en_i = 0;

    top->funct3_i = 0b010;

    top->eval();

    EXPECT_EQ(top->data_o, 0xDEADBEEF);

}

  

// Store and load a single byte

TEST_F(DataMemoryTestbench, StoreLoadByte)

{

    top->wr_en_i = 1;

    top->funct3_i = 0b000;         // Byte operation

    top->addr_i = 0x00000020;

    top->data_i = 0x000000AA;

  

    top->clk_i = 0; top->eval();

    top->clk_i = 1; top->eval();

  

    top->wr_en_i = 0;

    top->funct3_i = 0b000;

    top->eval();

    EXPECT_EQ(top->data_o, 0xAAu); // Zero-extended byte

}

```

  

These tests were particularly important for debugging the funct3 byte offset logic in the cache.


#### PC Multiplexer Testbench (`mux_reg_tb.cpp`)

Tests the PC selection logic for different instruction types:

```cpp

// Default: sequential execution (PC + 4)

TEST_F(MuxRegTestbench, DefaultTakesPcPlus4)

{

    top->PCPlus4F_i = 0x10;

    top->eval();

    EXPECT_EQ(top->PCNext_o, 0x10u);

}

  

// Branch taken: use PCTarget

TEST_F(MuxRegTestbench, BranchTakesTarget)

{

    top->PCTargetE_i = 0x200;

    top->PCSrcE_i = 1;

    top->JalrE_i = 0;

    top->eval();

    EXPECT_EQ(top->PCNext_o, 0x200u);

}

  

// JALR: use ALU result (rs1 + imm)

TEST_F(MuxRegTestbench, JalrUsesAluResult)

{

    top->ALUResultE_i = 0xDEADBEEF;

    top->PCTargetE_i = 0x12340000;  // Should be ignored

    top->PCSrcE_i = 1;

    top->JalrE_i = 1;               // JALR flag

    top->eval();

    EXPECT_EQ(top->PCNext_o, 0xDEADBEEF);

}

```

  
#### ALU Testbench (`ALU_tb.cpp`)

Comprehensive tests for all ALU operations:


```cpp

// ADD operation

TEST_F(ALUTestbench, AddWorksTest)

{

    top->ALUControl_i = 0b000;

    top->SrcA_i = 10;

    top->SrcB_i = 20;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 30);

    EXPECT_EQ(top->Zero_o, 0);

}

  

// SUB operation

TEST_F(ALUTestbench, SubWorksTest)

{

    top->ALUControl_i = 0b001;

    top->SrcA_i = 20;

    top->SrcB_i = 5;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 15);

}

  

// AND operation

TEST_F(ALUTestbench, AndWorksTest)

{

    top->ALUControl_i = 0b010;

    top->SrcA_i = 0b1100;

    top->SrcB_i = 0b1010;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 0b1000);

}

  

// OR operation

TEST_F(ALUTestbench, OrWorksTest)

{

    top->ALUControl_i = 0b011;

    top->SrcA_i = 0b1100;

    top->SrcB_i = 0b0110;

    top->eval();

    EXPECT_EQ(top->ALUResult_o, 0b1110);

}

  

// SLT (Set Less Than)

TEST_F(ALUTestbench, SltWorksTest)

{

    top->ALUControl_i = 0b101;

    top->SrcA_i = 5;

    top->SrcB_i = 9;

    top->eval();

    EXPECT_EQ(top->Zero_o, 1); // 5 < 9, so Zero flag set

}

```

  
#### Instruction Memory Testbench (`instr_mem_tb.cpp`)

Tests instruction fetch functionality:

```cpp

TEST_F(InstrMemTestbench, ReadsFirstWordIfPresent)

{

    std::ifstream fin("program.hex");

    if (!fin.is_open())

    {

        GTEST_SKIP() << "program.hex not present, skipping ROM content check";

    }

  

    // Pull first 4 bytes and reconstruct word (little-endian)

    std::string line;

    uint32_t bytes[4] = {0};

    for (int i = 0; i < 4 && std::getline(fin, line); ++i)

    {

        std::stringstream ss;

        ss << std::hex << line;

        ss >> bytes[i];

    }

    uint32_t expected = (bytes[3] << 24) | (bytes[2] << 16) |

                        (bytes[1] << 8) | bytes[0];

  

    top->A_i = 0;

    top->eval();

    EXPECT_EQ(top->RD_o, expected);

}

```

  

This test gracefully handles the case where `program.hex` isn't present, using gtest's skip functionality.

### Integration Testing

The full system was verified using the provided test programs in `tb/tests/verify.cpp`:

  

```cpp

TEST_F(CpuTestbench, TestAddiBne) {

    setupTest("1_addi_bne");

    initSimulation();

    runSimulation(CYCLES);

    EXPECT_EQ(top_->a0, 254);

}

  

TEST_F(CpuTestbench, TestLbuSb) {

    setupTest("3_lbu_sb");

    initSimulation();

    runSimulation(CYCLES);

    EXPECT_EQ(top_->a0, 300);

}

  

TEST_F(CpuTestbench, TestPdf) {

    setupTest("5_pdf");

    setData("reference/gaussian.mem");

    initSimulation();

    runSimulation(CYCLES * 100);

    EXPECT_EQ(top_->a0, 15363);

}

```

  

The `3_lbu_sb` test was particularly important for validating the funct3 byte offset logic - it only passed after implementing the byte addressing correctly in the cache.

  

### Summary of Testbenches Created

Below is a summary of all component test benches I created:
  
**ALU**
File: ALU_tb.cpp
Tests covered: ADD, SUB, AND, OR, SLT, default case

**Branch Unit**
File: branch_unit_tb.cpp
Tests covered: BEQ, BNE, BLT, BGE, default

**Control Unit**
File: control_unit_tb.cpp
Tests covered: ADDI, LOAD, STORE, BNE, default

**Data Memory**
File: data_memory_tb.cpp
Tests covered: Word store/load, byte store/load

**Hazard Unit**
File: hazard_unit_tb.cpp
Tests covered: Memory forward, WB forward, LW stall, flush

**Instruction Memory**
File: instr_mem_tb.cpp
Tests covered: First word read verification

**PC Mux**
File: mux_reg_tb.cpp
Tests covered: PC+4, branch target, JALR
## Project Management

### Version Control Strategy

I established the versioning principles for our team during the November 28th meeting:

- **Feature branches**: Each team member works on their own branch or 2 people working on the same branch if they are doing it together

- **Main branch protection**: All merges to main require peer review and testing

- **Release tags**: Major milestones are tagged for easy reference apart from the single cycle CPU which we left on one [branch](https://github.com/IAC-Group-2/Project_Brief/commits/single_cycle)

I resolved multiple merge conflicts throughout the project, particularly when integrating:

- Control unit updates with the pipeline

- Cache module with the pipelined processor

- Full instruction set branch with cache implementation

The largest one was this commit, introducing the stretch goal 3 and cache due to parallel development of both. See [here](https://github.com/IAC-Group-2/Project_Brief/commit/0a64becde15de50b46a8f47c59d855d549958a39). This required a live video call with Anthony, Yichan and I.

### Team Coordination


Task allocation was structured around the pipeline stages:

- **Stage 1 (Nov 25-26)**: Pipeline registers and initial integration

- **Stage 2 (Nov 28)**: Hazard unit implementation

- **Parallel work**: Control unit and ALU updates by Carys and Anthony

- **Stage 3**: Cache implementation

- **Stage 4**: Lots of debugging the cache

- **Parallel work**: Carys and Anthony making full instruction set working in ALU and control unit.

- **Stage 5**: Integration and testing on assembly test benches

- **Stage 6**: Individual component testing 
  

This structure allowed parallel development while minimizing merge conflicts.

## Conclusion & Reflections

### What I Learned

This project significantly deepened my understanding of:

1. **Pipelined processor architecture**: Understanding how instructions flow through stages and how hazards arise gave me practical insight into CPU design principles.

2. **Hardware description vs programming**: The biggest mental shift was thinking in terms of concurrent hardware rather than sequential software. Every `always_comb` block runs simultaneously, not sequentially.

3. **Cache design trade-offs**: Implementing a write-back cache taught me about the complexity of maintaining data coherency and the performance implications of different cache policies.

4. **GTKWave debugging**: Extensive debugging sessions made me proficient at tracing signals through waveforms and identifying timing issues.

### Mistakes Made

1. **Initial byte addressing oversight**: Our first cache implementation assumed all addresses were word-aligned, failing on byte operations. This required significant rework to add byte offset logic.

2. **Flush during cache stall**: Initially, the hazard unit would flush instructions during cache stalls, corrupting the pipeline state. The fix was simple but finding the bug took hours of waveform analysis.

3. **Underestimating integration complexity**: I assumed connecting modules would be straightforward, but cache state changing and naming mismatches caused numerous issues which were gladly minimised due to our diagram and thoughtful planning however they weren't fully eliminated.

### What I Would Do Differently

1. **More upfront design**: While we created a cache diagram before implementation, I would spend more time designing the hazard unit logic on paper before coding.

2. **Earlier testing**: Writing component testbenches before integration would have caught issues like the byte addressing problem sooner.

3. **Better documentation**: Inline comments explaining the "why" behind design decisions would have helped when debugging weeks later.

### Team Acknowledgments

I'm grateful to have worked with such a dedicated team:

- **Yichan**: Close collaboration on pipeline registers, hazard unit, and cache implementation through numerous video calls

- **Carys and Anthony**: Delivering the control unit and ALU updates that enabled our pipelined processor

- The entire team for their commitment to achieving all stretch goals

This project demonstrated that effective communication and clear task allocation are just as important as technical skills in successful hardware design.
