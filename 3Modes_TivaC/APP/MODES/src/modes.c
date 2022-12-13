#include "modes.h"
#include "lcd.h"
#include "keypad.h"
#include "buzzer.h"
#include "timer.h"
#include "SysTick.h"

uint8 NUMBER1 , NUMBER2 , OPERATION;
uint8 seconds=0 , minutes=0;
uint8 sec=0 , min=0;
uint8 result_str[10];
uint16 result, ipart;
uint32 result_div, fpart;
uint8 state_flag = 0;
uint8 flag =0;
static uint8 New_Tick_Flag = 0;

void SystickNewTick(void)
{
	/*a flag used as indication for new tick in the systick timer and then a new second indication */
    New_Tick_Flag = 1;
}

void displayTime(void)
{
	if(minutes != 0)
        {
		LCD_intgerToString(minutes);
		LCD_displayCharacter(':');
	}
	
	LCD_intgerToString(seconds);
        
        if (seconds == 60)
        {
          minutes++;
          seconds = 0;
        }
}

void time(void)
{	
  if(min != 0)
        {
		LCD_intgerToString(min);
		LCD_displayCharacter(':');
	}
	LCD_intgerToString(sec);
        
        if (sec == 60)
        {
          min++;
          sec = 0;
        }
}

void start (void)
{
  flag = 1;
  TIMER_Start();
}

void pause (void)
{
  flag = 2;
  TIMER_Stop();
}

void reset (void)
{
  flag =3 ;
  seconds = 0;
  minutes = 0;
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
		LCD_displayCharacter(NUMBER1);
		LCD_displayCharacter(OPERATION);
		LCD_displayCharacter(NUMBER2);
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


void CalcMode ( void )
{
  state_flag = 1;
  while(1)
  {
  
		LCD_displayString("num1 : ");
		do
                {
			NUMBER1 = KEYPAD_getPressedKey();
			LCD_moveCursor(0 , 8);   							// set cursor location at (0,8)
			LCD_displayCharacter(NUMBER1);
		}while(NUMBER1 == '+' || NUMBER1 == '-' || NUMBER1 == '*' || NUMBER1 == '/' || NUMBER1 == '=');					//repeat until a number is detected

		//read operation//
		LCD_clearScreen();
		LCD_displayString("op :   ");
		do
                {
			OPERATION = KEYPAD_getPressedKey();
			LCD_moveCursor(0 , 8);   							// set cursor location at (0,8)
			LCD_displayCharacter(OPERATION);
		}while(	OPERATION == '=' || (OPERATION < 57 && OPERATION > 48) );    	// ascii code of 0 = 48, 9 = 57
		
		//read second number//
		LCD_clearScreen();
		LCD_sendCommand(LCD_GO_TO_HOME);
		LCD_displayString("num2 : ");
		do
                {
			NUMBER2 = KEYPAD_getPressedKey();
			LCD_moveCursor(0 , 8);   							// set cursor location at (0,8)
			LCD_displayCharacter(NUMBER2);
		}while(NUMBER2 == '+' || NUMBER2 == '-' || NUMBER2 == '*' || NUMBER2 == '/' || NUMBER2 == '=');             //repeat until a number is detected
		
		//compute result //
		if(OPERATION == '+')
                {		
			result = (NUMBER1 - 48) + (NUMBER2 - 48);
			
			tostring(result_str, result);
			displayResult(NUMBER1, OPERATION, NUMBER2);
			sendResultNumber(result_str);
		}
		else if(OPERATION == '-')
                {
			if(NUMBER1 > NUMBER2){
				result = (NUMBER1 - 48) - (NUMBER2 - 48);
				
				tostring(result_str, result);
				displayResult(NUMBER1, OPERATION, NUMBER2);
				sendResultNumber(result_str);
			}else{
				result = (NUMBER2 - 48) - (NUMBER1 - 48);
				
				tostring(result_str, result);
				displayResult(NUMBER1, OPERATION, NUMBER2);
				sendResultNumber(result_str);
			}
		}
		else if(OPERATION == '*')
                {			
				result = (NUMBER1 - 48) * (NUMBER2 - 48);
				tostring(result_str, result);
				displayResult(NUMBER1, OPERATION, NUMBER2);
				sendResultNumber(result_str);
		}
		else
                {
				result_div = (float)(NUMBER1 - 48) / (float)(NUMBER2 - 48);
				ipart  = (uint16)result_div;
				tostring(result_str, ipart);
				if(ipart == result_div){                   //no floating part
					displayResult(NUMBER1, OPERATION, NUMBER2);
					sendResultNumber(result_str);
				}else{                                     //floating part
					fpart = result_div - (float)ipart;
					fpart = (uint16)(fpart * 10);            //only first number after the decimal point
					
					displayResult(NUMBER1, OPERATION, NUMBER2);
					sendResultNumber(result_str);             //integar part
					LCD_displayCharacter('.');												//decimal point					
					LCD_displayCharacter(fpart + 48);								//fraction part
				}
		}
		
			LCD_clearScreen();
  }
  
}



void TimerMode ( void )
{
  uint8 cmd;
  state_flag = 2;
  LCD_clearScreen();
  LCD_displayString("enter time");
  
  cmd = KEYPAD_getPressedKey();
  
  sec = cmd;
  
  SysTick_SetCallBack(SystickNewTick);
  
  SysTick_Start(cmd);
  
  while (1)
  {
    if (New_Tick_Flag == 1)
  {
    Buzzer_on();
    New_Tick_Flag =0;
  }
    time();
  }
}



void StopWatchMode ( void )
{
  state_flag = 3;
  while (1)
  {
    displayTime();
  }
}