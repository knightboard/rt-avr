# 1 "avr.inc.h"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "avr.inc.h"
# 1 "/usr/lib/avr/include/avr/io.h" 1 3
# 99 "/usr/lib/avr/include/avr/io.h" 3
# 1 "/usr/lib/avr/include/avr/sfr_defs.h" 1 3
# 100 "/usr/lib/avr/include/avr/io.h" 2 3
# 244 "/usr/lib/avr/include/avr/io.h" 3
# 1 "/usr/lib/avr/include/avr/iom32.h" 1 3
# 720 "/usr/lib/avr/include/avr/iom32.h" 3
       
# 721 "/usr/lib/avr/include/avr/iom32.h" 3

       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
# 245 "/usr/lib/avr/include/avr/io.h" 2 3
# 627 "/usr/lib/avr/include/avr/io.h" 3
# 1 "/usr/lib/avr/include/avr/portpins.h" 1 3
# 628 "/usr/lib/avr/include/avr/io.h" 2 3

# 1 "/usr/lib/avr/include/avr/common.h" 1 3
# 630 "/usr/lib/avr/include/avr/io.h" 2 3

# 1 "/usr/lib/avr/include/avr/version.h" 1 3
# 632 "/usr/lib/avr/include/avr/io.h" 2 3






# 1 "/usr/lib/avr/include/avr/fuse.h" 1 3
# 639 "/usr/lib/avr/include/avr/io.h" 2 3


# 1 "/usr/lib/avr/include/avr/lock.h" 1 3
# 642 "/usr/lib/avr/include/avr/io.h" 2 3
# 2 "avr.inc.h" 2

.equ "TWBR", ((0x00) + 0x20)
.equ "TWSR", ((0x01) + 0x20)
.equ "TWAR", ((0x02) + 0x20)
.equ "TWDR", ((0x03) + 0x20)
.equ "ADCW", ((0x04) + 0x20)
.equ "ADCL", ((0x04) + 0x20)
.equ "ADCH", ((0x05) + 0x20)
.equ "IOADCH", ((((0x05) + 0x20)) - 0x20)
.equ "ADCSRA", ((0x06) + 0x20)
.equ "IOADCSRA", ((((0x06) + 0x20)) - 0x20)
.equ "ADMUX", ((0x07) + 0x20)
.equ "ACSR", ((0x08) + 0x20)
.equ "UBRRL", ((0x09) + 0x20)
.equ "UCSRB", ((0x0A) + 0x20)
.equ "UCSRA", ((0x0B) + 0x20)
.equ "UDR", ((0x0C) + 0x20)
.equ "SPCR", ((0x0D) + 0x20)
.equ "SPSR", ((0x0E) + 0x20)
.equ "SPDR", ((0x0F) + 0x20)
.equ "PIND", ((0x10) + 0x20)
.equ "DDRD", ((0x11) + 0x20)
.equ "PORTD", ((0x12) + 0x20)
.equ "PINC", ((0x13) + 0x20)
.equ "DDRC", ((0x14) + 0x20)
.equ "PORTC", ((0x15) + 0x20)
.equ "PINB", ((0x16) + 0x20)
.equ "DDRB", ((0x17) + 0x20)
.equ "PORTB", ((0x18) + 0x20)
.equ "PINA", ((0x19) + 0x20)
.equ "DDRA", ((0x1A) + 0x20)
.equ "IODDRA", ((((0x1A) + 0x20)) - 0x20)
.equ "PORTA", ((0x1B) + 0x20)
.equ "EECR", ((0x1C) + 0x20)
.equ "EEDR", ((0x1D) + 0x20)
.equ "EEAR", ((0x1E) + 0x20)
.equ "EEARL", ((0x1E) + 0x20)
.equ "EEARH", ((0x1F) + 0x20)
.equ "UBRRH", ((0x20) + 0x20)
.equ "UCSRC", ((0x20) + 0x20)
.equ "WDTCR", ((0x21) + 0x20)
.equ "ASSR", ((0x22) + 0x20)
.equ "SFIOR", ((0x30) + 0x20)
.equ "OSCCAL", ((0x31) + 0x20)
.equ "OCDR", ((0x31) + 0x20)

.equ "MCUSR", ((0x34) + 0x20)
.equ "MCUSR", ((((0x34) + 0x20)) - 0x20)

