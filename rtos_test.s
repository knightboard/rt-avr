.include "avr.inc"
.include "rtos.inc"
RESET_VEC=main
TIMER_2_COMP_VEC=RT_TimerInterrupt
.section .text
.include "startup.asm"


main:
	rcall RT_Init
	RT_TIMER 2, 1
	RT_TIMER 3, 2	
	RT_TIMER 1, 3
	rcall RT_TimerInterrupt
	rcall RT_TimerInterrupt
	rcall RT_TimerInterrupt
	rcall RT_TimerInterrupt
	rcall RT_TimerInterrupt
	rjmp RT_Start
RT_TaskProcs:
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
.end
	
.section .eeprom
.end
.include "kernel.asm"
