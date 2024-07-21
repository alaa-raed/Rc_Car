/*
 * Buzzer.h
 *
 *  Created on: Oct 31, 2022
 *      Author: abdoa
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include "macros.h"

#define BUZZER_PORT_ID	C
#define BUZZER_PIN_ID	PIN5


void Buzzer_init();
void Buzzer_on();
void Buzzer_off();
void Buzzer_pep();
#endif /* BUZZER_H_ */
