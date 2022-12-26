 /******************************************************************************
 *
 * [FILE NAME]: <buzzer.h>
 *
 * Author: Ziad Ayman
 *
 * [DATE CREATED]: <18/12/2022>
 *
 * [DESCRIPTION]: <Header file for BUZZER Driver>
 *
 *******************************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define BUZZER_PORT_ID          PORTA_ID

#define BUZZER_PIN_1            PIN6_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description: A function that initialize the buzzer.
 *
 */
void Buzzer_init(void);

/*
 * Description: A function that start the buzzer.
 *
 */
void Buzzer_on(void);

/*
 * Description: A function that stop the buzzer.
 *
 */
void Buzzer_off(void);



#endif /* BUZZER_H_ */
