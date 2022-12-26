 /******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: timer.c
 *
 * Description: Source file for the ARM timer driver
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/





#include "timer.h"
#include "tm4c123gh6pm_registers.h"
#include "tm4c123gh6pm.h"
#include "modes.h"





/************************************************************************************
* Service Name: TIMER_Start
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the Timer configuration to count n miliseconds:
************************************************************************************/
void TIMER_Start(void)
{
  SYSCTL_RCGCTIMER_R = 0x1;      // Enable the clock of Timer0
  TIMER0_CTL_R  = 0;             // Disable Timer0 before Configuration
  TIMER0_CFG_R  = (1<<2) ;       // Configure Timer0 to be in 16-bits : (1<<2)
  TIMER0_TAMR_R = (1<<2);        // Periodic mode:(1<<2) 
  TIMER0_TAPR_R = 250;           // 16 MHz/ 250 = 64000 Hz
  TIMER0_TAILR_R = 64000;       // Load the interval load register by 64000 to get 1 Hz
  TIMER0_ICR_R = 1;              // clear the time-out flag of TimerA
  TIMER0_IMR_R = 1;              // Enable the time-out interrupt of TimerA
  NVIC_PRI4_R |=0x80000000;
  NVIC_EN0_R = 1<<19; 
  TIMER0_CTL_R  = 1;             // Enable Timer0 after Configuration
}

/************************************************************************************
* Service Name: TIMER_Stop
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Stop the Timer.
************************************************************************************/
void TIMER_Stop(void)
{
    TIMER0_CTL_R = 0; /* Disable the SysTick Timer by Clear the ENABLE Bit */
}

