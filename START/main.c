 /******************************************************************************
 *
 * [FILE NAME]: <main.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <04/11/2022>
 *
 * [DESCRIPTION]: <Source file for main function>
 *
 *******************************************************************************/



#include "gpio.h"
#include "interrupt.h"
#include "timer.h"
#include "Button.h"
#include "lcd.h"
#include "keypad.h"
#include "delay.h"
#include "modes.h"




void Timer0A_Handler(void)
{
  uint32 i;  
    
	TIMER0_ICR_R = 1;           // clear the time-out flag of TimerA
    i= TIMER0_ICR_R ;           // Reading the register to force the flag to be cleared
  
	seconds++;
        
        if (seconds == 60 )
        {
          minutes ++ ;
          seconds =0;
          LCD_clearScreen();
        }
}




/************************************************************************************
* Service Name: SysTick_Handler
* Description: SysTick Timer ISR
************************************************************************************/
void SysTick_handler(void)
{
  if (min != 0)
  {
  if (sec == 0 )
  {
    min--;
    sec=60;
  }
  }
	sec--;
  
  if ((sec == 0) && (min == 0))
  {
    NEW_TICK_FLAG=1;
  }
}



int main(void)
{
  Enable_Interrupts();
  GPIO_init();
  Buzzer_init();
  LCD_init();
  Buttom_Init();
  keypad_init();
  
  while (1)
  {
    modes();
  }
}


