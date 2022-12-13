 /******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: timer.h
 *
 * Description: Header file for the ARM timer driver
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/


#ifndef GPT_H
#define GPT_H

#include "StandardTypes.h"
#include "interrupt.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/



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
void TIMER_Start(void);


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
void TIMER_Stop(void);



#endif /* GPT_H */