 /******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.c
 *
 * Description: Source file to Initilaze Buttons.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/

#include "Button.h"


/***	Description: Function to initilaize Switchs  ***/
void Buttom_Init()
{
  GPIO_setupPinDirection (BUTTOM1_PORT,BUTTOM1_PIN,PIN_INPUT);
  GPIO_setupPinDirection (BUTTOM2_PORT,BUTTOM2_PIN,PIN_INPUT);
  GPIO_setupPinDirection (BUTTOM3_PORT,BUTTOM3_PIN,PIN_INPUT);
 GPIO_setupPinDirection (BUTTOM4_PORT,BUTTOM4_PIN,PIN_INPUT);



}


