 /******************************************************************************
 *
 * [FILE NAME]: <keypad.h>
 *
 * Author: Ziad Ayman
 *
 * [DATE CREATED]: <18/12/2022>
 *
 * [DESCRIPTION]: <Header file for KEYPAD Driver>
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "StandardTypes.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                  4
#define KEYPAD_NUM_ROWS                  4

/* Keypad Port Configurations */
#define KEYPAD_PORT_ID                    PORTE_ID //rows
#define KEYPAD_PORT2_ID                   PORTC_ID //columns


#define KEYPAD_FIRST_ROW_PIN_ID           PIN0_ID
#define KEYPAD_FIRST_COLUMN_PIN_ID        PIN4_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void keypad_init();

/*
 * Description :
 * Get the Keypad pressed button
 */
uint8 keypad_read(void);

#endif /* KEYPAD_H_ */
