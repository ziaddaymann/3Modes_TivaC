#include "gpio.h"
#include "interrupt.h"
#include "timer.h"
#include "Button.h"
#include "lcd.h"
#include "keypad.h"
#include "delay.h"
#include "modes.h"


/************************************************************************************
* Service Name: buttom_Handler
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
************************************************************************************/
void Buttom_Handler(void)
{
  
  uint16 state=0;
  if(GPIO_PORTF_RIS_REG)
  {
   if(GPIO_PORTF_RIS_REG)
   {
   state = GPIO_PORTF_RIS_REG & 0x31 ;
   }
  }
 if(state==0x01)
 {
  
   if (state_flag == 0)
   {
     CalcMode();
   }
   
   
 else if(state_flag == 1)
  {
    TimerMode();
  }
  
  else if (state_flag == 2)
  {
    StopWatchMode();
  }
  
  else if (state_flag == 3)
  {
    if (flag == 0)
    {
    start();
    }
    else if (flag == 1)
    {
      CalcMode();
    }
  }
 }
 
 if(state==0x10)
 {
   if (state_flag == 3)
   {
     if (flag == 1)
     {
     pause();
     }
   }
 }
 
 if(state==0x20)
 {
   if (state_flag == 3)
   {
     if (flag == 2)
     {
     reset();
     }
   }
 }
 
 
   GPIO_PORTF_ICR_REG   |= (1<<0); 
   GPIO_PORTF_ICR_REG   |= (1<<4);
}


int main(void)
{
  Enable_Interrupts();
  GPIO_init();
  Buzzer_init();
  LCD_init();
  Buttom_Init();
  
  while (1)
  {
    Wait_For_Interrupt();
  }
}


