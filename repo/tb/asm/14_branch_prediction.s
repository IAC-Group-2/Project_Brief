.text
.globl main

main:
    # Loop 20 times to saturate predictor.
    
    li a0, 0            # a0: Result count
    li t0, 20           # t0: Loop Counter

loop_start:
    addi a0, a0, 1      # Increment result
    addi t0, t0, -1     # Decrement counter
    
    # Branch taken 19 times, not taken 1 time.
    bne t0, zero, loop_start 

done:
    j done #spin
