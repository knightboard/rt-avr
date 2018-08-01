.equ MCU, ATMEGA16
IO_REG "TWBR", 0x00

IO_REG "TWSR", 0x01
.equ "TWPS0", 0
.equ "TWPS1", 1
.equ "TWS3", 3
.equ "TWS4", 4
.equ "TWS5", 5
.equ "TWS6", 6
.equ "TWS7", 7

IO_REG "TWAR", 0x02
.equ "TWGCE", 0
.equ "TWA0", 1
.equ "TWA1", 2
.equ "TWA2", 3
.equ "TWA3", 4
.equ "TWA4", 5
.equ "TWA5", 6
.equ "TWA6", 7

IO_REG "TWDR", 0x03

IO_REG "ADCW", 0x04
IO_REG "ADCL", 0x04
IO_REG "ADCH", 0x05

IO_REG "ADCSRA", 0x06
.equ "ADPS0", 0
.equ "ADPS1", 1
.equ "ADPS2", 2
.equ "ADIE", 3
.equ "ADIF", 4
.equ "ADATE", 5
.equ "ADSC", 6
.equ "ADEN", 7

IO_REG "ADMUX", 0x07
.equ "MUX0", 0
.equ "MUX1", 1
.equ "MUX2", 2
.equ "MUX3", 3
.equ "MUX4", 4
.equ "ADLAR", 5
.equ "REFS0", 6
.equ "REFS1", 7

IO_REG "ACSR", 0x08
.equ "ACIS0", 0
.equ "ACIS1", 1
.equ "ACIC", 2
.equ "ACIE", 3
.equ "ACI", 4
.equ "ACO", 5
.equ "ACBG", 6
.equ "ACD", 7

IO_REG "UBRRL", 0x09

IO_REG "UCSRB", 0x0A
.equ "TXB8", 0
.equ "RXB8", 1
.equ "UCSZ2", 2
.equ "TXEN", 3
.equ "RXEN", 4
.equ "UDRIE", 5
.equ "TXCIE", 6
.equ "RXCIE", 7

IO_REG "UCSRA", 0x0B
.equ "MPCM", 0
.equ "U2X", 1
.equ "PE", 2
.equ "DOR", 3
.equ "FE", 4
.equ "UDRE", 5
.equ "TXC", 6
.equ "RXC", 7

IO_REG "UDR", 0x0C

IO_REG "SPCR", 0x0D
.equ "SPR0", 0
.equ "SPR1", 1
.equ "CPHA", 2
.equ "CPOL", 3
.equ "MSTR", 4
.equ "DORD", 5
.equ "SPE", 6
.equ "SPIE", 7

IO_REG "SPSR", 0x0E
.equ "SPI2X", 0
.equ "WCOL", 6
.equ "SPIF", 7

IO_REG "SPDR", 0x0F

IO_REG "PIND", 0x10
.equ "PIND0", 0
.equ "PIND1", 1
.equ "PIND2", 2
.equ "PIND3", 3
.equ "PIND4", 4
.equ "PIND5", 5
.equ "PIND6", 6
.equ "PIND7", 7

IO_REG "DDRD", 0x11
.equ "DDD0", 0
.equ "DDD1", 1
.equ "DDD2", 2
.equ "DDD3", 3
.equ "DDD4", 4
.equ "DDD5", 5
.equ "DDD6", 6
.equ "DDD7", 7

IO_REG "PORTD", 0x12
.equ "PD0", 0
.equ "PD1", 1
.equ "PD2", 2
.equ "PD3", 3
.equ "PD4", 4
.equ "PD5", 5
.equ "PD6", 6
.equ "PD7", 7

IO_REG "PINC", 0x13
.equ "PINC0", 0
.equ "PINC1", 1
.equ "PINC2", 2
.equ "PINC3", 3
.equ "PINC4", 4
.equ "PINC5", 5
.equ "PINC6", 6
.equ "PINC7", 7

IO_REG "DDRC", 0x14
.equ "DDC0", 0
.equ "DDC1", 1
.equ "DDC2", 2
.equ "DDC3", 3
.equ "DDC4", 4
.equ "DDC5", 5
.equ "DDC6", 6
.equ "DDC7", 7

