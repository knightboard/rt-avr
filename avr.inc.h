#include <avr/io.h>

.equ "TWBR", TWBR
.equ "TWSR", TWSR
.equ "TWAR", TWAR
.equ "TWDR", TWDR
.equ "ADCW", ADCW
.equ "ADCL", ADCL
.equ "ADCH", ADCH
.equ "IOADCH", _SFR_IO_ADDR(ADCH)
.equ "ADCSRA", ADCSRA
.equ "IOADCSRA", _SFR_IO_ADDR(ADCSRA)
.equ "ADMUX", ADMUX
.equ "ACSR", ACSR
.equ "UBRRL", UBRRL
.equ "UCSRB", UCSRB
.equ "UCSRA", UCSRA
.equ "UDR", UDR
.equ "SPCR", SPCR
.equ "SPSR", SPSR
.equ "SPDR", SPDR
.equ "PIND", PIND
.equ "DDRD", DDRD
.equ "PORTD", PORTD
.equ "PINC", PINC
#ifdef DDRC
.equ "DDRC", DDRC
.equ "IODDRC", _SFR_IO_ADDR(DDRC)
#endif
.equ "PORTC", PORTC
.equ "PINB", PINB
.equ "DDRB", DDRB
.equ "PORTB", PORTB
.equ "PINA", PINA
.equ "DDRA", DDRA
.equ "IODDRA", _SFR_IO_ADDR(DDRA)
.equ "PORTA", PORTA
.equ "EECR", EECR
.equ "EEDR", EEDR
.equ "EEAR", EEAR
.equ "EEARL", EEARL
.equ "EEARH", EEARH
.equ "UBRRH", UBRRH
.equ "UCSRC", UCSRC
.equ "WDTCR", WDTCR
.equ "ASSR", ASSR
.equ "SFIOR", SFIOR
.equ "OSCCAL", OSCCAL
.equ "OCDR", OCDR
#ifdef MCUSR
.equ "MCUSR", MCUSR
.equ "IOMCUSR", _SFR_IO_ADDR(MCUSR)
#endif
.equ "MCUCSR", MCUCSR
.equ "MCUCR", MCUCR
.equ "TWCR", TWCR
.equ "SPMCR", SPMCR
.equ "TIFR", TIFR
#ifdef TIMSK
.equ "TIMSK", TIMSK
.equ "IOTIMSK", _SFR_IO_ADDR(TIMSK)
#endif
.equ "GIFR", GIFR
#ifdef GIMSK
.equ "GIMSK", GIMSK
.equ "IOGIMSK", _SFR_IO_ADDR(GIMSK)
#endif

