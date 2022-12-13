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
  SYSCTL_RCGCTIMER_R |= 1;
  TIMER0_CTL_R = 0;
  TIMER0_CFG_R = 0x04;
  TIMER0_TAMR_R = 0x11;
  TIMER0_TAPR_R |= 0xF4;
  TIMER0_TAILR_R = 0xFFFF;
  TIMER0_CTL_R = 0x03;
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


