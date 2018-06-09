.include "avr.inc"
.include "rtos.inc"
RESET_VEC=main
TIMER_2_COMP_VEC=RT_TimerInterrupt
.section .text
.include "startup.asm"


main:
	rcall RT_Init

    ldi R16, 0b00000011
    out DDRD, R16     
	ldi R16, 0b00000000
	out PORTD, R16

	RT_TIMER 2, 50 
	RT_TIMER 1, 70 
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
	ret
Task1:
	sbi IOPORTD, 0
	RT_TIMER 3, 123 
	ret
Task2:
	sbi IOPORTD, 1
	RT_TIMER 4, 351
	ret
Task3:
	cbi IOPORTD, 0
	RT_TIMER 1, 212
	ret
Task4:
	cbi IOPORTD, 1
	RT_TIMER 2, 211
	ret
	
.section .eeprom
.end
