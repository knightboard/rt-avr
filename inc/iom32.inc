.equ MCU, ATMEGA32
/* I/O registers */

/* TWI stands for "Two Wire Interface" or "TWI Was I2C(tm)" */
IO_REG "TWBR", 0x00
IO_REG "TWSR", 0x01
IO_REG "TWAR", 0x02
IO_REG "TWDR", 0x03

/* ADC */
IO_REG "ADCW", 0x04
IO_REG "ADCL", 0x04
IO_REG "ADCH", 0x05
IO_REG "ADCSRA", 0x06
IO_REG "ADMUX", 0x07

/* analog comparator */
IO_REG "ACSR", 0x08

/* USART */
IO_REG "UBRRL", 0x09
IO_REG "UCSRB", 0x0A
IO_REG "UCSRA", 0x0B
IO_REG "UDR", 0x0C

/* SPI */
IO_REG "SPCR", 0x0D
IO_REG "SPSR", 0x0E
IO_REG "SPDR", 0x0F

/* Port D */
IO_REG "PIND", 0x10
IO_REG "DDRD", 0x11
IO_REG "PORTD", 0x12

/* Port C */
IO_REG "PINC", 0x13
IO_REG "DDRC", 0x14
IO_REG "PORTC", 0x15

/* Port B */
IO_REG "PINB", 0x16
IO_REG "DDRB", 0x17
IO_REG "PORTB", 0x18

/* Port A */
IO_REG "PINA", 0x19
IO_REG "DDRA", 0x1A
IO_REG "PORTA", 0x1B

/* EEPROM Control Register */
IO_REG "EECR", 0x1C

/* EEPROM Data Register */
IO_REG "EEDR", 0x1D

/* EEPROM Address Register */
IO_REG "EEAR", 0x1E
IO_REG "EEARL", 0x1E
IO_REG "EEARH", 0x1F

IO_REG "UBRRH", 0x20
IO_REG "UCSRC", UBRRH

IO_REG "WDTCR", 0x21

IO_REG "ASSR", 0x22

/* Timer 2 */
IO_REG "OCR2", 0x23
IO_REG "TCNT2", 0x24
IO_REG "TCCR2", 0x25

/* Timer 1 */
IO_REG "ICR1", 0x26
IO_REG "ICR1L", 0x26
IO_REG "ICR1H", 0x27
IO_REG "OCR1B", 0x28
IO_REG "OCR1BL", 0x28
IO_REG "OCR1BH", 0x29
IO_REG "OCR1A", 0x2A
IO_REG "OCR1AL", 0x2A
IO_REG "OCR1AH", 0x2B
IO_REG "TCNT1", 0x2C
IO_REG "TCNT1L", 0x2C
IO_REG "TCNT1H", 0x2D
IO_REG "TCCR1B", 0x2E
IO_REG "TCCR1A", 0x2F

IO_REG "SFIOR", 0x30

IO_REG "OSCCAL", 0x31
IO_REG "OCDR", OSCCAL

/* Timer 0 */
IO_REG "TCNT0", 0x32
IO_REG "TCCR0", 0x33

IO_REG "MCUSR", 0x34
IO_REG "MCUCSR", MCUSR
IO_REG "MCUCR", 0x35

IO_REG "TWCR", 0x36

IO_REG "SPMCR", 0x37

IO_REG "TIFR", 0x38
IO_REG "TIMSK", 0x39

IO_REG "GIFR", 0x3A
IO_REG "GIMSK", 0x3B
IO_REG "GICR", GIMSK

IO_REG "OCR0", 0x3C

/* 0x3D..0x3E SP */

/* 0x3F SREG */



/* Bit numbers */

/* GICR */
.equ "INT1", 7
.equ "INT0", 6
.equ "INT2", 5
.equ "IVSEL", 1
.equ "IVCE", 0

/* GIFR */
.equ "INTF1", 7
.equ "INTF0", 6
.equ "INTF2", 5

/* TIMSK */
.equ "OCIE2", 7
.equ "TOIE2", 6
.equ "TICIE1", 5
.equ "OCIE1A", 4
.equ "OCIE1B", 3
.equ "TOIE1", 2
.equ "OCIE0", 1
.equ "TOIE0", 0

/* TIFR */
.equ "OCF2", 7
.equ "TOV2", 6
.equ "ICF1", 5
.equ "OCF1A", 4
.equ "OCF1B", 3
.equ "TOV1", 2
.equ "OCF0", 1
.equ "TOV0", 0

/* SPMCR */
.equ "SPMIE", 7
.equ "RWWSB", 6
/* bit 5 reserved */
.equ "RWWSRE", 4
.equ "BLBSET", 3
.equ "PGWRT", 2
.equ "PGERS", 1
.equ "SPMEN", 0

