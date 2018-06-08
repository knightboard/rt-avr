.include "avr.inc"
.include "kernel_macro.inc"
.section .data
.equ TaskQueueSize, 11
TaskQueue:
.space TaskQueueSize
.equ TimersPoolSize, 5
TimersPool:
.space TimersPoolSize*3
.equ Treshold, 1


.section .text
RESET_VEC=main
TIMER_2_COMP_VEC=TimerInterrupt
RAMEND=500
.include "startup.asm"


main:
	rcall InitRtos
	RT_TIMER 2, 1
	RT_TIMER 3, 2	
	RT_TIMER 1, 3
	rcall TimerInterrupt
	rcall TimerInterrupt
	rcall TimerInterrupt
	rcall TimerInterrupt
	rcall TimerInterrupt
	rjmp StartRtos
TaskProcs:
	.word Idle
	.word Task1
	.word Task2
	.word Task3
Idle:
	nop
	nop
	ret
Task1:
	nop
	nop
	ret
Task2:
	nop
	nop
	ret
Task3:
	nop
	nop
	ret
.include "kernel.asm"
	
.section .eeprom

.end
