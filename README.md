# Tesla Model X

## Table of Contents

1. [Project Objective](#project-objective)
2. [System Block Diagram](#system-block-diagram)
    - [Block Diagram](#block-diagram)
    - [Block Diagram Description](#block-diagram-description)
3. [Schematic Diagram (Circuit Diagram)](#schematic-diagram-circuit-diagram)
4. [List Of Components](#list-of-components)
5. [Real-Time Hardware Photo](#real-time-hardware-photo)


---

## Project Objective
The primary objective of this project is to design and develop an advanced remote-controlled (RC) car utilizing embedded systems technology. The RC car will feature three distinct modes of operation: manual remote control, autonomous navigation using sensors, and voice recognition for command execution. This project aims to demonstrate effective communication between the remote controller and the RC car, incorporate safety features to prevent accidents and collisions, and showcase innovation and creativity in the design and functionality of the RC car.

## Project Features

### Remote-Controlled (RC) Mode:
This mode allows for manual control of the RC car using a wireless remote controller. Users can steer, accelerate, and brake the car, providing a traditional RC car experience with responsive and intuitive control.

### Autonomous Mode:
In this mode, the RC car will use sensors (such as ultrasonic sensors) and embedded algorithms to navigate autonomously. It will be capable of detecting and avoiding obstacles, following predefined paths, and performing basic autonomous driving functions without user intervention.

### Voice Recognition Mode:
This feature enables the RC car to receive and execute voice commands. Users can initiate actions such as starting, stopping, turning, and switching between modes through voice recognition, enhancing user interaction and control flexibility.

## System Block Diagram

### Block Diagram
![Block Diagram](https://github.com/amrhossam9/RC-Car/blob/main/Pictures/Block%20Diagram.png)

### Block Diagram Description
The project makes use of an ATmega32 microcontroller to control various components of the RC car. The microcontroller is connected to an H-bridge, which in turn is connected to the DC motors that provide the car's movement. Additionally, the microcontroller is connected to a Bluetooth module that receives commands through UART and is connected to the remote controller.

A servo motor is also used in the project, which is attached to an ultrasonic sensor. The ultrasonic sensor is mounted on the servo motor, allowing it to look in different directions. Additionally, an infrared sensor is incorporated into the design.

## Schematic Diagram (Circuit Diagram)
![Circuit Diagram 1](https://github.com/amrhossam9/RC-Car/blob/main/Pictures/Circuit%201.png)

The calculation used to configure the sensor:
Sound velocity = 340.00 m/s = 34000 cm/s
the distance of Object (in cm) = (340000∗Time)/2 = 17000 * Time
Total distance is divided by 2 because the signal travels from HC-SR04 to the object and returns to the module.
Now, here we have selected an internal 16MHz oscillator frequency for ATmega32, with Pre scaler F_CPU/8 for timer frequency.
distance (cm) = 17000 x (TIMER value) x 5 x 10^-7 cm
= 0.0085 x (TIMER value) cm
= (TIMER value) / 117 cm

## List Of Components
| SN  | Item Type       | Item Code         | Name                    | Purpose                                           | Quantity |
|-----|-----------------|-------------------|-------------------------|---------------------------------------------------|----------|
| 1   | Microcontroller | ATMEGA 32         | ATMEGA 32               | To process the code                               | 1        |
| 2   | Motor           | DC Motor          | DC Motor                | To move the car                                   | 2        |
| 3   | Motor           | Servo             | Servo Motor             | To move the Ultrasonic Sensor                     | 1        |
| 4   | Sensor          | UltraSonic Sensor | UltraSonic Sensor       | Stop the car from hitting                         | 1        |
| 5   | H-Bridge        | L298N             | L298N                   | To Help in controlling the direction of the motor | 1        |
| 6   | IR Sensor       | -                 | Infrared Sensor         | Used in line moving mode                          | 1        |
| 7   | Bluetooth module| HC-05              | HC-05 Bluetooth module | Controlling the car through Bluetooth             | 1        |

## Real-Time Hardware Photo
![Real-Time Hardware Photo](https://github.com/amrhossam9/RC-Car/blob/main/Pictures/Real%20time%20hardware.png)

