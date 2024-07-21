/*
 * bluetooth.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */


#include "macros.h"
#include "bluetooth.h"
#include "uart.h"


void BT_Init(){
	UART_init(9600);
}
u8  BT_RX(){
	return UART_recieveByte();
}
void BT_TX(u8 data){
	UART_sendByte(data);
}
void BT_TX_string (u8 data[]){
	UART_sendString(data);
}
