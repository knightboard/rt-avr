### RT-AVR

This is a very simple RTOS written is assembly. It supports basic task
scheduling without context switching. I take it from DI HALT
tutorial (see link below) with some modifications, adopt it for gcc
toolchain. Now it works only for ATMEGA32, probably works with others
MCU, but not tested. Internally, it implemented with simple task
queue, and timer list. Project also has example of usage this rtos, it
linking on build with this example.
Intended for use in small projects and for learning purposes and other\
stuff :)


#### API

- `RT_Init` - Initializes memory and timer.

- `RT_Process` - Starts processing event loop

- `RT_TimerInterrupt`
  This procedure must be invoked from timer interrupt vector,
  it must be invoked with period of 1 ms for properly timings.

- `RT_TaskProcs` 
  Pointer to table of task procedure addresses (16 bit address).
  Each task refers by task number, it means offset in table of procs. 
  Task with  number 0 is idle task, it invoked when no task in queue.

- `RT_SendTask` (macro `RT_TASK`) 
  Puts task by task number into queue

- `RT_SetTimer` (macro `RT_TIMER`) 
  Puts task into scheduler (used task number and
  waiting time in ms up to 65535 ms)


#### Links

AVR DI HALT's tutorial: 
http://easyelectronics.ru/avr-uchebnyj-kurs-operacionnaya-sistema-vvedenie.html

Template makefile:
https://gist.github.com/bradfordbarr/9182992
