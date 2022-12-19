 /******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.h
 *
 * Description: Header file to Initilaze Buttons.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/


#ifndef BUTTON
#define BUTTON

#include "tm4c123gh6pm_registers.h"
#include "gpio.h"
#include "interrupt.h"

#define BUTTOM1_PORT     PORTF_ID
#define BUTTOM2_PORT     PORTF_ID
#define BUTTOM3_PORT     PORTE_ID


#define BUTTOM1_PIN      PIN0_ID
#define BUTTOM2_PIN      PIN4_ID
#define BUTTOM3_PIN      PIN5_ID

   


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/***	Description: Function to initilaize Switchs  ***/
void Buttom_Init(void);



#endif
