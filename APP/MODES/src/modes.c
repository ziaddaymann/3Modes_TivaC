 /******************************************************************************
 *
 * [FILE NAME]: <modes.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <04/11/2022>
 *
 * [DESCRIPTION]: <Source file for Modes>
 *
 *******************************************************************************/





#include "modes.h"
#include "lcd.h"
#include "keypad.h"
#include "buzzer.h"
#include "timer.h"
#include "SysTick.h"
#include "delay.h"

uint8 NUMBER1 , NUMBER2 , OPERATION;
uint16 seconds=0 , minutes=0;
uint8 sec=0 , min=0;
uint8 result_str[10];
uint16 result, ipart;
uint32 result_div, fpart;
uint8 state_flag = 0;
uint8 flag =0;
uint8 NEW_TICK_FLAG =0;


void time(void)   // Timer Mode
{	
   LCD_Cmd(returnHome);
   LCD_intgerToString(min);
   LCD_displayCharacter(':');
   LCD_intgerToString(sec);
}


void displaytime(void)  // StopWatch Mode
{
  LCD_clearScreen();
  LCD_Cmd(returnHome);
  LCD_intgerToString(minutes);
  LCD_displayCharacter(':');
  LCD_intgerToString(seconds);
}
  

void start (void)  // StopWatch Mode
{
  flag =1;
  TIMER_Start();
}

void pause (void)  // StopWatch Mode
{
  flag = 2;
  TIMER_Stop();
}

void reset (void)  // StopWatch Mode
{
  flag =0 ;
  seconds = 0;
  minutes = 0;
  TIMER_Stop();
}


void tostring(uint8 str[], uint16 num)  
{
	uint16 i, rem, len = 0, n;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}

void displayResult(uint8 num1, uint8 OPERATION, uint8 num2)
{
		LCD_clearScreen();
		LCD_intgerToString(NUMBER1);
		LCD_displayCharacter(OPERATION);
		LCD_intgerToString(NUMBER2);
		LCD_displayCharacter('=');
}

void sendResultNumber(uint8 result[])
{
		uint16 i =0;
		while(result[i] != '\0')
                {
			LCD_displayCharacter(result[i]);
			i++;
		}
}


void modes (void)
{
  if((GPIO_PORTF_DATA_R & 0x01) ==0)
  {
    if((GPIO_PORTF_DATA_R & 0x01) ==0 )
  {
    if (state_flag == 0)
    {
      TimerMode();
    }
    else if (state_flag == 1)
    {
      StopWatchMode();
    }
    
    else if (state_flag == 2)
    {
      CalcMode();
    }
  }
  }
  
  if((GPIO_PORTF_DATA_R & 0x10) ==0)
  {
    if((GPIO_PORTF_DATA_R & 0x10) ==0 )
  {
    if (state_flag ==2)
    {
      if (( flag == 0) || (flag == 1 ) || (flag == 2))
      {
        start();
      }
    }
  }
  }
  
  
  if((GPIO_PORTA_DATA_R & 0x04) ==0)
  {
    if((GPIO_PORTA_DATA_R & 0x04) ==0 )
  {
    if (state_flag ==2)
    {
      if ( flag == 1)
      {
        pause();
      }
    }
  }
  }
  
  if((GPIO_PORTA_DATA_R & 0x08) ==0)
  {
    if((GPIO_PORTA_DATA_R & 0x08) ==0 )
  {
    if (state_flag ==2)
    {
      if ( (flag == 1) || (flag == 2) )
      {
        reset();
      }
    }
  }
  }
}
  

