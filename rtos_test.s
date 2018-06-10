.include "avr.inc"
.include "rtos.inc"
.section .text
.equ RESET_VEC, main
.equ TIMER2_COMP_VEC, RT_TimerInterrupt
# .equ TIMER2_COMP_VEC, Idle 
.include "startup.asm"
main:
	rcall RT_Init

    ldi R16, 0b00000011
    out IODDRD, R16     
	ldi R16, 0b00000000
	out IOPORTD, R16

	RT_TIMER 2, 500 
	RT_TIMER 1, 500 
	
	
	rjmp RT_Start
RT_TaskProcs:
	.word Idle
	.word Task1
	.word Task2
	.word Task3
	.word Task4

Idle:
	ret	
Task1:
	sbi IOPORTD, 0
	RT_TIMER 3, 200
	ret
Task2:
	sbi IOPORTD, 1
	RT_TIMER 4, 201 
	ret
Task3:
	cbi IOPORTD, 0
	RT_TIMER 1, 200 
	ret
Task4:
	cbi IOPORTD, 1
	RT_TIMER 2, 201 
	ret
	
.section .eeprom
.end
