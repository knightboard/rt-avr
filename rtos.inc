.global RT_Start
.global RT_TimerInterrupt
.global RT_Init
.global RT_SendTask
.global RT_SetTimer
.global RT_TaskProcs
.equ RT_TaskQueueSize, 11
.equ RT_TimersPoolSize, 5
.equ RT_TimerDivider, 8000000/64/1000 	; 1 mS
.equ RT_RG, R17
.macro RT_TIMER taskno, ms
	ldi 	RT_RG, \taskno
	ldi 	XL, lo8(\ms)
	ldi 	XH, hi8(\ms)
	rcall 	RT_SetTimer
.endm
.macro RT_TASK taskno, ms
	ldi RT_RG, \taskno
	rcall RT_SendTask
.endm

;SRAM STS analog for Tiny
/*
			.macro	LDR reg, addr
			push	ZL
			push	ZH

			ldi		ZL,lo8(\addr)
			ldi		ZH,hi8(\addr)

			ld		\reg, Z

			pop		ZH
			pop		ZL
			.endm



			.macro	STR reg, addr
			push	ZL
			push	ZH

			ldi		ZL,lo8(\addr)
			ldi		ZH,hi8(\addr)

			st		Z, \reg

			pop		ZH
			pop		ZL
			.endm

;=======================================================================================
;FLASH
			.macro	LDF reg, addr
			push	ZL
			push	ZH

			ldi		ZL, lo8(\addr*2)
			ldi		ZH, hi8(\addr*2)

			lpm		\reg, Z

			pop		ZH
			pop		ZL
			.endm

			.macro	LDPA addr
			ldi		ZL, lo8(\addr*2)
			ldi		ZH, hi8(\addr*2)
			.endm
;========================================================================================
;XYZ
			.macro	LDX addr
			ldi		XL, lo8(\addr)
			ldi		XH, hi8(\addr)
			.endm

			.macro	LDY addr
			ldi		YL, lo8(\addr)
			ldi		YH, hi8(\addr)
			.endm

			.macro	LDZ addr
			ldi		ZL, lo8(\addr)
			ldi		ZH, hi8(\addr)
			.endm

;========================================================================================
;USART INIT


			.macro	USART_INIT

			.equ XTAL 			, MainClock
			.equ baudrate 		, 19200
			.equ bauddivider 	, XTAL/(16*baudrate)-1

			
			OUTI 	UBRRL, lo8(bauddivider)
			OUTI 	UBRRH, hi8(bauddivider)
			OUTI 	UCSRA, 0
			OUTI 	UCSRB, (1<<RXEN)|(1<<TXEN)|(1<<RXCIE)|(1<<TXCIE)
			OUTI 	UCSRC, (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1)
			.endm
*/
