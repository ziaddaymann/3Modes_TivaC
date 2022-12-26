/******************************************************************************
 *
 * Module: delay
 *
 * File Name: delay.c
 *
 * Description: Source file for delay.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/



/* Mili seconds delay function */
#include "delay.h"

void delay_ms(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {}
}

/* Micro seconds delay function */
void delay_us(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {}
 
}