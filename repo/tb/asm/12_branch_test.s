.text
.globl main

main:

    li t0, 5
    li t1, 10
    li t2, -3
    li t3, -8


# BEQ

    beq t0, t0, BEQ_OK
    li a0, 1            # FAIL
BEQ_OK:


# BNE

    bne t0, t1, BNE_OK
    li a0, 2            # FAIL
BNE_OK:

# BLT (signed)

    blt t2, t0, BLT_OK
    li a0, 3            # FAIL
BLT_OK:


# BGE (signed)

    bge t0, t2, BGE_OK
    li a0, 4            # FAIL
BGE_OK:


# BLTU (unsigned)

    li t4, -1           # 0xFFFFFFFF
    li t5, 1

    bltu t5, t4, BLTU_OK
    li a0, 5            # FAIL
BLTU_OK:


# BGEU (unsigned)

    bgeu t4, t5, BGEU_OK
    li a0, 6            # FAIL
BGEU_OK:


# FINAL RESULT

    li a0, 100          # PASS

done:
    j done
