	;; Interrupt table only for atmega7

.Lvstart=.
.if (MCU == ATMEGA8)
	rjmp .L1  ; (RESET)
	.org .Lvstart+2
	INT_DEF 2 INT0_VEC		; (INTO) External interrupt request 0
	INT_DEF 2 INT1_VEC		; (INT1) External interrupt request 1
	INT_DEF 2 TIMER2_COMP_VEC		; (TIMER1 COMP)
	INT_DEF 2 TIMER2_OVF_VEC	; (TIMER2 OVF)
	INT_DEF 2 TIMER1_CAPT_VEC; (TIMER1 CAPT)
	INT_DEF 2 TIMER1_COMPA_VEC		; (TIMER1 COMPA)
	INT_DEF 2 TIMER1_COMPB_VEC	; (TIMER1 COMPB)
	INT_DEF 2 TIMER1_OVF_VEC	; (TIMER1 OVF)
	INT_DEF 2 TIMER0_OVF_VEC	; (TIMER0 OVF)
	INT_DEF 2 SPI_STC_VEC	; (SPI, STC) Serial Transfer Complete
	INT_DEF 2 USART_RXC_VEC	; (USART, RXC) USART, RX Complete
	INT_DEF 2 USART_UDRE_VEC	; (USART, UDRE) USART Data Register Empty
	INT_DEF 2 USART_TXC_VEC	; (USART, TXC) USART, TX Complete
	INT_DEF 2 ADC_VEC	; (ADC) ADC Conversion complete
	INT_DEF 2 EE_RDY_VEC	; (EE_RDY) EEPROM READY
	INT_DEF 2 ANA_COMP_VEC	; (ANA_COMP) Analog comparator
	INT_DEF 2 TWI_VEC	; (TWI) 2-wire Serial Interface
	INT_DEF 2 SPM_RDY_VEC	; (SPM_RDY) Store Program Memory Ready

.elseif (MCU == ATMEGA16)

	jmp .L1  ; (RESET)
	.org .Lvstart+4
	INT_DEF 4 INT0_VEC		; (INTO) External interrupt request 0
	INT_DEF 4 INT1_VEC		; (INT1) External interrupt request 1
	INT_DEF 4 TIMER2_COMP_VEC		; (TIMER1 COMP)
	INT_DEF 4 TIMER2_OVF_VEC	; (TIMER2 OVF)
	INT_DEF 4 TIMER1_CAPT_VEC; (TIMER1 CAPT)
	INT_DEF 4 TIMER1_COMPA_VEC		; (TIMER1 COMPA)
	INT_DEF 4 TIMER1_COMPB_VEC	; (TIMER1 COMPB)
	INT_DEF 4 TIMER1_OVF_VEC	; (TIMER1 OVF)
	INT_DEF 4 TIMER0_OVF_VEC	; (TIMER0 OVF)
	INT_DEF 4 SPI_STC_VEC	; (SPI, STC) Serial Transfer Complete
	INT_DEF 4 USART_RXC_VEC	; (USART, RXC) USART, RX Complete
	INT_DEF 4 USART_UDRE_VEC	; (USART, UDRE) USART Data Register Empty
	INT_DEF 4 USART_TXC_VEC	; (USART, TXC) USART, TX Complete
	INT_DEF 4 ADC_VEC	; (ADC) ADC Conversion complete
	INT_DEF 4 EE_RDY_VEC	; (EE_RDY) EEPROM READY
	INT_DEF 4 ANA_COMP_VEC	; (ANA_COMP) Analog comparator
	INT_DEF 4 TWI_VEC	; (TWI) 2-wire Serial Interface
	INT_DEF 4 INT2_VEC	; (INT2) External Interrupt request 2
	INT_DEF 4 TIMER0_COMP_VEC	; (TIMER0 COMP)
	INT_DEF 4 SPM_RDY_VEC	; (SPM_RDY) Store Program Memory Ready

.elseif (MCU == ATMEGA32)

	jmp .L1  ; (RESET)
	.org .Lvstart+4
	INT_DEF 4 INT0_VEC		; (INTO) External interrupt request 0
	INT_DEF 4 INT1_VEC		; (INT1) External interrupt request 1
	INT_DEF 4 INT2_VEC	; (INT2) External Interrupt request 2
	INT_DEF 4 TIMER2_COMP_VEC		; (TIMER1 COMP)
	INT_DEF 4 TIMER2_OVF_VEC	; (TIMER2 OVF)
	INT_DEF 4 TIMER1_CAPT_VEC; (TIMER1 CAPT)
	INT_DEF 4 TIMER1_COMPA_VEC		; (TIMER1 COMPA)
	INT_DEF 4 TIMER1_COMPB_VEC	; (TIMER1 COMPB)
	INT_DEF 4 TIMER1_OVF_VEC	; (TIMER1 OVF)
	INT_DEF 4 TIMER0_COMP_VEC	; (TIMER0 COMP)
	INT_DEF 4 TIMER0_OVF_VEC	; (TIMER0 OVF)
	INT_DEF 4 SPI_STC_VEC	; (SPI, STC) Serial Transfer Complete
	INT_DEF 4 USART_RXC_VEC	; (USART, RXC) USART, RX Complete
	INT_DEF 4 USART_UDRE_VEC	; (USART, UDRE) USART Data Register Empty
	INT_DEF 4 USART_TXC_VEC	; (USART, TXC) USART, TX Complete
	INT_DEF 4 ADC_VEC	; (ADC) ADC Conversion complete
	INT_DEF 4 EE_RDY_VEC	; (EE_RDY) EEPROM READY
	INT_DEF 4 ANA_COMP_VEC	; (ANA_COMP) Analog comparator
	INT_DEF 4 TWI_VEC	; (TWI) 2-wire Serial Interface
	INT_DEF 4 SPM_RDY_VEC	; (SPM_RDY) Store Program Memory Ready

.else
	.error MCU
	.error "Unknown mcu"
.endif

.org VECTORS_SIZE
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
	.print "RESET_DEFINED"
	rjmp RESET_VEC
.endif
