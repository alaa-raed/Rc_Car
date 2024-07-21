/*
 * GPIO.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */

#include "GPIO.h"
#include <avr/io.h>

/*
 * Description :
 * Setup the dir of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void pinMode(u8 port_num, u8 pin_num, PinDir dir){
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	*/
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)){}
	else{
		/* Setup the pin dir as required */
		switch(port_num){
			case (A | a):
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRA,pin_num);
				}
				else
				{
					CLR_BIT(DDRA,pin_num);
				}
				break;
			case (B | b) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRB,pin_num);
				}
				else
				{
					CLR_BIT(DDRB,pin_num);
				}
				break;
			case (C | c) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRC,pin_num);
				}
				else
				{
					CLR_BIT(DDRC,pin_num);
				}
				break;
			case (D | d) :
				if(dir == OUTPUT || dir == 1 || dir == HIGH)
				{
					SET_BIT(DDRD,pin_num);
				}
				else
				{
					CLR_BIT(DDRD,pin_num);
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
void pinWrite(u8 port_num, u8 pin_num, u8 value){
	/*
		 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
		 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
		 * In this case the input is not valid port/pin number
		 */
		if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)){}
		else
		{
			/* Write the pin value as required */
			switch(port_num)
			{
			case (A | a):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTA,pin_num);
				}
				else
				{
					CLR_BIT(PORTA,pin_num);
				}
				break;
			case (B | b):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTB,pin_num);
				}
				else
				{
					CLR_BIT(PORTB,pin_num);
				}
				break;
			case (C | c):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTC,pin_num);
				}
				else
				{
					CLR_BIT(PORTC,pin_num);
				}
				break;
			case (D | d):
				if(value == HIGH || value == 1)
				{
					SET_BIT(PORTD,pin_num);
				}
				else
				{
					CLR_BIT(PORTD,pin_num);
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
u8 pinRead(u8 port_num, u8 pin_num){
		u8 pin_value = LOW;
		/*
		 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
		 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
		 * In this case the input is not valid port/pin number
		 */
		if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)){}
		else
		{
			/* Read the pin value as required */
			switch(port_num)
			{
			case (A | a):
				if(BIT_IS_SET(PINA,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (B | b):
				if(BIT_IS_SET(PINB,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (C | c):
				if(BIT_IS_SET(PINC,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
			case (D | d):
				if(BIT_IS_SET(PIND,pin_num))
				{
					pin_value = HIGH;
				}
				else
				{
					pin_value = LOW;
				}
				break;
						}
		}

		return pin_value;

}

/*
 * Description :
 * Setup the dir of the required port all pins input/output.
 * If the dir value is PORT_INPUT all pins in this port should be input pins.
 * If the dir value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void portMode(u8 port_num, u8 dir){
	/*
		 * Check if the input number is greater than NUM_OF_PORTS value.
		 * In this case the input is not valid port number
		 */
		if(port_num >= NUM_OF_PORTS){}
		else
		{
			/* Setup the port dir as required */
			switch(port_num)
			{
			case (A | a):
				DDRA = dir;
				break;
			case (B | b):
				DDRB = dir;
				break;
			case (C | c):
				DDRC = dir;
				break;
			case (D | d):
				DDRD = dir;
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
void portWrite(u8 port_num, u8 value){
	/*
		 * Check if the input number is greater than NUM_OF_PORTS value.
		 * In this case the input is not valid port number
		 */
		if(port_num >= NUM_OF_PORTS){}
		else
		{
			/* Write the port value as required */
			switch(port_num)
			{
			case (A | a):
				PORTA = value;
				break;
			case (B | b):
				PORTB = value;
				break;
			case (C | c):
				PORTC = value;
				break;
			case (D | d):
				PORTD = value;
				break;

			}
		}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
u8 portRead(u8 port_num){
	u8 value = LOW;
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS){}
	else
	{
		/* Read the port value as required */
		switch(port_num)
		{
		case (A | a):
			value = PINA;
			break;
		case (B | b):
			value = PINB;
			break;
		case (C | c):
			value = PINC;
			break;
		case (D | d):
			value = PIND;
			break;
				}
	}

	return value;
}

