/*
 * Automatic Hand Soap Dispenser
 * Version 2
 * Created: 4/2/2021
 * Author: Neil Lukowski
 * 
 * Version  2.0 - Abandoned dispense loop in favor of repeated activations when proximity detected
 * Revision 1.2 - Called the function when HIGH value is detected by sensor
 * Version  1.1 - Added: code sample from Elegoo 37 in 1 Sensor Kit Tutorial Lesson 25
 *                which reads values from Obstacle Avoidance Sensor and lights LED
 *                when a HIGH value is detected
 *                Removed: Testing code that required serial input to trigger dispense()
 * Version  1.0 - Code that read serial input looking for "k" to trigger a dispense()function
 *                which rotates a servo 3 times simulating a soap dispense action
 */

#include <Servo.h>
Servo serv;
int sensor_pin = 4;
int servo_pin =5;
int val;

//#include "SR04.h"    code commented out is for testing or no longer used
//#define TRIG_PIN 12
//#define ECHO_PIN 11
//const int ledpin = 2;
//SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
//int pos;
//long a;
//int Led=13;       //define LED port
//int buttonpin=3; //define switch port
//int val;      //define digital variable val
//int disp;

//int dispense(){
//  for( int i = 0; i<=3; i++){
//        Serial.println("Going to 0");     // Printing angle to the Serial monitor for testing
//        serv.write(0);                    // Moving the servo to 0 degrees
//        delay(250);

//        Serial.println("Going to 90");
//        serv.write(90);                   // Moving the servo to 90 degrees
//        delay(250);      
//  }
//  return 1;
//}

void setup() {
  pinMode(sensor_pin,INPUT);
  serv.attach(servo_pin);
// serv.attach(9);  
//  Serial.begin(9600);
//  delay(100);
//  pinMode(Led,OUTPUT);//define LED as a output port
//  pinMode(buttonpin,INPUT);//define switch as a output port
}

void loop() {
{ val = digitalRead(sensor_pin);

    if(val==0)
      {
        serv.attach(servo_pin);
        serv.write(0);
        delay(500);
        serv.write(60);
        delay(500);
      }
      
    if (val==1)
     {
      serv.write(0);
      serv.detach();
    }
}
  
}
