.equ "ATMEGA8", 1
.equ "ATMEGA16", 2
.equ "ATMEGA32", 3

.macro IO_REG reg, value
	.equ "\reg", (\value + 0x20)
	.equ "IO\reg", \value
.endm

.macro INT_DEF size sym
.La=.
.ifdef \sym
	rjmp \sym
	.print "DEFINED"
.else
	reti
	.print "NOT_DEFINED"
.endif

.org .La+\size
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

#if defined(__AVR_ATmega8__)
	.include "inc/iom8.inc"
#elif defined( __AVR_ATmega16__) 
	.include "inc/iom16.inc"
#elif defined(__AVR_ATmega32__)
	.include "inc/iom32.inc"
#else
# error "Unknown MCU in def"
#endif

IO_REG SPL, 0x3D
IO_REG SPH, 0x3E
IO_REG SP, 0x3D
IO_REG SREG, 0x3F

.equ SREG_C, 0
.equ SREG_Z, 1
.equ SREG_N, 2
.equ SREG_V, 3
.equ SREG_S, 4
.equ SREG_H, 5
.equ SREG_T, 6
.equ SREG_I, 7


.equ R0, 0
.equ R1, 1 
.equ R2, 2 
.equ R3, 3 
.equ R4, 4 
.equ R5, 5 
.equ R6, 6 
.equ R7, 7 
.equ R8, 8 
.equ R9, 9 
.equ R10, 10
.equ R11, 11 
.equ R12, 12 
.equ R13, 13 
.equ R14, 14 
.equ R15, 15 
.equ R16, 16 
.equ R17, 17 
.equ R18, 18 
.equ R19, 19 
.equ R20, 20
.equ R21, 21 
.equ R22, 22 
.equ R23, 23 
.equ R24, 24 
.equ R25, 25 
.equ R26, 26 
.equ R27, 27 
.equ R28, 28 
.equ R29, 29 
.equ R30, 30
.equ R31, 31
.equ XL, 26
.equ XH, 27
.equ YL, 28
.equ YH, 29
.equ ZL, 30
.equ ZH, 31 
.equ Z, 30
.equ Y, 28
.equ X, 26

