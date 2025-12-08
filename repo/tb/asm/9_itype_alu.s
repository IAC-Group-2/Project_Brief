.text
.globl main

main:

    # ADDI
    addi    a0, zero, 10
    addi    a0, a0, 5        # a0 = 15

    # ANDI
    andi    a1, a0, 0b1100   # 15 & 12 = 12

    # ORI
    ori     a2, a1, 0b0011   # 12 | 3 = 15

    # XORI
    xori    a3, a2, 0b0101   # 15 ^ 5 = 10

    # SLLI
    slli    a4, a3, 2        # 10 << 2 = 40

    # SRLI
    srli    a5, a4, 3        # 40 >> 3 = 5

    # SRAI (sign shift)
    addi    t1, zero, -16
    srai    a6, t1, 2        # -16 >> 2 = -4

    # SLTI
    slti    a7, a6, -2       # -4 < -2 → true => 1

    # SLTIU (unsigned compare)
    sltiu   t2, a6, 1        # -4 unsigned < 1 → false => 0

    # Final result check = sum of all above
    add     a0, a0, a7       # 15 + 1  = 16
    add     a0, a0, t2       # + 0     = 16

done:
    j done
