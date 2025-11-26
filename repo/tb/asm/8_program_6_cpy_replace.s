.text
.globl main
main:
    addi    t1, zero, 0xff      # t1 = 255
    addi    a3, zero, 0x0       # output (was a0, now a3) = 0
    addi    a0, zero, 0x0       # counter for outer loop additions (was a3, now a0)

mloop:
    addi    a1, zero, 0x0       # i = 0

iloop:
    addi    a3, a1, 0           # output = i     
    addi    a1, a1, 1           # i++
    bne     a1, t1, iloop       # if i != 255, goto iloop

    add     a0, a0, 100         # increment counter

    bne     t1, zero, mloop     # infinite loop
