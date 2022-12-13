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

INT_CONFIG config_b1 = {INPUT_OUTPUT , FALLING , BUTTOM1_PORT , BUTTOM1_PIN};
INT_CONFIG config_b2 = {INPUT_OUTPUT , FALLING , BUTTOM2_PORT , BUTTOM2_PIN};
INT_CONFIG config_b3 = {INPUT_OUTPUT , FALLING , BUTTOM3_PORT , BUTTOM3_PIN};



/***	Description: Function to initilaize Switchs  ***/
void Buttom_Init()
{
  GPIO_setupPinDirection (BUTTOM1_PORT,BUTTOM1_PIN,PIN_INPUT);
  GPIO_setupPinDirection (BUTTOM2_PORT,BUTTOM2_PIN,PIN_INPUT);
  GPIO_setupPinDirection (BUTTOM3_PORT,BUTTOM3_PIN,PIN_INPUT);


  
  INTERRUPT_Init (&config_b1);
  INTERRUPT_Init (&config_b2);
  INTERRUPT_Init (&config_b3);

}


