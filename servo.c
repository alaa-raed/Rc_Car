/*
 * servo.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */
#include "servo.h"
#include "timer.h"
#include "macros.h"
#include "GPIO.h"
#include <util/delay.h>
#include <avr/io.h>
void Servo_Init(){
		T2_init();
}
void Servo_SetAngle(u16 i){

	T2_PWM(i);
}
// 245 -90
// 500 90
// 0 375