/* TWCR */
.equ "TWINT", 7
.equ "TWEA", 6
.equ "TWSTA", 5
.equ "TWSTO", 4
.equ "TWWC", 3
.equ "TWEN", 2
/* bit 1 reserved */
.equ "TWIE", 0

/* TWAR */
.equ "TWA6", 7
.equ "TWA5", 6
.equ "TWA4", 5
.equ "TWA3", 4
.equ "TWA2", 3
.equ "TWA1", 2
.equ "TWA0", 1
.equ "TWGCE", 0

/* TWSR */
.equ "TWS7", 7
.equ "TWS6", 6
.equ "TWS5", 5
.equ "TWS4", 4
.equ "TWS3", 3
/* bit 2 reserved */
.equ "TWPS1", 1
.equ "TWPS0", 0

/* MCUCR */
.equ "SE", 7
.equ "SM2", 6
.equ "SM1", 5
.equ "SM0", 4
.equ "ISC11", 3
.equ "ISC10", 2
.equ "ISC01", 1
.equ "ISC00", 0

/* MCUCSR */
.equ "JTD", 7
.equ "ISC2", 6
/* bit 5 reserved */
.equ "JTRF", 4
.equ "WDRF", 3
.equ "BORF", 2
.equ "EXTRF", 1
.equ "PORF", 0

/* SFIOR */
.equ "ADTS2", 7
.equ "ADTS1", 6
.equ "ADTS0", 5
/* bit 4 reserved */
.equ "ACME", 3
.equ "PUD", 2
.equ "PSR2", 1
.equ "PSR10", 0

/* TCCR0 */
.equ "FOC0", 7
.equ "WGM00", 6
.equ "COM01", 5
.equ "COM00", 4
.equ "WGM01", 3
.equ "CS02", 2
.equ "CS01", 1
.equ "CS00", 0

/* TCCR2 */
.equ "FOC2", 7
.equ "WGM20", 6
.equ "COM21", 5
.equ "COM20", 4
.equ "WGM21", 3
.equ "CS22", 2
.equ "CS21", 1
.equ "CS20", 0

/* ASSR */
/* bits 7-4 reserved */
.equ "AS2", 3
.equ "TCN2UB", 2
.equ "OCR2UB", 1
.equ "TCR2UB", 0

/* TCCR1A */
.equ "COM1A1", 7
.equ "COM1A0", 6
.equ "COM1B1", 5
.equ "COM1B0", 4
.equ "FOC1A", 3
.equ "FOC1B", 2
.equ "WGM11", 1
.equ "WGM10", 0

/* TCCR1B */
.equ "ICNC1", 7
.equ "ICES1", 6
/* bit 5 reserved */
.equ "WGM13", 4
.equ "WGM12", 3
.equ "CS12", 2
.equ "CS11", 1
.equ "CS10", 0

/* WDTCR */
/* bits 7-5 reserved */
.equ "WDTOE", 4
.equ "WDE", 3
.equ "WDP2", 2
.equ "WDP1", 1
.equ "WDP0", 0

/* PA7-PA0 = ADC7-ADC0 */
/* PORTA */
.equ "PA7", 7
.equ "PA6", 6
.equ "PA5", 5
.equ "PA4", 4
.equ "PA3", 3
.equ "PA2", 2
.equ "PA1", 1
.equ "PA0", 0

/* DDRA */
.equ "DDA7", 7
.equ "DDA6", 6
.equ "DDA5", 5
.equ "DDA4", 4
.equ "DDA3", 3
.equ "DDA2", 2
.equ "DDA1", 1
.equ "DDA0", 0

/* PINA */
.equ "PINA7", 7
.equ "PINA6", 6
.equ "PINA5", 5
.equ "PINA4", 4
.equ "PINA3", 3
.equ "PINA2", 2
.equ "PINA1", 1
.equ "PINA0", 0

/*
   PB7 = SCK
   PB6 = MISO
   PB5 = MOSI
   PB4 = SS#
   PB3 = OC0/AIN1
   PB2 = INT2/AIN0
   PB1 = T1
   PB0 = XCK/T0
 */

/* PORTB */
.equ "PB7", 7
.equ "PB6", 6
.equ "PB5", 5
.equ "PB4", 4
.equ "PB3", 3
.equ "PB2", 2
.equ "PB1", 1
.equ "PB0", 0

/* DDRB */
.equ "DDB7", 7
.equ "DDB6", 6
.equ "DDB5", 5
.equ "DDB4", 4
.equ "DDB3", 3
.equ "DDB2", 2
.equ "DDB1", 1
.equ "DDB0", 0

/* PINB */
.equ "PINB7", 7
.equ "PINB6", 6
.equ "PINB5", 5
.equ "PINB4", 4
.equ "PINB3", 3
.equ "PINB2", 2
.equ "PINB1", 1
.equ "PINB0", 0

/*
   PC7 = TOSC2
   PC6 = TOSC1
   PC1 = SDA
   PC0 = SCL
 */