.equ "GICR", GICR
.equ "_VECTORS_SIZE", _VECTORS_SIZE
.equ "IVSEL", IVSEL
.equ "IVCE", IVCE
.equ "SPMIE", SPMIE
.equ "RWWSB", RWWSB
.equ "RWWSRE", RWWSRE
.equ "BLBSET", BLBSET
.equ "PGWRT", PGWRT
.equ "PGERS", PGERS
.equ "SPMEN", SPMEN
.equ "TWINT", TWINT
.equ "TWEA", TWEA
.equ "TWSTA", TWSTA
.equ "TWSTO", TWSTO
.equ "TWWC", TWWC
.equ "TWEN", TWEN
.equ "TWIE", TWIE
.equ "TWGCE", TWGCE
.equ "SE", SE
.equ "JTD", JTD
.equ "JTRF", JTRF
.equ "WDRF", WDRF
.equ "BORF", BORF
.equ "EXTRF", EXTRF
.equ "PORF", PORF
.equ "ACME", ACME
.equ "PUD", PUD
.equ "WDTOE", WDTOE
.equ "WDE", WDE
.equ "SPIF", SPIF
.equ "WCOL", WCOL
.equ "SPIE", SPIE
.equ "SPE", SPE
.equ "DORD", DORD
.equ "MSTR", MSTR
.equ "CPOL", CPOL
.equ "CPHA", CPHA
.equ "RXC", RXC
.equ "TXC", TXC
.equ "UDRE", UDRE
.equ "FE", FE
.equ "DOR", DOR
.equ "PE", PE
.equ "MPCM", MPCM
.equ "RXCIE", RXCIE
.equ "TXCIE", TXCIE
.equ "UDRIE", UDRIE
.equ "RXEN", RXEN
.equ "TXEN", TXEN
.equ "URSEL", URSEL
.equ "UMSEL", UMSEL
.equ "USBS", USBS
.equ "UCPOL", UCPOL
.equ "ACD", ACD
.equ "ACBG", ACBG
.equ "ACO", ACO
.equ "ACI", ACI
.equ "ACIE", ACIE
.equ "ACIC", ACIC
.equ "ADEN", ADEN
.equ "ADSC", ADSC
.equ "ADATE", ADATE
.equ "ADIF", ADIF
.equ "ADIE", ADIE
.equ "ADLAR", ADLAR
.equ "EERIE", EERIE
.equ "EEMWE", EEMWE
.equ "EEWE", EEWE
.equ "EERE", EERE
.equ "SPM_PAGESIZE", SPM_PAGESIZE
.equ "RAMSTART", RAMSTART
.equ "RAMEND", RAMEND
.equ "XRAMEND", XRAMEND
.equ "FLASHEND", FLASHEND
.equ "FUSE_MEMORY_SIZE", FUSE_MEMORY_SIZE
#ifdef TCCR0
.equ "TCCR0", TCCR0
.equ "IOTCCR0", _SFR_IO_ADDR(TCCR0)
#endif
#ifdef TCCR2
.equ "TCCR2", TCCR2
.equ "IOTCCR2", _SFR_IO_ADDR(TCCR2)
#endif
#ifdef TCCR1B
.equ "TCCR1B", TCCR1B
.equ "IOTCCR1B", _SFR_IO_ADDR(TCCR1B)
#endif
#ifdef TCCR1A
.equ "TCCR1A", TCCR1A
.equ "IOTCCR1A", _SFR_IO_ADDR(TCCR1A)
#endif
#ifdef TCNT0
.equ "TCNT0", TCNT0
.equ "IOTCNT0", _SFR_IO_ADDR(TCNT0)
#endif
#ifdef TCNT1L
.equ "TCNT1L", TCNT1L
.equ "IOTCNT1L", _SFR_IO_ADDR(TCNT1L)
#endif
#ifdef TCNT1H
.equ "TCNT1H", TCNT1H
.equ "IOTCNT1H", _SFR_IO_ADDR(TCNT1H)
#endif
#ifdef TCNT1
.equ "TCNT1", TCNT1
.equ "IOTCNT1", _SFR_IO_ADDR(TCNT1)
#endif
#ifdef TCNT2
.equ "TCNT2", TCNT2
.equ "IOTCNT2", _SFR_IO_ADDR(TCNT2)
#endif
#ifdef SREG
.equ "SREG", SREG
.equ "IOSREG", _SFR_IO_ADDR(SREG)
#endif

.equ "IOSPL", _SFR_IO_ADDR(SPL)
.equ "IOSPH", _SFR_IO_ADDR(SPH)
.equ "IOPORTD", _SFR_IO_ADDR(PORTD)
.equ "IOPORTB", _SFR_IO_ADDR(PORTB)
.equ "IOPORTC", _SFR_IO_ADDR(PORTC)
.equ "IOPORTA", _SFR_IO_ADDR(PORTA)
.equ "IOPINB", _SFR_IO_ADDR(PINB)
.equ "IODDRD", _SFR_IO_ADDR(DDRD)
.equ "IODDRB", _SFR_IO_ADDR(DDRB)
.equ "IOADMUX", _SFR_IO_ADDR(ADMUX)
.equ "IOADCSRA", _SFR_IO_ADDR(ADCSRA)
.equ "IOTCCR2", _SFR_IO_ADDR(TCCR2)
.equ "IOTCNT2", _SFR_IO_ADDR(TCNT2)
.equ "IOOCR2", _SFR_IO_ADDR(OCR2)

; bits for TCCR2 atmega32
.equ "FOC2", 7
.equ "WGM20", 6
.equ "COM21", 5
.equ "COM20", 4
.equ "WGM21", 3
.equ "CS22", 2
.equ "CS21", 1
.equ "CS20", 0
; bits for APCSRA atmega32
.equ "ADEN", 7
.equ "ADSC", 6
.equ "ADATE", 5
.equ "ADIF", 4
.equ "ADIE", 3
.equ "ADPS2", 2
.equ "ADPS1", 1
.equ "ADPS0", 0

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
