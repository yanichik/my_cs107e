.globl _start
_start:

.equ DELAY, 0x03f000	// delay between transitions
.equ FULL, 	0x000f		// FULL & DIM1 delays determine duty cycle
.equ DIM1, 	0x000f		// Duty Cycle = FULL/(FULL+DIM1)


// configure GPIO 20-23 for output
ldr r0, FSEL2
mov r1, #0x049
mov r2, #0x200
add r1, r1, r2
str r1, [r0]

// initialize count r6, r8 (previous cnt value), and starting shift r7 at GPIO 19
// to initiate the brightest LED at GPIO 20
mov r6, #3
mov r7, #19
mov r8, #4

mov r9, #DELAY
//	outerloop responsible for counting down the time between transitions
outerloop:
    subs r9, #1
//	loop responsible for lighting the LEDs at appropriate ratio to accomplish
//	the desired duty cycle
loop:
mov r1, #7
mov r4, r1, lsl r7
// set GPIO high
ldr r0, SET0
str r4, [r0]

// delay
mov r5, #FULL
wait1:
    subs r5, #1
    bne wait1

// set GPIO low
mov r1, #5
mov r4, r1, lsl r7
ldr r0, CLR0
str r4, [r0]

// delay2
mov r5, #DIM1
wait2:
    subs r5, #1
    bne wait2

//	decision tree: if less than, than LEDs moving down. if greater than, moving down.
cmp r6, r8
blt down

cmp r6, r8
bgt up

//	& if equal to, it means an entire cycle has occured, so moving down again
down:
	cmp r9, #0
	bne outerloop
mov r9, #DELAY
mov r8, r6
add r7, #1
subs r6, r6, #1
cmp r6, #0
bge loop

//	transition from down to up
mov r9, #DELAY
mov r8, r6
add r6, #1
b up

up:
	cmp r9, #0
	bne outerloop
mov r9, #DELAY
mov r8, r6
sub r7, r7, #1
add r6, #1
cmp r6, #4
ble loop

//	transition from up to down
mov r9, #DELAY
mov r8, r6
subs r6, r6, #1
b down

FSEL0: .word 0x20200000
FSEL1: .word 0x20200004
FSEL2: .word 0x20200008
SET0:  .word 0x2020001C
SET1:  .word 0x20200020
CLR0:  .word 0x20200028
CLR1:  .word 0x2020002C
