/*
 * Buzzer.c
 *
 *  Created on: Oct 31, 2022
 *      Author: abdoa
 */
#include "Buzzer.h"
#include "GPIO.h"
#include <util/delay.h>
void Buzzer_init(){

	pinMode(BUZZER_PORT_ID, BUZZER_PIN_ID, OUTPUT);
	pinWrite(BUZZER_PORT_ID, BUZZER_PIN_ID, LOW);

}

void Buzzer_on(){
	pinWrite(BUZZER_PORT_ID, BUZZER_PIN_ID, HIGH);
	pinWrite(c, 0, HIGH);

}

void Buzzer_off(){
	pinWrite(BUZZER_PORT_ID, BUZZER_PIN_ID, LOW);
	pinWrite(c, 0, LOW);

}
void Buzzer_pep(){
	Buzzer_on();
	_delay_ms(1000);
	Buzzer_off();

}
