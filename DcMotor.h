/*
 * DcMotor.h
 *
 *  Created on: Oct 9, 2022
 *      Author: abdoa
 */

#ifndef GPIO_DCMOTOR_H_
#define GPIO_DCMOTOR_H_

#include"macros.h"


#define Motor1_PORT		A
#define Motor1_Pin1		PIN0
#define Motor1_Pin2		PIN1
#define Motor2_PORT		A
#define Motor2_Pin1		PIN2
#define Motor2_Pin2		PIN4
#define Motor_EN_PORT	A
#define Motor1_EN_Pin	PIN4
#define Motor2_EN_Pin	PIN5


typedef enum {
	Clkw,A_Clkw,Stop
}M_state;



void Motor_Init();


void Motor1_Rot(M_state st);


void Motor2_Rot(M_state st);


#endif /* GPIO_DCMOTOR_H_ */
