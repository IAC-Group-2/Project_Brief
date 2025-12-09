.text
.globl main

main:
    li a1, 6
    li a2, 7

    mul  a3, a1, a2      # 42
    mulh a4, a1, a2      # high signed
    mulhu a5, a1, a2
    mulhsu a6, a1, a2

    # Combine outputs 
    add a0, a3, a4
    add a0, a0, a5
    add a0, a0, a6

done:
    j done
