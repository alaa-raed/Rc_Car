/*
 * MotorDriver.h
 *
 *  Created on: Jun 16, 2023
 *      Author: Mohamed
 */

#ifndef BASE_MOTORDRIVER_H_
#define BASE_MOTORDRIVER_H_
#define max 100
#define mid 50
#define min 25
void Driver();
void forward();
void backward();
void left();
void right();
void stop();
void speed(u8 spd);

#endif /* BASE_MOTORDRIVER_H_ */