.equ "MCUCSR", ((0x34) + 0x20)
.equ "MCUCR", ((0x35) + 0x20)
.equ "TWCR", ((0x36) + 0x20)
.equ "SPMCR", ((0x37) + 0x20)
.equ "TIFR", ((0x38) + 0x20)

.equ "TIMSK", ((0x39) + 0x20)
.equ "IOTIMSK", ((((0x39) + 0x20)) - 0x20)

.equ "GIFR", ((0x3A) + 0x20)

.equ "GIMSK", ((0x3B) + 0x20)
.equ "IOGIMSK", ((((0x3B) + 0x20)) - 0x20)


.equ "GICR", ((0x3B) + 0x20)
.equ "_VECTORS_SIZE", 84
.equ "IVSEL", 1
.equ "IVCE", 0
.equ "SPMIE", 7
.equ "RWWSB", 6
.equ "RWWSRE", 4
.equ "BLBSET", 3
.equ "PGWRT", 2
.equ "PGERS", 1
.equ "SPMEN", 0
.equ "TWINT", 7
.equ "TWEA", 6
.equ "TWSTA", 5
.equ "TWSTO", 4
.equ "TWWC", 3
.equ "TWEN", 2
.equ "TWIE", 0
.equ "TWGCE", 0
.equ "SE", 7
.equ "JTD", 7
.equ "JTRF", 4
.equ "WDRF", 3
.equ "BORF", 2
.equ "EXTRF", 1
.equ "PORF", 0
.equ "ACME", 3
.equ "PUD", 2
.equ "WDTOE", 4
.equ "WDE", 3
.equ "SPIF", 7
.equ "WCOL", 6
.equ "SPIE", 7
.equ "SPE", 6
.equ "DORD", 5
.equ "MSTR", 4
.equ "CPOL", 3
.equ "CPHA", 2
.equ "RXC", 7
.equ "TXC", 6
.equ "UDRE", 5
.equ "FE", 4
.equ "DOR", 3
.equ "PE", 2
.equ "MPCM", 0
.equ "RXCIE", 7
.equ "TXCIE", 6
.equ "UDRIE", 5
.equ "RXEN", 4
.equ "TXEN", 3
.equ "URSEL", 7
.equ "UMSEL", 6
.equ "USBS", 3
.equ "UCPOL", 0
.equ "ACD", 7
.equ "ACBG", 6
.equ "ACO", 5
.equ "ACI", 4
.equ "ACIE", 3
.equ "ACIC", 2
.equ "ADEN", 7
.equ "ADSC", 6
.equ "ADATE", 5
.equ "ADIF", 4
.equ "ADIE", 3
.equ "ADLAR", 5
.equ "EERIE", 3
.equ "EEMWE", 2
.equ "EEWE", 1
.equ "EERE", 0
.equ "SPM_PAGESIZE", 128
.equ "RAMSTART", (0x60)
.equ "RAMEND", 0x85F
.equ "XRAMEND", 0x85F
.equ "FLASHEND", 0x7FFF
.equ "FUSE_MEMORY_SIZE", 2
.equ "TCCR2", ((0x25) + 0x20)
.equ "TCNT2", ((0x24) + 0x20)

.equ "SREG", ((0x3F) + 0x20)
.equ "IOSREG", ((((0x3F) + 0x20)) - 0x20)


.equ "IOSPL", ((((0x3D) + 0x20)) - 0x20)
.equ "IOSPH", ((((0x3E) + 0x20)) - 0x20)
.equ "IOPORTD", ((((0x12) + 0x20)) - 0x20)
.equ "IOPORTB", ((((0x18) + 0x20)) - 0x20)
.equ "IOPORTC", ((((0x15) + 0x20)) - 0x20)
.equ "IOPORTA", ((((0x1B) + 0x20)) - 0x20)
.equ "IOPINB", ((((0x16) + 0x20)) - 0x20)
.equ "IODDRD", ((((0x11) + 0x20)) - 0x20)
.equ "IODDRB", ((((0x17) + 0x20)) - 0x20)
.equ "IOADMUX", ((((0x07) + 0x20)) - 0x20)
.equ "IOADCSRA", ((((0x06) + 0x20)) - 0x20)
.equ "IOTCCR2", ((((0x25) + 0x20)) - 0x20)
.equ "IOTCNT2", ((((0x24) + 0x20)) - 0x20)
.equ "IOOCR2", ((((0x23) + 0x20)) - 0x20)

; bits for ((0x25) + 0x20) atmega32
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