IO_REG "PORTC", 0x15
.equ "PC0", 0
.equ "PC1", 1
.equ "PC2", 2
.equ "PC3", 3
.equ "PC4", 4
.equ "PC5", 5
.equ "PC6", 6
.equ "PC7", 7

IO_REG "PINB", 0x16
.equ "PINB0", 0
.equ "PINB1", 1
.equ "PINB2", 2
.equ "PINB3", 3
.equ "PINB4", 4
.equ "PINB5", 5
.equ "PINB6", 6
.equ "PINB7", 7

IO_REG "DDRB", 0x17
.equ "DDB0", 0
.equ "DDB1", 1
.equ "DDB2", 2
.equ "DDB3", 3
.equ "DDB4", 4
.equ "DDB5", 5
.equ "DDB6", 6
.equ "DDB7", 7

IO_REG "PORTB", 0x18
.equ "PB0", 0
.equ "PB1", 1
.equ "PB2", 2
.equ "PB3", 3
.equ "PB4", 4
.equ "PB5", 5
.equ "PB6", 6
.equ "PB7", 7

IO_REG "PINA", 0x19
.equ "PINA0", 0
.equ "PINA1", 1
.equ "PINA2", 2
.equ "PINA3", 3
.equ "PINA4", 4
.equ "PINA5", 5
.equ "PINA6", 6
.equ "PINA7", 7

IO_REG "DDRA", 0x1A
.equ "DDA0", 0
.equ "DDA1", 1
.equ "DDA2", 2
.equ "DDA3", 3
.equ "DDA4", 4
.equ "DDA5", 5
.equ "DDA6", 6
.equ "DDA7", 7

IO_REG "PORTA", 0x1B
.equ "PA0", 0
.equ "PA1", 1
.equ "PA2", 2
.equ "PA3", 3
.equ "PA4", 4
.equ "PA5", 5
.equ "PA6", 6
.equ "PA7", 7

/* EEPROM Control Register */
IO_REG "EECR", 0x1C
.equ "EERE", 0
.equ "EEWE", 1
.equ "EEMWE", 2
.equ "EERIE", 3

/* EEPROM Data Register */
IO_REG "EEDR", 0x1D

/* EEPROM Address Register */
IO_REG "EEAR", 0x1E
IO_REG "EEARL", 0x1E
IO_REG "EEARH", 0x1F

IO_REG "UCSRC", 0x20
.equ "UCPOL", 0
.equ "UCSZ0", 1
.equ "UCSZ1", 2
.equ "USBS", 3
.equ "UPM0", 4
.equ "UPM1", 5
.equ "UMSEL", 6
.equ "URSEL", 7

IO_REG "UBRRH", 0x20
.equ "URSEL", 7

IO_REG "WDTCR", 0x21
.equ "WDP0", 0
.equ "WDP1", 1
.equ "WDP2", 2
.equ "WDE", 3
.equ "WDTOE", 4

IO_REG "ASSR", 0x22
.equ "TCR2UB", 0
.equ "OCR2UB", 1
.equ "TCN2UB", 2
.equ "AS2", 3

IO_REG "OCR2", 0x23

IO_REG "TCNT2", 0x24

IO_REG "TCCR2", 0x25
.equ "CS20", 0
.equ "CS21", 1
.equ "CS22", 2
.equ "WGM21", 3
.equ "COM20", 4
.equ "COM21", 5
.equ "WGM20", 6
.equ "FOC2", 7

/* Combine ICR1L and ICR1H */
IO_REG "ICR1", 0x26

IO_REG "ICR1L", 0x26
IO_REG "ICR1H", 0x27

/* Combine OCR1BL and OCR1BH */
IO_REG "OCR1B", 0x28

IO_REG "OCR1BL", 0x28
IO_REG "OCR1BH", 0x29

/* Combine OCR1AL and OCR1AH */
IO_REG "OCR1A", 0x2A

IO_REG "OCR1AL", 0x2A
IO_REG "OCR1AH", 0x2B

/* Combine TCNT1L and TCNT1H */
IO_REG "TCNT1", 0x2C

IO_REG "TCNT1L", 0x2C
IO_REG "TCNT1H", 0x2D

IO_REG "TCCR1B", 0x2E
.equ "CS10", 0
.equ "CS11", 1
.equ "CS12", 2
.equ "WGM12", 3
.equ "WGM13", 4
.equ "ICES1", 6
.equ "ICNC1", 7

