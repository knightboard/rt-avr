.equ Counter , R16				; Счетчик (преимущественно используется для организации циклов)			;
.equ OSRG , R17
.equ Tmp2 , R18					;
.equ Tmp3 , R19					;
.equ Tmp4 , R20					; Некоторые переменные общего назначения

.equ MainClock 		, 8000000				; CPU Clock
.equ TimerDivider 	, MainClock/64/1000 	; 1 mS

.macro RT_TIMER taskno, ms
	ldi 	OSRG, \taskno
	ldi 	XL, lo8(\ms)
	ldi 	XH, hi8(\ms)
	rcall 	SetTimer
.endm


.macro RT_TASK taskno, ms
	ldi OSRG, \taskno
	rcall SendTask
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
