/*
 * timer.h
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */

#ifndef BASE_TIMER_H_
#define BASE_TIMER_H_

#include "macros.h"

void T0_Init_CTC_Mode(unsigned char tick);
void T0_Deinit_CTC_Mode();
void T0_init();
void T0_PWM(u8 duty_cycle);

void T2_Init();
void T2_duty(u16 x);
#endif /* BASE_TIMER_H_ */
