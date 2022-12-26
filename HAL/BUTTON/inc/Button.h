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
#define BUTTOM3_PORT     PORTA_ID
#define BUTTOM4_PORT     PORTA_ID

#define BUTTOM1_PIN      PIN0_ID // Switch in tiva that starts calculator mode
#define BUTTOM2_PIN      PIN4_ID //  Switch in tiva that starts timer mode
#define BUTTOM3_PIN      PIN2_ID //  external push button that starts stopwatch mode
#define BUTTOM4_PIN      PIN3_ID // second external push button that starts stop watch

   


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/***	Description: Function to initilaize Switchs  ***/
void Buttom_Init(void);



#endif