void CalcMode ( void )
{
  uint8 i , y;
  state_flag = 3;
  while (1)
  {
  LCD_clearScreen();
  LCD_Cmd(returnHome);
  delay_ms(300);
  LCD_displayString("num1:  "); 
  LCD_moveCursor(0, 8);
  
   i = keypad_read();
   if ( i  == '#')
{
  TimerMode();
}
 LCD_displayCharacter(i);
 delay_ms(1000);
 LCD_moveCursor(0 , 9);
 NUMBER1 = i - 48;
 
 i = keypad_read();
 if ( i  == '#')
{
  TimerMode();
}
 LCD_displayCharacter(i);
 delay_ms(1000); 
 NUMBER1 = (NUMBER1*10) + (i - 48);
  
  LCD_clearScreen();
  LCD_displayString("op: ");
  
  
  OPERATION = keypad_read();
  if (  OPERATION == '#')
{
  TimerMode();
}
  delay_ms(30);
  LCD_displayCharacter(OPERATION);
  
  delay_ms(1000);
  
  LCD_clearScreen();
  LCD_displayString("num2: ");
  LCD_moveCursor(0, 8);
  
  
  y = keypad_read();
  if ( y  == '#')
{
  TimerMode();
}
 LCD_displayCharacter(y);
 delay_ms(1000);
 LCD_moveCursor(0 , 9);
 NUMBER2 = y - 48;
 
 y = keypad_read();
 if ( y  == '#')
{
  TimerMode();
}
 LCD_displayCharacter(y);
 delay_ms(1000); 
 NUMBER2 = (NUMBER2*10) + (y - 48);
  
  if(OPERATION == '+')
                {		
			result = (NUMBER1) + (NUMBER2);
			
			tostring(result_str, result);
                        delay_ms(1000);
			displayResult(NUMBER1, OPERATION, NUMBER2);
                        delay_ms(1000);
			sendResultNumber(result_str);
                        delay_ms(5000);
		}
		else if(OPERATION == '-')
                {
			if(NUMBER1 > NUMBER2){
				result = (NUMBER1 ) - (NUMBER2);
				
				tostring(result_str, result);
                                delay_ms(1000);
				displayResult(NUMBER1, OPERATION, NUMBER2);
                                delay_ms(1000);
				sendResultNumber(result_str);
                                delay_ms(5000);
			}else{ 
				result = (NUMBER2) - (NUMBER1);
				
				tostring(result_str, result);
                                delay_ms(1000);
				displayResult(NUMBER1, OPERATION, NUMBER2);
                                delay_ms(1000);
				sendResultNumber(result_str);
                                delay_ms(5000);
			}
		}
		else if(OPERATION == '*')
                {			
				result = (NUMBER1) * (NUMBER2);
				tostring(result_str, result);
                                delay_ms(1000);
				displayResult(NUMBER1, OPERATION, NUMBER2);
                                delay_ms(1000);
				sendResultNumber(result_str);
                                delay_ms(5000);
		}
		else
                {
				result_div = (float)(NUMBER1) / (float)(NUMBER2);
				ipart  = (uint16)result_div;
				tostring(result_str, ipart);
                                delay_ms(1000);
				if(ipart == result_div){              
                                  delay_ms(1000);    //no floating part
					displayResult(NUMBER1, OPERATION, NUMBER2);
                                        delay_ms(1000);
					sendResultNumber(result_str);
                                        delay_ms(5000);
				}else{                                     //floating part
					fpart = result_div - (float)ipart;
					fpart = (uint16)(fpart * 10);            //only first number after the decimal point
					delay_ms(1000);
					displayResult(NUMBER1, OPERATION, NUMBER2);
                                        delay_ms(1000);
					sendResultNumber(result_str);   //integar part
					LCD_displayCharacter('.');												//decimal point					
					LCD_displayCharacter(fpart + 48);
                                        delay_ms(5000);//fraction part
				}
		}

}
}

  




void TimerMode ( void )
{
  state_flag = 1;
    uint8 cmd,cmd2;
  LCD_clearScreen();
 LCD_displayString("min");
 LCD_moveCursor(0 , 5); 
 
 cmd = keypad_read();
 if (cmd   == '#')
{
  StopWatchMode();
}
 LCD_displayCharacter(cmd);
 delay_ms(1000);
 LCD_moveCursor(0 , 6);
 min = cmd - 48;
 
 cmd = keypad_read();
 if (cmd   == '#')
{
  StopWatchMode();
}
 LCD_displayCharacter(cmd);
 delay_ms(1000); 
 min = (min*10) + (cmd - 48);
 
   LCD_clearScreen();
 LCD_displayString("sec");
 LCD_moveCursor(0 , 5); 
 
 
 delay_ms(500);
 
 cmd2 = keypad_read();
 if ( cmd2  == '#')
{
  StopWatchMode();
}
 LCD_displayCharacter(cmd2);
 delay_ms(1000); 
 LCD_moveCursor(0 , 6); 
 sec = cmd2 - 48;
 
 cmd2 = keypad_read();
 if ( cmd2  == '#')
{
  StopWatchMode();
}
 LCD_displayCharacter(cmd2); 
 delay_ms(1000); 
 LCD_moveCursor(0 , 7); 
 sec = (sec*10) + (cmd2 - 48);  
 
 delay_ms(500);
 LCD_clearScreen();
  SysTick_Start((min * 60) + (sec));
  
  while (1)
  {
    modes();
    time();
   
   if (NEW_TICK_FLAG == 1)
   {
     SysTick_Stop();
     Buzzer_on();
     delay_ms(10000);
     Buzzer_off();
     NEW_TICK_FLAG = 0;
   }
  }
}



void StopWatchMode ( void )
{
  LCD_clearScreen();
  state_flag = 2;
  while (1)
  {
    displaytime();
    delay_ms(300);
     modes();
  }
}