IO_REG "TCCR1A", 0x2F
.equ "WGM10", 0
.equ "WGM11", 1
.equ "FOC1B", 2
.equ "FOC1A", 3
.equ "COM1B0", 4
.equ "COM1B1", 5
.equ "COM1A0", 6
.equ "COM1A1", 7

/* 
   The ADHSM bit has been removed from all documentation, 
   as being not needed at all since the comparator has proven 
   to be fast enough even without feeding it more power.
*/

IO_REG "SFIOR", 0x30
.equ "PSR10", 0
.equ "PSR2", 1
.equ "PUD", 2
.equ "ACME", 3
.equ "ADTS0", 5
.equ "ADTS1", 6
.equ "ADTS2", 7

IO_REG "OSCCAL", 0x31

IO_REG "OCDR", 0x31

IO_REG "TCNT0", 0x32

IO_REG "TCCR0", 0x33
.equ "CS00", 0
.equ "CS01", 1
.equ "CS02", 2
.equ "WGM01", 3
.equ "COM00", 4
.equ "COM01", 5
.equ "WGM00", 6
.equ "FOC0", 7

IO_REG "MCUCSR", 0x34
.equ "PORF", 0
.equ "EXTRF", 1
.equ "BORF", 2
.equ "WDRF", 3
.equ "JTRF", 4
.equ "ISC2", 6
.equ "JTD", 7

IO_REG "MCUCR", 0x35
.equ "ISC00", 0
.equ "ISC01", 1
.equ "ISC10", 2
.equ "ISC11", 3
.equ "SM0", 4
.equ "SM1", 5
.equ "SE", 6
.equ "SM2", 7

IO_REG "TWCR", 0x36
.equ "TWIE", 0
.equ "TWEN", 2
.equ "TWWC", 3
.equ "TWSTO", 4
.equ "TWSTA", 5
.equ "TWEA", 6
.equ "TWINT", 7

IO_REG "SPMCR", 0x37
.equ "SPMEN", 0
.equ "PGERS", 1
.equ "PGWRT", 2
.equ "BLBSET", 3
.equ "RWWSRE", 4
.equ "RWWSB", 6
.equ "SPMIE", 7

IO_REG "TIFR", 0x38
.equ "TOV0", 0
.equ "OCF0", 1
.equ "TOV1", 2
.equ "OCF1B", 3
.equ "OCF1A", 4
.equ "ICF1", 5
.equ "TOV2", 6
.equ "OCF2", 7

IO_REG "TIMSK", 0x39
.equ "TOIE0", 0
.equ "OCIE0", 1
.equ "TOIE1", 2
.equ "OCIE1B", 3
.equ "OCIE1A", 4
.equ "TICIE1", 5
.equ "TOIE2", 6
.equ "OCIE2", 7

IO_REG "GIFR", 0x3A
.equ "INTF2", 5
.equ "INTF0", 6
.equ "INTF1", 7

IO_REG "GICR", 0x3B
.equ "IVCE", 0
.equ "IVSEL", 1
.equ "INT2", 5
.equ "INT0", 6
.equ "INT1", 7

IO_REG "OCR0", 0x3C

/* SP [0x3D..0x3E] */
/* SREG [0x3F] */



/* Constants */
.equ "SPM_PAGESIZE", 128
.equ "RAMSTART", 0x60
.equ "RAMEND", 0x45F
.equ "XRAMEND", RAMEND
.equ "E2END", 0x1FF
.equ "E2PAGESIZE", 4
.equ "FLASHEND", 0x3FFF
.equ "VECTORS_SIZE", 84

/* Signature */
.equ "SIGNATURE_0", 0x1E
.equ "SIGNATURE_1", 0x94
.equ "SIGNATURE_2", 0x03

.equ "SLEEP_MODE_IDLE", (0x00<<4)
.equ "SLEEP_MODE_ADC", (0x01<<4)
.equ "SLEEP_MODE_PWR_DOWN", (0x02<<4)
.equ "SLEEP_MODE_PWR_SAVE", (0x03<<4)
.equ "SLEEP_MODE_STANDBY", (0x0A<<4)
.equ "SLEEP_MODE_EXT_STANDBY", (0x0B<<4)
