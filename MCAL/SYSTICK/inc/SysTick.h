   /******************************************************************************
 *
 * [FILE NAME]: <SysTick.h>
 *
 * Author: Ziad Ayman
 *
 * [DATE CREATED]: <18/12/2022>
 *
 * [DESCRIPTION]: <Header file for Systick>
 *
 *******************************************************************************/


#ifndef GPT_H
#define GPT_H

#include "StandardTypes.h"



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/



/************************************************************************************
* Service Name: SysTick_Start
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Tick_Time - Time in miliseconds
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the SysTick Timer configuration to count n miliseconds:
*              - Set the Reload value
*              - Enable SysTick Timer with System clock 16Mhz
*              - Enable SysTick Timer Interrupt and set its priority
************************************************************************************/	
void SysTick_Start(uint32 tick);

/************************************************************************************
* Service Name: SysTick_Stop
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Stop the SysTick Timer.
************************************************************************************/
void SysTick_Stop(void);



#endif /* GPT_H */