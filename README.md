# Single Cycle RISCV Processor
## Overview
Our single cycle implementation covers the basic requirements to run all the initial tests provided. Implemented instructions are listed below:

|Instruction type|Instructions|
|----------------|------------|
|R-type|`add` `sub` `and` `or` `sll` `slt`|
|I-type (Arithmetic|`addi` `andi` `ori` `slli` `slti`|
|I-type (Load)|`lw` `lb`|
|S-type|`sw` `sb`|
|B-type|`beq` `bne`|
|J-type|`jal` `jalr`|
|U-type|`lui`|

## Schematic

## Contributions
|Module|Josh|Yichan|Carys|Anthony|
|------|----|------|-----|-------|
|addr||||X|
|ALU||X|*||
|control_unit|||X|*|
|data_memory|*||X||
|instr_mem|||X||
|mux_reg|||X|*|
|pc_reg|||X|*|
|regfile||*|X||
|sign_extend|||X||
|top|*|*|X||
|F1 Assembly||||X|
|System testing and debugging|||X|*|
|PDF testing|||X||
|F1 testing||||X|

`X`: Main contributor

`*`: Partial contributor

## Testing
### Test Cases
Single cycle passes all the tests provided:
![Testbench tests](images/single_cycle%20test%20pass.png)

### F1 light
*insert gif
*insert video

### PDF - Gaussian
![Gaussian test](images/gaussian.gif)

[Link to higher quality video](videos/gaussian.mp4)

### PDF - Triangle
![Triangle test](images/triangle.gif)

[Link to higher quality video](videos/triangle.mp4)

### PDF - Noisy
![Noisy test](images/noisy.gif)

[Link to higher quality video](videos/noisy.mp4)

For the PDF testbench, we display data every 4 cycles in order to plot unique data point per loop. This is because of the implementation of PDF in `5_pdf.s` assembly code:
```
display:    # function send PDF array value to a0 for display
    LI      s1, 0               # s1 = counter to sum pdf values (not in original)
    LI      a1, 0               # a1 = offset into pdf array
    LI      a2, 255             # a2 = max index of pdf array
_loop3:                         # repeat
    LBU     a0, base_pdf(a1)    #   a0 = mem[base_pdf+a1)
    ADD     s1, s1, a0          #   s1 += mem[base_pdf+a1)
    ADDI    a1, a1, 1           #   incr
    BNE     a1, a2, _loop3      # until end of pdf array
    RET
```
We can see that the value in register `a0` only updates once every 4 clock cycles. Plotting every single cycle would lead to the graph look stretched out horizontally.
