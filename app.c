#include<avr/io.h>
#include "ultrasonic.h"
#include "macros.h"
#include <util/delay.h>
#include "uart.h"
#include "MotorDriver.h"
#include "Buzzer.h"
#include "servo.h"
#include "timer.h"
#include <avr/interrupt.h>
u8 choice;
u8 backwardFlag=0;
u8 hornFlag =0;
u16 distance = 0;
u8 UltrasonicModeOn=1;
#define MIN_DISTANCE 40
#define NUMBER_OF_COMPARE_MTACHES_PER_HALF_SECOND 30

/* global variable contain the ticks count of the timer */
unsigned char g_tick = 0;

ISR(TIMER0_COMP_vect)
{
	g_tick++;

	if(g_tick == NUMBER_OF_COMPARE_MTACHES_PER_HALF_SECOND)
	{
		PORTC = PORTC ^ (1<<PC5);   //toggle led every 1.5 second
		g_tick = 0;                 //clear the tick counter again to count a new 0.5 second
	}
}

ISR(USART_RXC_vect){

	u8 data =UART_recieveByte();
	if(data=='S'){
	stop();
	UltrasonicModeOn=0;
	UCSRB &= ~(1<<RXCIE);}
}

void rc_car_mode(){
	u8 input;
	while(1){
		input=UART_recieveByte();//change uart make it bluetooth

		switch(input){
		case 'F':
			forward();
			Buzzer_off();
			T0_Deinit_CTC_Mode();
			backwardFlag=0;
			break;
		case 'B':
			backward();
			if(backwardFlag==0){
				backwardFlag=1;
				T0_Init_CTC_Mode(250);
			}
			break;
		case 'L':
			left();
			Buzzer_off();
			T0_Deinit_CTC_Mode();
			backwardFlag=0;
			break;
		case 'R':
			right();
			Buzzer_off();
			T0_Deinit_CTC_Mode();
			backwardFlag=0;
			break;
		case 'G':
			Buzzer_off();
			T0_Deinit_CTC_Mode();
			backwardFlag=0;
			left();
			_delay_ms(30);
			forward();
			_delay_ms(30);
			break;
		case 'I':
			Buzzer_off();
			T0_Deinit_CTC_Mode();
			backwardFlag=0;
			right();
			_delay_ms(30);
			forward();
			_delay_ms(30);
			break;
		case 'H':
			if(backwardFlag==0){
				backwardFlag=1;
				T0_Init_CTC_Mode(250);
			}
			left();
			_delay_ms(30);
			backward();
			_delay_ms(30);
			break;
		case 'J':
			if(backwardFlag==0){
				backwardFlag=1;
				T0_Init_CTC_Mode(250);
			}
			right();
			_delay_ms(30);
			backward();
			_delay_ms(30);
			break;
		case 'S':
			if(hornFlag==0){
				Buzzer_off();}
			T0_Deinit_CTC_Mode();
			backwardFlag=0;
			stop();
			break;
		case 'V':
			Buzzer_on();
			hornFlag=1;
			break;
		case 'v':
			Buzzer_off();
			hornFlag=0;
			break;
		case'w':
			/*Servo_SetAngle(n_ninty_angle);
		_delay_ms(1000);
		Servo_SetAngle(zero_angle);
		_delay_ms(1000);
		Servo_SetAngle(p_ninty_angle);
		_delay_ms(1000);
		Servo_SetAngle(zero_angle);
		_delay_ms(1000);
			 */
			return;

			break;
			/*default:
		stop();
		if(hornFlag ==0){
			Buzzer_off();}
		T0_Deinit_CTC_Mode();
		backwardFlag=0;
		break;
			 */
		}

	}
}

void UltraSonicRightAction () {
	Servo_SetAngle(zero_angle);
	_delay_ms(500);

	//backward();
	//_delay_ms(200);
	right();
	_delay_ms(750);
	stop();
}

void UltraSonicLeftAction () {
	Servo_SetAngle(zero_angle);
	_delay_ms(500);
	//backward();
	//_delay_ms(200);
	left();
	_delay_ms(750);
	stop();
}
void UltraSonicBackAction () {
	Servo_SetAngle(zero_angle);
	backward();
	_delay_ms(500);
	left();
	_delay_ms(850);
	stop();
}

void ultraSonic_mode(){

	static u16 distance ;
	 UCSRB |= (1<<RXCIE); //enable Rx interrupt
	while(UltrasonicModeOn){
			Servo_SetAngle(zero_angle);
			forward();

			distance = Ultrasonic_readDistance();

			if (distance < MIN_DISTANCE){
				stop();
				_delay_ms(500);
				Servo_SetAngle(p_ninty_angle);//left
				_delay_ms(500);
				u16 left = Ultrasonic_readDistance();
				Servo_SetAngle(n_ninty_angle);//right
				_delay_ms(500);
				u16 right = Ultrasonic_readDistance();
				if (right> MIN_DISTANCE && right > left ){

					UltraSonicRightAction();
				}
				else if(left > MIN_DISTANCE && left>=right){
					UltraSonicLeftAction();
				}
				else{
					UltraSonicBackAction();
				}

		}}

			UltrasonicModeOn=1;
	}


int main(){
	UART_init(9600);
	Servo_Init();
	Driver();
	Buzzer_init();
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Initialize the Ultrasonic driver */
	Ultrasonic_init();
	Buzzer_on();
	_delay_ms(20);
	Buzzer_off();
	_delay_ms(200);
	Buzzer_on();
	_delay_ms(20);
	Buzzer_off();
	_delay_ms(200);
	Buzzer_on();
	_delay_ms(70);
	Buzzer_off();
	Servo_SetAngle(zero_angle);
	while(1){
		choice = UART_recieveByte();
		switch(choice){
		case'W':
			rc_car_mode();
			break;
		case'U':
			ultraSonic_mode();
			break;
		}
	}
}

