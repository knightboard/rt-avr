.org 0x0000
.macro INT_DEF sym
.La=.
.ifdef \sym
	rjmp \sym
.else
	reti
.endif

.org .La+4
.endm

.macro PUSHLST tmp, car, cdr:vararg
	PUSHREG \car, \tmp
	.ifnb \cdr
	PUSHLST \tmp, \cdr
	.endif		
.endm

.macro POPLST tmp, car, cdr:vararg
	.ifnb \cdr
	POPLST \tmp, \cdr
	.endif
	POPREG \car, \tmp
.endm

.macro PROLOG car, cdr:vararg
	.if (\car >= 0x20)
		.error "Must be register"
		.exitm
	.endif
	push \car
	.ifnb \cdr
		PUSHLST \car, \cdr
	.endif
.endm

.macro EPILOG car, cdr:vararg
	.if (\car >= 0x20)
		.error "Must be register"
		.exitm
	.endif
	.ifnb \cdr
		POPLST \car, \cdr
	.endif
	pop \car
.endm

.macro PUSHREG reg, tmpreg=R16
	.if (\reg >= 0x20)
		IOLDS \tmpreg, \reg
		push \tmpreg
	.else
		push \reg
	.endif
.endm

.macro POPREG reg, tmpreg=R16
	.if (\reg >= 0x20)
		pop \tmpreg
		IOSTS \reg, \tmpreg
	.else
		pop \reg
	.endif
.endm

.macro IOLDS reg, ioreg
	.if (\ioreg < 0x60)
		.if (\ioreg < 0x20)
			.error "Must be IO register"
			.exitm
		.endif
		in \reg, (\ioreg - 0x20)
	.else
		lds \reg, \ioreg
	.endif
.endm 

.macro IOSTS ioreg, reg
	.if (\ioreg < 0x60)
		.if (\ioreg < 0x20)
			.error "Must be IO register"
			.exitm
		.endif
		out (\ioreg - 0x20), \reg
	.else
		sts \ioreg, \reg
	.endif
.endm

	;; Interrupt table only for atmega32
	jmp .L1  ; (RESET)
	INT_DEF INT0_VEC		; (INTO) External interrupt request 0
	INT_DEF INT1_VEC		; (INT1) External interrupt request 1
	INT_DEF INT2_VEC	; (INT2) External Interrupt request 2
	INT_DEF TIMER1_COMP_VEC		; (TIMER1 COMP)
	INT_DEF	TIMER2_COMP_VEC	; (TIMER2 OVF)
	INT_DEF	TIMER1_CAPT_VEC; (TIMER1 CAPT)
	INT_DEF TIMER1_COMPA_VEC		; (TIMER1 COMPA)
	INT_DEF	TIMER1_COMPB_VEC	; (TIMER1 COMPB)
	INT_DEF	TIMER1_OVF_VEC	; (TIMER1 OVF)
	INT_DEF	TIMER0_COMP_VEC	; (TIMER0 COMP)
	INT_DEF	TIMER0_OVF_VEC	; (TIMER0 OVF)
	INT_DEF	SPI_STC_VEC	; (SPI, STC) Serial Transfer Complete
	INT_DEF	USART_RXC_VEC	; (USART, RXC) USART, RX Complete
	INT_DEF	USART_UDRE_VEC	; (USART, UDRE) USART Data Register Empty
	INT_DEF	USART_TXC_VEC	; (USART, TXC) USART, TX Complete
	INT_DEF	ADC_VEC	; (ADC) ADC Conversion complete
	INT_DEF	EE_RDY_VEC	; (EE_RDY) EEPROM READY
	INT_DEF	ANA_COMP_VEC	; (ANA_COMP) Analog comparator
	INT_DEF	TWI_VEC	; (TWI) 2-wire Serial Interface
	INT_DEF	SPM_RDY_VEC	; (SPM_RDY) Store Program Memory Ready

.org _VECTORS_SIZE
;; Interrupts

;; End Interrupts

.L1:
	clr R0
	clr R1
	clr R2
	clr R3
	clr R4
	clr R5
	clr R6
	clr R7
	clr R8
	clr R9
	clr R10
	clr R11
	clr R12
	clr R13
	clr R14
	clr R15
	clr R16
	clr R17
	clr R18
	clr R19
	clr R20
	clr R21
	clr R22
	clr R23
	clr R24
	clr R25
	clr XL
	clr XH
	clr YL
	clr YH
	clr ZL
	clr ZH
	;; Init stack
	ldi R16, lo8(RAMEND)
	out IOSPL, R16

	ldi R16, hi8(RAMEND)
	out IOSPH, R16


	ldi ZL, lo8(RAMSTART)
	clr R16

.L2:

	st Z+, R16
	cpi ZH, hi8(RAMEND)
	brne .L2
	cpi ZL, lo8(RAMEND)
	brne .L2

	clr ZL
	clr ZH
	out IOSREG, R16			; Инициализация SREG 

.ifdef RESET_VEC
	rjmp RESET_VEC
.endif
