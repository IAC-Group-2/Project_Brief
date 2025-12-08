.text
.globl main

main:
    jal     ra, func
    addi    a0, zero, 0      # if we FAIL jumping, this runs

func:
    addi    a0, zero, 99
    jalr    zero, 0(ra)
