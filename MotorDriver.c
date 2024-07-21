/*
 * MotorDriver.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Mohamed
 */


#include "DcMotor.h"
#include "timer.h"
void Driver(){
	Motor_Init();
}

void forward(){
	Motor1_Rot(A_Clkw);
	Motor2_Rot(A_Clkw);
}

void backward(){
	Motor1_Rot(Clkw);
	Motor2_Rot(Clkw);
}

void left(){
	Motor2_Rot(A_Clkw);
	Motor1_Rot(Clkw);
}

void right(){
	Motor2_Rot(Clkw);
	Motor1_Rot(A_Clkw);
}

void stop(){
	Motor1_Rot(Stop);
	Motor2_Rot(Stop);
}


void speed(u8 spd){
	T0_PWM(spd);
}
