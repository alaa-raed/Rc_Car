/*
 * timer.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */


#include <avr/io.h>
#include "macros.h"
#include "GPIO.h"
#include "timer.h"


/* Interrupt Service Routine for timer0 compare mode */

/* Description:
 * For System Clock = 16Mhz and prescaler F_CPU/1024.
 * Timer frequency will be around 16Khz, Ttimer = 62.5us
 * For compare value equals to 250 the timer will generate compare match interrupt every 15.625ms.
 * Compare interrupt will be generated every 15.625ms, so we need 32 compare interrupts to count 0.5 second.
 */
void T0_Init_CTC_Mode(unsigned char tick)
{
	TCNT0 = 0;    // Set Timer initial value to 0

	OCR0  = tick; // Set Compare Value

	TIMSK |= (1<<OCIE0); // Enable Timer0 Compare Interrupt

	/* Configure timer0 control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
}

void T0_Deinit_CTC_Mode(){
	TCCR0=0;
	TIMSK&=~(1<<OCIE0);
	OCR0=0;
}


void T0_init(){

	OCR0=0;
	DDRB  = DDRB | (1<<PB3);
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<CS02)|(1<<COM01);
}

void T0_PWM(u8 duty_cycle){

	OCR0=duty_cycle;
	//OCR0 = (u8)(((u32)(duty_cycle*255))/100);

}
void T2_init(){

	OCR2=0;
	DDRD  = DDRD | (1<<PD7);
	TCCR2=(1<<WGM20)|(1<<WGM21)|(1<<CS21)|(1<<CS22)|(1<<COM21);
}

void T2_PWM(u8 duty_cycle){

	OCR2 = duty_cycle;

}
