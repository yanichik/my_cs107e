.equ DELAY, 0x3f0000

// configure GPIO 20-23 for output
ldr r0, FSEL2
mov r1, #0x049
mov r2, #0x200
add r1, r1, r2
str r1, [r0]

// left shift to set bits 20-23
mov r1, #1

// initialize count and starting shift registers
mov r6, #3
mov r7, #20
mov r8, #4

loop:
// shift r1 by r7 to move to next LED
mov r4, r1, lsl r7

// set GPIO high
ldr r0, SET0
str r4, [r0]

// delay
mov r5, #DELAY
wait1:
    subs r5, #1
    bne wait1

// set GPIO low
ldr r0, CLR0
str r4, [r0]

cmp r6, r8
blt down

cmp r6, r8
bgt up

down:
mov r8, r6
add r7, #1
subs r6, r6, #1
cmp r6, #0
bge loop
b up

up:
mov r8, r6
sub r7, #1
add r6, #1
cmp r6, #3
ble loop
b down

FSEL0: .word 0x20200000
FSEL1: .word 0x20200004
FSEL2: .word 0x20200008
SET0:  .word 0x2020001C
SET1:  .word 0x20200020
CLR0:  .word 0x20200028
CLR1:  .word 0x2020002C
