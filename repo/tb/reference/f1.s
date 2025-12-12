.text
.globl main

main:
    li      a0, 0x0                 # a0 = FSM state 
    li      a2, 0                   # a2 = cmd_delay
    li      a3, 0                   # a3 = cmd_seq
    li      t1, 0b11111111          # t1 = Terminal LED state (8 lights)
    li      t4, 0b1011010           # 7-bit LFSR seed

shift_loop:
    li      t2, 30                  # t2 = Visible delay between lights

delay_loop:
    addi    t2, t2, -1              # t2--
    bnez    t2, delay_loop          # Loop until t2 == 0
    slli    a0, a0, 1               # Shift LED pattern left
    ori     a0, a0, 1               # ins 1
    bne     a0, t1, state_output    # If not all LEDs on, continue

state_S8:
    li      a2, 1                   # cmd_delay = 1
    li      t2, 6  

base_delay:
    addi    t2, t2, -1              # t2--
    bnez    t2, base_delay          # Loop until t2 == 0
    andi    t5, t4, 1               # feedback bit
    srli    t4, t4, 1               # Shift LFSR   
    beqz    t5, lfsr_done           # If feedback bit == 0, skip xor
    xori    t4, t4, 0b1100000       # Feedback polynomial

lfsr_done:
    andi    t5, t4, 0x1F            # Random value: 0–31
    addi    t5, t5, 1               #   "      "    1–32

random_delay:
    li      t2, 3                   # Inner loop scaling

rand_inner:
    addi    t2, t2, -1              # t2--
    bnez    t2, rand_inner          # Loop until t2 == 0
    addi    t5, t5, -1              # t5--
    bnez    t5, random_delay        # Loop until t5 == 0
    li      a0, 0x0                 # Reset LEDs
    li      a2, 0                   # cmd_delay = 0
    li      a3, 0                   # cmd_seq = 0
    j       shift_loop              # Restart LED Sequence 

state_output:
    li      a3, 1                   # cmd_seq = 1
    j       shift_loop              # Continue LED Sequence
