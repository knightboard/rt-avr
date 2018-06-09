
/* 
EEPROMRead:
ERL01:	sbic	EECR, EEWE	;if EEWE not clear
		rjmp	ERL01		; wait more 

		out		EEARH, ZH	;output address 
		out		EEARL, ZL	;output address 

		sbi		EECR, EERE	;set EEPROM Read strobe
		in		OSRG, EEDR	;get data
		ret
	
EEPROMWrite:
EWL01:	sbic	EECR, EEWE	;if EEWE not clear
		rjmp	EWL01		;    wait more
	
		out		EEARH, ZH	
		out		EEARL, ZL	

		out		EEDR, OSRG	;output data
		sbi		EECR, EEMWE	;set EEPROM Master Write Enable
		sbi		EECR, EEWE	;set EEPROM Write strobe
		ret
*/
.include "avr.inc"
.include "rtos.inc"
.equ Counter , R16				; Счетчик (преимущественно используется для организации циклов)			;
#.equ OSRG , R17
.equ Tmp2 , R18					;
.equ Tmp3 , R19					;
.equ Tmp4 , R20					; Некоторые переменные общего назначения
.section .data

RT_TaskQueue:
	.skip RT_TaskQueueSize
RT_TimersPool:
	.skip RT_TimersPoolSize*3

.section .text
RT_Init:
		rcall RT_ClearTimers		; Очистить список таймеров РТОС
		rcall RT_ClearTaskQueue	; Очистить очередь событий РТОС

		; Init Timer 2
		; Основной таймер для ядра РТОС

		ldi RT_RG,1<<WGM21|4<<CS20	; Freq = CK/64 - Установить режим и предделитель
		out IOTCCR2, RT_RG				; Автосброс после достижения регистра сравнения

		clr RT_RG					; Установить начальное значение счётчиков
		out IOTCNT2, RT_RG				;	

		ldi RT_RG, lo8(RT_TimerDivider)
		out IOOCR2, RT_RG				; Установить значение в регистр сравнения
		sei						; Разрешить обработку прерываний
		ret

RT_Start:

		# wdr
		rcall RT_ProcessTaskQueue
		rjmp RT_Start

RT_TimerInterrupt:
			push 	RT_RG
			in 		RT_RG, IOSREG		; Save Sreg
			push 	RT_RG				; Сохранение регистра RT_RG и регистра состояния SREG

			push 	ZL	
			push 	ZH					; сохранение Регистра Z
			push 	Counter				; сохранение Регистра Counter
	
			ldi 	ZL, lo8(RT_TimersPool)	; Загрузка с регистр Z адреса RAM, 
			ldi 	ZH, hi8(RT_TimersPool) ; по которому находится информация о таймерах

			ldi 	Counter, RT_TimersPoolSize ; максимальное количество таймеров
	
.LComp1L01:	ld 		RT_RG, Z				; RT_RG = [Z] ; Получить номер события
			cpi 	RT_RG, 0xFF			; Проверить на "NOP"
			breq 	.LComp1L03			; Если NOP то переход к следующей позиции

			clt							; Флаг T используется для сохранения информации об окончании счёта
			ldd 	RT_RG, Z+1			; 
			subi 	RT_RG, lo8(1) 		; Уменьшение младшей части счётчика на 1
			std 	Z+1, RT_RG			;
			breq 	.LComp1L02			; Если 0 то флаг T не устанавливаем
			set							; 

.LComp1L02:	ldd 	RT_RG, Z+2			;
			sbci 	RT_RG, hi8(1) 		; Уменьшение старшей части счётчика на 1
			std 	Z+2, RT_RG			;
			brne 	.LComp1L03			; Счёт не окончен
			brts 	.LComp1L03			; Счёт не окончен (по T)	
	
			ld 		RT_RG, Z				; Получить номер события
			rcall 	RT_SendTask			; послать в системную очередь задач
	
			ldi 	RT_RG, 0xFF			; = NOP (задача выполнена, таймер самоудаляется)
			st 		Z, RT_RG				; Clear Event

.LComp1L03:	subi 	ZL, lo8(-3)			; Skip Counter
			sbci 	ZH, hi8(-3)			; Z+=3 - переход к следующему таймеру
			dec 	Counter				; счетчик таймеров
			brne 	.LComp1L01			; Loop	

			pop 	Counter				; восстанавливаем переменные
			pop 	ZH
			pop 	ZL

			pop 	RT_RG				; Восстанавливаем регистры
			out 	IOSREG, RT_RG			; 
			pop 	RT_RG
			reti


RT_ClearTaskQueue:
		push 	ZL
		push 	ZH

		ldi 	ZL, lo8(RT_TaskQueue)
		ldi 	ZH, hi8(RT_TaskQueue)

		ldi 	RT_RG, 0xFF		
		ldi 	Counter, RT_TaskQueueSize

.LCEQL01: 
		st 		Z+, RT_RG		;
		dec 	Counter		;
		brne 	.LCEQL01		; Loop

		pop 	ZH
		pop 	ZL
		ret
	
