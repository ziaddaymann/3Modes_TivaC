 /******************************************************************************
 *
 * Module: INTERRUPT
 *
 * File Name: interrupt.c
 *
 * Description: Source file to Initilaze Interrupts.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/


#include "interrupt.h"

void INTERRUPT_Init ( INT_CONFIG *config_ptr)
{

if (config_ptr->mode == SYSTIC)
{
   NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & 0x1FFFFFFF) | (2<<29); 
}

else if (config_ptr->mode == INPUT_OUTPUT)
{

switch (config_ptr->port_num)
{
case PORTA_ID:

CLEAR_BIT(GPIO_PORTA_IBE_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTA_ICR_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTA_IM_REG, config_ptr->pin_num);

if (config_ptr->edge == FALLING)
{
  CLEAR_BIT(GPIO_PORTA_IS_REG, config_ptr->pin_num);
  CLEAR_BIT(GPIO_PORTA_IEV_REG, config_ptr->pin_num);
}

else if (config_ptr->edge == RISING)
{
  CLEAR_BIT(GPIO_PORTA_IS_REG, config_ptr->pin_num);
  SET_BIT(GPIO_PORTA_IEV_REG, config_ptr->pin_num);
}

break;

case PORTB_ID:

CLEAR_BIT(GPIO_PORTB_IBE_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTB_ICR_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTB_IM_REG, config_ptr->pin_num);

if (config_ptr->edge == FALLING)
{
  CLEAR_BIT(GPIO_PORTB_IS_REG, config_ptr->pin_num);
  CLEAR_BIT(GPIO_PORTB_IEV_REG, config_ptr->pin_num);
}

else if (config_ptr->edge == RISING)
{
  CLEAR_BIT(GPIO_PORTB_IS_REG,config_ptr->pin_num);
  SET_BIT(GPIO_PORTB_IEV_REG, config_ptr->pin_num);
}

break;


case PORTC_ID:

CLEAR_BIT(GPIO_PORTC_IBE_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTC_ICR_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTC_IM_REG, config_ptr->pin_num);

if (config_ptr->edge == FALLING)
{
  CLEAR_BIT(GPIO_PORTC_IS_REG, config_ptr->pin_num);
  CLEAR_BIT(GPIO_PORTC_IEV_REG, config_ptr->pin_num);
}

else if (config_ptr->edge == RISING)
{
  CLEAR_BIT(GPIO_PORTC_IS_REG,config_ptr->pin_num);
  SET_BIT(GPIO_PORTC_IEV_REG, config_ptr->pin_num);
}

break;




case PORTD_ID:

CLEAR_BIT(GPIO_PORTD_IBE_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTD_ICR_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTD_IM_REG, config_ptr->pin_num);

if (config_ptr->edge == FALLING)
{
  CLEAR_BIT(GPIO_PORTD_IS_REG, config_ptr->pin_num);
  CLEAR_BIT(GPIO_PORTD_IEV_REG, config_ptr->pin_num);
}

else if (config_ptr->edge == RISING)
{
  CLEAR_BIT(GPIO_PORTD_IS_REG, config_ptr->pin_num);
  SET_BIT(GPIO_PORTD_IEV_REG, config_ptr->pin_num);
}

break;



case PORTE_ID:

CLEAR_BIT(GPIO_PORTE_IBE_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTE_ICR_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTE_IM_REG, config_ptr->pin_num);

if (config_ptr->edge == FALLING)
{
  CLEAR_BIT(GPIO_PORTE_IS_REG, config_ptr->pin_num);
  CLEAR_BIT(GPIO_PORTE_IEV_REG, config_ptr->pin_num);
}

else if (config_ptr->edge == RISING)
{
  CLEAR_BIT(GPIO_PORTE_IS_REG, config_ptr->pin_num);
  SET_BIT(GPIO_PORTE_IEV_REG, config_ptr->pin_num);
}

break;



case PORTF_ID:

CLEAR_BIT(GPIO_PORTF_IBE_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTF_ICR_REG, config_ptr->pin_num);
SET_BIT(GPIO_PORTF_IM_REG, config_ptr->pin_num);

if (config_ptr->edge == FALLING)
{
  CLEAR_BIT(GPIO_PORTF_IS_REG, config_ptr->pin_num);
  CLEAR_BIT(GPIO_PORTF_IEV_REG, config_ptr->pin_num);
}

else if (config_ptr->edge == RISING)
{
  CLEAR_BIT(GPIO_PORTF_IS_REG, config_ptr->pin_num);
  SET_BIT(GPIO_PORTF_IEV_REG, config_ptr->pin_num);
}

break;
}

NVIC_PRI7_REG = (NVIC_PRI7_REG & 0xFF1FFFFF) | (3<<21); 

NVIC_EN0_REG |= 0x40000000;
NVIC_PRI7_REG = (NVIC_PRI7_REG & 0xFF1FFFFF) | (2<<21); 

NVIC_EN0_REG |= 0x40000000;
}
}


