
/* 
.equ Counter , R16				; Счетчик (преимущественно используется для организации циклов)			;
.equ OSRG , R17
.equ Tmp2 , R18					;
.equ Tmp3 , R19					;
.equ Tmp4 , R20					; Некоторые переменные общего назначения

.equ MainClock 		, 8000000				; CPU Clock
.equ TimerDivider 	, MainClock/64/1000 	; 1 mS
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
InitRtos:
		rcall ClearTimers		; Очистить список таймеров РТОС
		rcall ClearTaskQueue	; Очистить очередь событий РТОС

		; Init Timer 2
		; Основной таймер для ядра РТОС

		ldi OSRG,1<<WGM21|4<<CS20	; Freq = CK/64 - Установить режим и предделитель
		out IOTCCR2, OSRG				; Автосброс после достижения регистра сравнения

		clr OSRG					; Установить начальное значение счётчиков
		out IOTCNT2, OSRG				;	

		ldi OSRG, lo8(TimerDivider)
		out IOOCR2, OSRG				; Установить значение в регистр сравнения
		sei						; Разрешить обработку прерываний
		ret

StartRtos:

		# wdr
		rcall ProcessTaskQueue
		rjmp StartRtos

TimerInterrupt:
			push 	OSRG
			in 		OSRG, IOSREG		; Save Sreg
			push 	OSRG				; Сохранение регистра OSRG и регистра состояния SREG

			push 	ZL	
			push 	ZH					; сохранение Регистра Z
			push 	Counter				; сохранение Регистра Counter
	
			ldi 	ZL, lo8(TimersPool)	; Загрузка с регистр Z адреса RAM, 
			ldi 	ZH, hi8(TimersPool) ; по которому находится информация о таймерах

			ldi 	Counter, TimersPoolSize ; максимальное количество таймеров
	
.LComp1L01:	ld 		OSRG, Z				; OSRG = [Z] ; Получить номер события
			cpi 	OSRG, 0xFF			; Проверить на "NOP"
			breq 	.LComp1L03			; Если NOP то переход к следующей позиции

			clt							; Флаг T используется для сохранения информации об окончании счёта
			ldd 	OSRG, Z+1			; 
			subi 	OSRG, lo8(1) 		; Уменьшение младшей части счётчика на 1
			std 	Z+1, OSRG			;
			breq 	.LComp1L02			; Если 0 то флаг T не устанавливаем
			set							; 

.LComp1L02:	ldd 	OSRG, Z+2			;
			sbci 	OSRG, hi8(1) 		; Уменьшение старшей части счётчика на 1
			std 	Z+2, OSRG			;
			brne 	.LComp1L03			; Счёт не окончен
			brts 	.LComp1L03			; Счёт не окончен (по T)	
	
			ld 		OSRG, Z				; Получить номер события
			rcall 	SendTask			; послать в системную очередь задач
	
			ldi 	OSRG, 0xFF			; = NOP (задача выполнена, таймер самоудаляется)
			st 		Z, OSRG				; Clear Event

.LComp1L03:	subi 	ZL, lo8(-3)			; Skip Counter
			sbci 	ZH, hi8(-3)			; Z+=3 - переход к следующему таймеру
			dec 	Counter				; счетчик таймеров
			brne 	.LComp1L01			; Loop	

			pop 	Counter				; восстанавливаем переменные
			pop 	ZH
			pop 	ZL

			pop 	OSRG				; Восстанавливаем регистры
			out 	IOSREG, OSRG			; 
			pop 	OSRG
			reti


ClearTaskQueue:
		push 	ZL
		push 	ZH

		ldi 	ZL, lo8(TaskQueue)
		ldi 	ZH, hi8(TaskQueue)

		ldi 	OSRG, 0xFF		
		ldi 	Counter, TaskQueueSize

.LCEQL01: st 		Z+, OSRG		;
		dec 	Counter		;
		brne 	.LCEQL01		; Loop

		pop 	ZH
		pop 	ZL
		ret
	
ClearTimers:
		push 	ZL
		push 	ZH

		ldi 	ZL, lo8(TimersPool)
		ldi 	ZH, hi8(TimersPool)

		ldi 	Counter, TimersPoolSize
		ldi 	OSRG, 0xFF		; Empty 
		ldi 	Tmp2, 0x00

.LCTL01:	st 		Z+, OSRG		; Event
		st 		Z+, Tmp2		; Counter Lo
		st 		Z+, Tmp2		; Counter Hi

		dec 	Counter		;
		brne 	.LCTL01		; Loop
	
		pop 	ZH
		pop 	ZL
		ret	
;------------------------------------------------------------------------------




ProcessTaskQueue:
		ldi 	ZL, lo8(TaskQueue)
		ldi 	ZH, hi8(TaskQueue)

		ld 		OSRG, Z		; For Event
		cpi 	OSRG, 0xFF	; No Event or Addr out of Range
		breq 	.LPTQL02		; No Action
	
		clr 	ZH
		lsl 	OSRG
		mov 	ZL, OSRG

		
		ldi 	OSRG, lo8(TaskProcs)
		add 	ZL, OSRG
		ldi		OSRG, hi8(TaskProcs)
		adc		ZH, OSRG 

		;subi 	ZL, lo8(TaskProcs)
		;sbci 	ZH, hi8(TaskProcs) ; Add

	
		lpm					; mov r0 <- CODE[Z]
		mov 	OSRG, r0
		ld 		r0, Z+			; inc Z
		lpm	
		mov 	ZL, OSRG		; Get Addr
		mov 	ZH, r0
	
		push 	ZL
		push 	ZH

; Advance Queue
		ldi 	Counter, TaskQueueSize-1
		ldi 	ZL, lo8(TaskQueue)
		ldi 	ZH, hi8(TaskQueue)
	
		cli
	
.LPTQL01:	ldd 	OSRG, Z+1 		;	Shift Queues
		st 		Z+, OSRG		

		dec 	Counter		
		brne 	.LPTQL01		; Loop
		ldi 	OSRG, 0xFF	
		st 		Z+, OSRG		
	
		sei

		pop 	ZH
		pop 	ZL
		clc
		ror ZH
		ror ZL
		clc
		ijmp 			; Minimize Stack Usage
	
.LPTQL02:	ret	


;-------------------------------------------------------------------------
; OSRG - Event
SendTask:
		push 	ZL
		push 	ZH
		push 	Tmp2
		push 	Counter

		ldi 	ZL,lo8(TaskQueue)
		ldi 	ZH,hi8(TaskQueue)

		ldi 	Counter, TaskQueueSize

SEQL01: ld 		Tmp2, Z+

		cpi 	Tmp2, 0xFF
		breq 	SEQL02

		dec 	Counter		;
		breq 	SEQL03		; Loop
		rjmp 	SEQL01

SEQL02: st 		-Z, OSRG	; Store Task



SEQL03:					; EXIT
		pop 	Counter
		pop 	Tmp2
		pop 	ZH
		pop 	ZL
		ret	
;------------------------------------------------------------------------	
; OSRG - Timer Event
; X - Counter
SetTimer:
		push 	ZL
		push 	ZH
		push 	Tmp2
		push 	Counter

		ldi 	ZL, lo8(TimersPool)
		ldi 	ZH, hi8(TimersPool)

		ldi 	Counter, TimersPoolSize
	
STL01: 	ld 		Tmp2, Z		; Value / Counter
		cp 		Tmp2, OSRG		; Search for Event
		breq 	STL02
	
		subi 	ZL, lo8(-3)	; Skip Counter
		sbci 	ZH, hi8(-3)	; Z+=2

		dec 	Counter		;
		breq 	STL03		; Loop
		rjmp 	STL01
	
STL02:	;cli
		std 	Z+1, XL		; Critical Section
		std 	Z+2, XH		; Update Counter
		;sei				; leave Critical Section
		rjmp	STL06		; Exit
STL03:

		ldi 	ZL, lo8(TimersPool)
		ldi 	ZH, hi8(TimersPool)

		ldi 	Counter, TimersPoolSize
	
STL04:	ld 		Tmp2, Z		; Value / Counter
		cpi 	Tmp2, 0xFF		; Search for Empty Timer
		breq 	STL05
	
		subi 	ZL, lo8(-3)	; Skip Counter
		sbci 	ZH, hi8(-3)	; Z+=2

		dec 	Counter		;
		breq 	STL06		; No Empty Timer
		rjmp 	STL04
	
STL05:	cli
		st 		Z, OSRG		; Set Event 
		std 	Z+1, XL
		std 	Z+2, XH
		sei

STL06:
		pop 	Counter
		pop 	Tmp2
		pop 	ZH
		pop 	ZL
		ret	