RT_ClearTimers:
		push 	ZL
		push 	ZH

		ldi 	ZL, lo8(RT_TimersPool)
		ldi 	ZH, hi8(RT_TimersPool)

		ldi 	Counter, RT_TimersPoolSize
		ldi 	RT_RG, 0xFF		; Empty 
		ldi 	Tmp2, 0x00

.LCTL01:	
		st 		Z+, RT_RG		; Event
		st 		Z+, Tmp2		; Counter Lo
		st 		Z+, Tmp2		; Counter Hi

		dec 	Counter		;
		brne 	.LCTL01		; Loop
	
		pop 	ZH
		pop 	ZL
		ret	
;------------------------------------------------------------------------------




RT_ProcessTaskQueue:
		ldi 	ZL, lo8(RT_TaskQueue)
		ldi 	ZH, hi8(RT_TaskQueue)

		ld 		RT_RG, Z		; For Event
		cpi 	RT_RG, 0xFF	; No Event or Addr out of Range
		breq 	.LPTQL02		; No Action
	
		clr 	ZH
		lsl 	RT_RG
		mov 	ZL, RT_RG

		
		ldi 	RT_RG, lo8(RT_TaskProcs)
		add 	ZL, RT_RG
		ldi		RT_RG, hi8(RT_TaskProcs)
		adc		ZH, RT_RG 

		lpm					; mov r0 <- CODE[Z]
		mov 	RT_RG, r0
		ld 		r0, Z+			; inc Z
		lpm	
		mov 	ZL, RT_RG		; Get Addr
		mov 	ZH, r0
	
		push 	ZL
		push 	ZH

; Advance Queue
		ldi 	Counter, RT_TaskQueueSize-1
		ldi 	ZL, lo8(RT_TaskQueue)
		ldi 	ZH, hi8(RT_TaskQueue)
	
		cli
	
.LPTQL01:	
		ldd 	RT_RG, Z+1 		;	Shift Queues
		st 		Z+, RT_RG		

		dec 	Counter		
		brne 	.LPTQL01		; Loop
		ldi 	RT_RG, 0xFF	
		st 		Z+, RT_RG		
	
		sei

		pop 	ZH
		pop 	ZL
		clc
		ror ZH
		ror ZL
		clc
		ijmp 			; Minimize Stack Usage
	
.LPTQL02:	
		ret	


;-------------------------------------------------------------------------
; RT_RG - Event
RT_SendTask:
		push 	ZL
		push 	ZH
		push 	Tmp2
		push 	Counter

		ldi 	ZL,lo8(RT_TaskQueue)
		ldi 	ZH,hi8(RT_TaskQueue)

		ldi 	Counter, RT_TaskQueueSize

.LSEQL01: 
		ld 		Tmp2, Z+

		cpi 	Tmp2, 0xFF
		breq 	.LSEQL02

		dec 	Counter		;
		breq 	.LSEQL03		; Loop
		rjmp 	.LSEQL01

.LSEQL02: 
		st 		-Z, RT_RG	; Store Task



.LSEQL03:					; EXIT
		pop 	Counter
		pop 	Tmp2
		pop 	ZH
		pop 	ZL
		ret	
;------------------------------------------------------------------------	
; RT_RG - Timer Event
; X - Counter
RT_SetTimer:
		push 	ZL
		push 	ZH
		push 	Tmp2
		push 	Counter

		ldi 	ZL, lo8(RT_TimersPool)
		ldi 	ZH, hi8(RT_TimersPool)

		ldi 	Counter, RT_TimersPoolSize
	
.LSTL01: 
		ld 		Tmp2, Z		; Value / Counter
		cp 		Tmp2, RT_RG		; Search for Event
		breq 	.LSTL02
	
		subi 	ZL, lo8(-3)	; Skip Counter
		sbci 	ZH, hi8(-3)	; Z+=2

		dec 	Counter		;
		breq 	.LSTL03		; Loop
		rjmp 	.LSTL01
	
.LSTL02:	;cli
		std 	Z+1, XL		; Critical Section
		std 	Z+2, XH		; Update Counter
		;sei				; leave Critical Section
		rjmp	.LSTL06		; Exit
.LSTL03:

		ldi 	ZL, lo8(RT_TimersPool)
		ldi 	ZH, hi8(RT_TimersPool)

		ldi 	Counter, RT_TimersPoolSize
	
.LSTL04:	
		ld 		Tmp2, Z		; Value / Counter
		cpi 	Tmp2, 0xFF		; Search for Empty Timer
		breq 	.LSTL05
	
		subi 	ZL, lo8(-3)	; Skip Counter
		sbci 	ZH, hi8(-3)	; Z+=2

		dec 	Counter		;
		breq 	.LSTL06		; No Empty Timer
		rjmp 	.LSTL04
	
.LSTL05:	
		cli
		st 		Z, RT_RG		; Set Event 
		std 	Z+1, XL
		std 	Z+2, XH
		sei

.LSTL06:
		pop 	Counter
		pop 	Tmp2
		pop 	ZH
		pop 	ZL
		ret	


	
