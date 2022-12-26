 /******************************************************************************
 *
 * [FILE NAME]: <keypad.c>
 *
 * Author: Ziad Ayman
 *
 * [DATE CREATED]: <18/12/2022>
 *
 * [DESCRIPTION]: <Source file for KEYPAD Driver>
 *
 *******************************************************************************/
#include "Common_Macros.h"
#include "keypad.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Prototypes                                    *
 *******************************************************************************/


static const uint8 mapping[4][4] = { {'1', '2', '3', '+'},
                                     {'4', '5', '6', '-'},
                                     {'7', '8', '9', '/'},
                                     {'*', '0', '#', '='} };


                  
void keypad_init()
{
  uint8 i;
  for(i=0;i<KEYPAD_NUM_COLS;i++) /* loop for columns */
		{
			/* 
			 * Each time setup the direction for all keypad port as input pins,
			 * except this column will be output pin
			 */
			GPIO_setupPinDirection(KEYPAD_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+i,PIN_INPUT);
			GPIO_setupPinDirection(KEYPAD_PORT2_ID,KEYPAD_FIRST_COLUMN_PIN_ID+i,PIN_OUTPUT);
                }
}


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
uint8 keypad_read(void)
{
	uint8 col,row;
	uint8 keypad_port_value = 0;
	while(1)
	{
		for(col=0;col<KEYPAD_NUM_COLS;col++) /* loop for columns */
		{


#if(KEYPAD_BUTTON_PRESSED == LOGIC_LOW)
			/* Clear the column output pin and set the rest pins value */
			keypad_port_value = (1<<(KEYPAD_NUM_COLS+col));
#else
			/* Set the column output pin and clear the rest pins value */
			keypad_port_value = ~(1<<(KEYPAD_NUM_COLS+col));
#endif
                        GPIO_PORTC_DATA_R = keypad_port_value;
                        delay_ms(2);

			for(row=0;row<KEYPAD_NUM_ROWS;row++) /* loop for rows */
			{
				/* Check if the switch is pressed in this row */
				if((GPIO_PORTE_DATA_R & 0x0F) & (1<<(row)))
				{
					return mapping[row][col];
				}
			}
		}
	}	
}

