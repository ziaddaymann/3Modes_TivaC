 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the ARM GPIO driver
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/

#include "gpio.h"
#include "Common_Macros.h" /* To use the macros like SET_BIT */
#include "tm4c123gh6pm.h"
#include "tm4c123gh6pm_registers.h"
#include <stdint.h>


/*
 * Description :
 * initialize GPIO.
 */
void GPIO_init (void)
{
    SET_BIT(SYSCTL_RCGCGPIO_R,0);
    SET_BIT(SYSCTL_RCGCGPIO_R,1);
    SET_BIT(SYSCTL_RCGCGPIO_R,2);
    SET_BIT(SYSCTL_RCGCGPIO_R,3);
    SET_BIT(SYSCTL_RCGCGPIO_R,4);
    SET_BIT(SYSCTL_RCGCGPIO_R,5);
    while((GET_BIT(SYSCTL_PRGPIO_R,0)) == 0x00);
    while((GET_BIT(SYSCTL_PRGPIO_R,1)) == 0x00);
    while((GET_BIT(SYSCTL_PRGPIO_R,2)) == 0x00);
    while((GET_BIT(SYSCTL_PRGPIO_R,3)) == 0x00);
    while((GET_BIT(SYSCTL_PRGPIO_R,4)) == 0x00);
    while((GET_BIT(SYSCTL_PRGPIO_R,5)) == 0x00);
}


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
			    SET_BIT(GPIO_PORTA_CR_R, pin_num);
			    SET_BIT(GPIO_PORTA_DIR_R, pin_num);
			    SET_BIT(GPIO_PORTA_DEN_R, pin_num);
			}
			else
			{
			    SET_BIT(GPIO_PORTA_CR_R, pin_num);
	             CLEAR_BIT(GPIO_PORTA_DIR_R, pin_num);
	             SET_BIT(GPIO_PORTA_DEN_R, pin_num);
	             SET_BIT(GPIO_PORTA_PUR_R, pin_num);
			}
			break;
		case PORTB_ID:
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(GPIO_PORTB_CR_R, pin_num);
                SET_BIT(GPIO_PORTB_DIR_R, pin_num);
                SET_BIT(GPIO_PORTB_DEN_R, pin_num);
            }
            else
            {
                SET_BIT(GPIO_PORTB_CR_R, pin_num);
                 CLEAR_BIT(GPIO_PORTB_DIR_R, pin_num);
                 SET_BIT(GPIO_PORTB_DEN_R, pin_num);
                 SET_BIT(GPIO_PORTB_PUR_R, pin_num);
            }
            break;
		case PORTC_ID:
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(GPIO_PORTC_CR_R, pin_num);
                SET_BIT(GPIO_PORTC_DIR_R, pin_num);
                SET_BIT(GPIO_PORTC_DEN_R, pin_num);
            }
            else
            {
                SET_BIT(GPIO_PORTC_CR_R, pin_num);
                 CLEAR_BIT(GPIO_PORTC_DIR_R, pin_num);
                 SET_BIT(GPIO_PORTC_DEN_R, pin_num);
                 SET_BIT(GPIO_PORTC_PUR_R, pin_num);
            }
            break;
		case PORTD_ID:
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(GPIO_PORTD_CR_R, pin_num);
                SET_BIT(GPIO_PORTD_DIR_R, pin_num);
                SET_BIT(GPIO_PORTD_DEN_R, pin_num);
                CLEAR_BIT(GPIO_PORTD_AMSEL_R , pin_num);
                CLEAR_BIT(GPIO_PORTD_AFSEL_R , pin_num);
            }
            else
            {
                 SET_BIT(GPIO_PORTD_CR_R, pin_num);
                 CLEAR_BIT(GPIO_PORTD_DIR_R, pin_num);
                 SET_BIT(GPIO_PORTD_DEN_R, pin_num);
                 SET_BIT(GPIO_PORTD_PUR_R, pin_num);
            }
            break;


        case PORTE_ID:
            if(direction == PIN_OUTPUT)
            {
                 SET_BIT(GPIO_PORTE_CR_R, pin_num);
                 SET_BIT(GPIO_PORTE_DIR_R, pin_num);
                 SET_BIT(GPIO_PORTE_DEN_R, pin_num);
            }
            else
            {
                 SET_BIT(GPIO_PORTE_CR_R, pin_num);
                 CLEAR_BIT(GPIO_PORTE_DIR_R, pin_num);
                 SET_BIT(GPIO_PORTE_DEN_R, pin_num);
                 SET_BIT(GPIO_PORTE_PUR_R, pin_num);
            }
            break;

        case PORTF_ID:
            if(direction == PIN_OUTPUT)
            {
                 SET_BIT(GPIO_PORTF_CR_R, pin_num);
                 SET_BIT(GPIO_PORTF_DIR_R, pin_num);
                 SET_BIT(GPIO_PORTF_DEN_R, pin_num);
            }
            else
            {
              if (pin_num == PIN0_ID)
                 {
                     GPIO_PORTF_LOCK_REG   = 0x4C4F434B;   /* Unlock the GPIO_PORTF_CR_REG */
                     GPIO_PORTF_PCTL_REG  &= 0xFFFFFFF0;   /* Clear PMCx bits for PF0 to use it as GPIO pin */
                     SET_BIT(GPIO_PORTF_CR_R, pin_num);
                     CLEAR_BIT(GPIO_PORTF_DIR_R, pin_num);
                     SET_BIT(GPIO_PORTF_DEN_R, pin_num);
                     SET_BIT(GPIO_PORTF_PUR_R, pin_num);
                     CLEAR_BIT(GPIO_PORTF_AMSEL_REG, pin_num);
                     CLEAR_BIT(GPIO_PORTF_AFSEL_REG, pin_num);
                 }
              
              else
              {
                 SET_BIT(GPIO_PORTF_CR_R, pin_num);
                 CLEAR_BIT(GPIO_PORTF_DIR_R, pin_num);
                 SET_BIT(GPIO_PORTF_DEN_R, pin_num);
                 SET_BIT(GPIO_PORTF_PUR_R, pin_num);
              }
              
                 
               
            }
            break;


		}
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(value == LOGIC_HIGH)
			{
		        SET_BIT(GPIO_PORTA_DATA_R, pin_num);
		    }
		    else
		    {
		        CLEAR_BIT(GPIO_PORTA_DATA_R, pin_num);
		    }
			break;
		case PORTB_ID:
			if(value == LOGIC_HIGH)
			{
		        SET_BIT(GPIO_PORTB_DATA_R, pin_num);
		    }
		    else
		    {
		        CLEAR_BIT(GPIO_PORTB_DATA_R, pin_num);
		    }
			break;
		case PORTC_ID:
			if(value == LOGIC_HIGH)
			{
                SET_BIT(GPIO_PORTC_DATA_R, pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTC_DATA_R, pin_num);
            }
			break;
		case PORTD_ID:
			if(value == LOGIC_HIGH)
			{
                SET_BIT(GPIO_PORTD_DATA_R, pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTD_DATA_R, pin_num);
            }
			break;


        case PORTE_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIO_PORTE_DATA_R, pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTE_DATA_R, pin_num);
            }
            break;


        case PORTF_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIO_PORTF_DATA_R, pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTF_DATA_R, pin_num);
            }
            break;
		}
	}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(GPIO_PORTA_DATA_R,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(GPIO_PORTB_DATA_R,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(GPIO_PORTC_DATA_R,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(GPIO_PORTD_DATA_R,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;

        case PORTE_ID:
            if(BIT_IS_SET(GPIO_PORTE_DATA_R,pin_num))
            {
                pin_value = LOGIC_HIGH;
            }
            else
            {
                pin_value = LOGIC_LOW;
            }
            break;


        case PORTF_ID:
            if(BIT_IS_SET(GPIO_PORTF_DATA_R,pin_num))
            {
                pin_value = LOGIC_HIGH;
            }
            else
            {
                pin_value = LOGIC_LOW;
            }
            break;
		}
	}

	return pin_value;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, uint8 direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(port_num)
		{
		case PORTA_ID:
		    GPIO_PORTA_DIR_R = direction;
			break;
		case PORTB_ID:
                    GPIO_PORTB_AMSEL_R = 0x00;
                    GPIO_PORTB_PCTL_R = 0x00000000; 
                    GPIO_PORTB_AFSEL_R = 0x00; 
                    GPIO_PORTB_DEN_R = direction;
		    GPIO_PORTB_DIR_R = direction;
			break;
		case PORTC_ID:
		    GPIO_PORTC_DIR_R = direction;
			break;
		case PORTD_ID:
		    GPIO_PORTD_DIR_R = direction;
			break;
        case PORTE_ID:
            GPIO_PORTE_DIR_R = direction;
            break;
        case PORTF_ID:
            GPIO_PORTF_DIR_R = direction;
            break;
		}
	}
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
		    GPIO_PORTA_DATA_R = value;
			break;
		case PORTB_ID:
		    GPIO_PORTB_DATA_R = value;
			break;
		case PORTC_ID:
		    GPIO_PORTC_DATA_R = value;
			break;
		case PORTD_ID:
		    GPIO_PORTD_DATA_R = value;
			break;
        case PORTE_ID:
            GPIO_PORTE_DATA_R = value;
            break;
        case PORTF_ID:
            GPIO_PORTF_DATA_R = value;
            break;
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{
	uint8 value = LOGIC_LOW;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			value = GPIO_PORTA_DATA_R;
			break;
		case PORTB_ID:
			value = GPIO_PORTB_DATA_R;
			break;
		case PORTC_ID:
			value = GPIO_PORTC_DATA_R;
			break;
		case PORTD_ID:
			value = GPIO_PORTD_DATA_R;
			break;
        case PORTE_ID:
            value = GPIO_PORTE_DATA_R;
            break;
        case PORTF_ID:
            value = GPIO_PORTF_DATA_R;
            break;
		}
	}

	return value;
}
