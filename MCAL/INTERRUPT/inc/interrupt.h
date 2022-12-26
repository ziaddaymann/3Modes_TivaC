 /******************************************************************************
 *
 * Module: INTERRUPT
 *
 * File Name: interrupt.h
 *
 * Description: Header file to Initilaze Interrupts.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/


#ifndef INTERRUPT_H
#define INTERRUPT_H


#include "gpio.h"
#include "Common_Macros.h"
#include "StandardTypes.h"
#include "tm4c123gh6pm_registers.h"


/************ Define for interrupt to be easily used **************************/
#define Enable_Interrupts()    __asm("CPSIE I")
#define Disable_Interrupts()   __asm("CPSID I")
#define Enable_Exceptions()    __asm("CPSIE F")
#define Disable_Exceptions()   __asm("CPSID F") 
#define Wait_For_Interrupt()   __asm("WFI")


typedef enum 
{
SYSTIC , INPUT_OUTPUT
} INT_MODE;

typedef enum
{
FALLING , RISING
} INT_EDGES;


typedef struct
{
INT_MODE mode;
INT_EDGES edge;
uint8 port_num;
uint8 pin_num;
} INT_CONFIG;

void INTERRUPT_Init ( INT_CONFIG *config_ptr);


#endif