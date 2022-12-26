 /******************************************************************************
 *
 * [FILE NAME]: <lcd.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <04/11/2022>
 *
 * [DESCRIPTION]: <Source file for lcd>
 *
 *******************************************************************************/



#include <math.h>  
#include <stdlib.h>
#include <stdio.h>

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "lcd.h"


static void swap(char *x, char *y);
static char* reverse(char *buffer, int i, int j);
static char* itoa(int value, char* buffer, int base);

void LCD_init(void)
{
 
  GPIOUnlockPin(GPIO_PORTB_BASE,0xFF);
  GPIO_PORTB_CR_R |= 0xFF;   
  LCD_DIR |=0xFF; /* Set GPIOB all pins a digital output pins */
  LCD_DEN |=0xFF; /* Declare GPIOB pins as digital pins */
  //GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
  
  LCD_Cmd(Set5x7FontSize);  /* select 5x7 font size and 2 rows of LCD */
  LCD_Cmd(Function_set_4bit); /* Select 4-bit Mode of LCD */
  LCD_Cmd(moveCursorRight); /* shift cursor right */
  LCD_Cmd(clear_display); /* clear whatever is written on display */
  LCD_Cmd(cursorBlink);  /* Enable Display and cursor blinking */
  
}

void LCD_Cmd(unsigned char command)
{
  LCD_Write_Nibble(command & 0xF0, 0);   /* Write upper nibble to LCD */
  LCD_Write_Nibble(command << 4, 0);     /* Write lower nibble to LCD */
  
  if (command < 4)
    delay_ms(2);         /* 2ms delay for commands 1 and 2 */
  else
    delay_us(40);        /* 40us delay for other commands */
}


void LCD_Write_Nibble(unsigned char data, unsigned char control)
{
  
  data &= 0xF0;       /* Extract upper nibble for data */
  control &= 0x0F;    /* Extract lower nibble for control */
  LCD_DATA = data | control;       /* Set RS and R/W to zero for write operation */
  LCD_DATA = data | control | EN;  /* Provide Pulse to Enable pin to perform wite operation */
  delay_us(0);
  LCD_DATA = data; /*Send data */
  LCD_DATA = 0; /* stop writing data to LCD */
}
void LCD_displayCharacter(unsigned char data)
{
  LCD_Write_Nibble(data & 0xF0, RS);    /* Write upper nibble to LCD and RS = 1 to write data */
  LCD_Write_Nibble(data << 4, RS);      /* Write lower nibble to LCD and RS = 1 to write data */
  delay_us(40);
}


void LCD_displayString (char *str)	/* Send string to LCD function */
{
  int i;
  for(i=0;str[i]!=0;i++)  /* Send each char of string till the NULL */
  {
    LCD_displayCharacter(str[i]);  /* Call LCD data write */
  }
}

void LCD_moveCursor(uint8 row,uint8 col)
{
  uint8 lcd_memory_address;
  
  /* Calculate the required address in the LCD DDRAM */
  switch(row)
  {
  case 0:
    lcd_memory_address=col;
    break;
  case 1:
    lcd_memory_address=col+0x40;
    break;
  case 2:
    lcd_memory_address=col+0x10;
    break;
  case 3:
    lcd_memory_address=col+0x50;
    break;
  }					
  /* Move the LCD cursor to this specific address */
  LCD_Cmd(lcd_memory_address | FirstRow);
}
void LCD_displayStringRowColumn(uint8 row,uint8 col, char *Str)
{
  LCD_moveCursor(row,col); /* go to to the required LCD position */
  LCD_displayString (Str); /* display the string */
}

void LCD_intgerToString(int data)
{
  char buff[16]; /* String to hold the ascii result */
  itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
  LCD_displayString(buff); /* Display the string */
}
void LCD_floatToString(double data)
{
  char buff[16]; /* String to hold the ascii result */
  gcvt(data,5,buff); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
  LCD_displayString(buff); /* Display the string */
}
void LCD_clearScreen(void)
{
  LCD_Cmd(clear_display); /* Send clear display command */
}


static void swap(char *x, char *y)
{
  char t = *x;
  *x = *y;
  *y = t;
}
static char* reverse(char *buffer, int i, int j)
{
  while (i < j) {
    swap(&buffer[i++], &buffer[j--]);
  }
  
  return buffer;
}

static char* itoa(int value, char* buffer, int base)
{
  // invalid input
  if (base < 2 || base > 32) {
    return buffer;
  }
  
  // consider the absolute value of the number
  int n = abs(value);
  
  int i = 0;
  while (n)
  {
    int r = n % base;
    
    if (r >= 10) {
      buffer[i++] = 65 + (r - 10);
    }
    else {
      buffer[i++] = 48 + r;
    }
    
    n = n / base;
  }
  
  // if the number is 0
  if (i == 0) {
    buffer[i++] = '0';
  }
  
  // If the base is 10 and the value is negative, the resulting string
  // is preceded with a minus sign (-)
  // With any other base, value is always considered unsigned
  if (value < 0 && base == 10) {
    buffer[i++] = '-';
  }
  
  buffer[i] = '\0'; // null terminate string
  
  // reverse the string and return it
  return reverse(buffer, 0, i - 1);
}