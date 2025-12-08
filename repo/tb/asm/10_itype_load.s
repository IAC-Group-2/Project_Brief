.text
.globl main

main:
    lui     t0, 0x00010      # base = 0x10000

    lb      a0, 0(t0)
    lbu     a1, 1(t0)
    lh      a2, 2(t0)
    lhu     a3, 4(t0)
    lw      a4, 8(t0)

    add     a0, a0, a1
    add     a0, a0, a2
    add     a0, a0, a3
    add     a0, a0, a4

loop:
    j loop
