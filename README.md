# 3Modes_TivaC
The goal of this project is to design a simple calculator with 2 extra features: a timer and a stopwatch. The calculator shall do the basic operations that are addition, subtraction, multiplication, and division. The timer and stopwatch features will be both handled separately by the hardware.
1. Timers: You will be using at least two timers one for the stopwatch mode and the other for the timer mode. 
2. 2. GPIO: You will be using the LCD and a keypad and some push buttons.
3. Interrupts: You will use interrupts also in this project for the push buttons and timers

In this project We have 3 main Modes. We need to have a keypad for all number inputs. We will need a push button to switch between these 3 modes.
1. Calculator
In this mode We will be asked to take inputs from the user and print that input on the LCD. We will take two numbers (each more than 1 digit) and a sign between them. Use the keypad numbers to get the numbers.
A button: +
B button: -
C button: / 
D button: = 
* button: x
Print the numbers and the sign on the LCD before printing the result.

2. Timer Mode
In this mode the user will set a time using the keypad, the timer will start counting down and as soon as it reaches the time zero it will trigger a buzzer.

3. Stopwatch Mode
In this mode the user will be using three buttons, one to start the stopwatch, one to pause the stopwatch, and one to reset the value back to 00:00.


MicroController : TivaC TM4C123GH6PM

MODULES : GPIO , INTERRUPT , SYSTICK , TIMER