/* PORTC */
.equ "PC7", 7
.equ "PC6", 6
.equ "PC5", 5
.equ "PC4", 4
.equ "PC3", 3
.equ "PC2", 2
.equ "PC1", 1
.equ "PC0", 0

/* DDRC */
.equ "DDC7", 7
.equ "DDC6", 6
.equ "DDC5", 5
.equ "DDC4", 4
.equ "DDC3", 3
.equ "DDC2", 2
.equ "DDC1", 1
.equ "DDC0", 0

/* PINC */
.equ "PINC7", 7
.equ "PINC6", 6
.equ "PINC5", 5
.equ "PINC4", 4
.equ "PINC3", 3
.equ "PINC2", 2
.equ "PINC1", 1
.equ "PINC0", 0

/*
   PD7 = OC2
   PD6 = ICP
   PD5 = OC1A
   PD4 = OC1B
   PD3 = INT1
   PD2 = INT0
   PD1 = TXD
   PD0 = RXD
 */

/* PORTD */
.equ "PD7", 7
.equ "PD6", 6
.equ "PD5", 5
.equ "PD4", 4
.equ "PD3", 3
.equ "PD2", 2
.equ "PD1", 1
.equ "PD0", 0

/* DDRD */
.equ "DDD7", 7
.equ "DDD6", 6
.equ "DDD5", 5
.equ "DDD4", 4
.equ "DDD3", 3
.equ "DDD2", 2
.equ "DDD1", 1
.equ "DDD0", 0

/* PIND */
.equ "PIND7", 7
.equ "PIND6", 6
.equ "PIND5", 5
.equ "PIND4", 4
.equ "PIND3", 3
.equ "PIND2", 2
.equ "PIND1", 1
.equ "PIND0", 0

/* SPSR */
.equ "SPIF", 7
.equ "WCOL", 6
/* bits 5-1 reserved */
.equ "SPI2X", 0

/* SPCR */
.equ "SPIE", 7
.equ "SPE", 6
.equ "DORD", 5
.equ "MSTR", 4
.equ "CPOL", 3
.equ "CPHA", 2
.equ "SPR1", 1
.equ "SPR0", 0

/* UCSRA */
.equ "RXC", 7
.equ "TXC", 6
.equ "UDRE", 5
.equ "FE", 4
.equ "DOR", 3
.equ "PE", 2
.equ "U2X", 1
.equ "MPCM", 0

/* UCSRB */
.equ "RXCIE", 7
.equ "TXCIE", 6
.equ "UDRIE", 5
.equ "RXEN", 4
.equ "TXEN", 3
.equ "UCSZ2", 2
.equ "RXB8", 1
.equ "TXB8", 0

/* UCSRC */
.equ "URSEL", 7
.equ "UMSEL", 6
.equ "UPM1", 5
.equ "UPM0", 4
.equ "USBS", 3
.equ "UCSZ1", 2
.equ "UCSZ0", 1
.equ "UCPOL", 0

/* ACSR */
.equ "ACD", 7
.equ "ACBG", 6
.equ "ACO", 5
.equ "ACI", 4
.equ "ACIE", 3
.equ "ACIC", 2
.equ "ACIS1", 1
.equ "ACIS0", 0

/* ADCSRA */
.equ "ADEN", 7
.equ "ADSC", 6
.equ "ADATE", 5
.equ "ADIF", 4
.equ "ADIE", 3
.equ "ADPS2", 2
.equ "ADPS1", 1
.equ "ADPS0", 0

/* ADMUX */
.equ "REFS1", 7
.equ "REFS0", 6
.equ "ADLAR", 5
.equ "MUX4", 4
.equ "MUX3", 3
.equ "MUX2", 2
.equ "MUX1", 1
.equ "MUX0", 0

/* EEPROM Control Register */
.equ "EERIE", 3
.equ "EEMWE", 2
.equ "EEWE", 1
.equ "EERE", 0

/* Constants */
.equ "SPM_PAGESIZE", 128
.equ "RAMSTART", (0x60)
.equ "RAMEND", 0x85F
.equ "XRAMEND", RAMEND
.equ "E2END", 0x3FF
.equ "E2PAGESIZE", 4
.equ "FLASHEND", 0x7FFF
.equ "VECTORS_SIZE", 84

/* Signature */
.equ "SIGNATURE_0", 0x1E
.equ "SIGNATURE_1", 0x95
.equ "SIGNATURE_2", 0x02

.equ "SLEEP_MODE_IDLE", (0x00<<4)
.equ "SLEEP_MODE_ADC", (0x01<<4)
.equ "SLEEP_MODE_PWR_DOWN", (0x02<<4)
.equ "SLEEP_MODE_PWR_SAVE", (0x03<<4)
.equ "SLEEP_MODE_STANDBY", (0x06<<4)
.equ "SLEEP_MODE_EXT_STANDBY", (0x07<<4)
