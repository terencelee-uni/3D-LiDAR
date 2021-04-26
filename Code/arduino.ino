/* Pro Micro Test Code
   by: Nathan Seidle
   modified by: Jim Lindblom
   SparkFun Electronics
   date: September 16, 2013
   license: Public Domain - please use this code however you'd like.
   It's provided as a learning tool.

   This code is provided to show how to control the SparkFun
   ProMicro's TX and RX LEDs within a sketch. It also serves
   to explain the difference between Serial.print() and
   Serial1.print().
*/
#include <Servo.h>
#include <Arduino.h>     // Every sketch needs this
#include <Wire.h>        // Instantiate the Wire library
#include <TFLI2C.h>      // TFLuna-I2C Library v.0.1.0
#include "math.h"
TFLI2C tflI2C;

int16_t  dist;    // distance in centimeters
int16_t  tfAddr = 0x10;  // Default I2C address
int stepper = 13;  
double hor_ang = 0;
int vert_ang = 0;
int Soffset = 90;
double theta;
double phi;
double x;
double y;
double z;
//double PI = 3.14;
Servo servo;
char temp;


void setup() 
{ 
  servo.attach(9);
  servo.write(90);  // set servo to mid-point

  pinMode(stepper, OUTPUT);  // Set RX LED as an output
  // TX LED is set as an output behind the scenes

  Serial.begin(9600); //This pipes to the serial monitor
  Serial.println("Initialize Serial Monitor");
      Wire.begin();           // Initalize Wire library


}

void loop()
{ 
  while (Serial.available()>0){
    temp = Serial.read();
    Serial.println(temp);
    }
  if(temp == 'S'){
    temp = ' ';
    for (int i = 0; i < 20; i++){
      servo.write(vert_ang+Soffset-30);
      for (int j = 0; j < 200; j++){
        pulse_stepper();
        dist = get_TOF_meas();
        
//        theta = hor_ang * PI / 180; //convert deg to radians
//        phi = (vert_ang-30) * PI / 180;
//        x = dist * cos(phi) * cos(theta); //spherical to cartesian
//        y = dist * cos(phi) * sin(theta);
//        z = dist * sin(phi);
        
        Serial.println(String(dist)+","+String(hor_ang)+","+String(vert_ang-30));
//        Serial.println(String(x)+","+String(y)+","+String(z));
        hor_ang = fmod(hor_ang + 1.8,360.0);
      }
      vert_ang = fmod(vert_ang + 3,60.0);
    }
    Serial.print("Stop");
  }
  
}

void pulse_stepper(){
        for (int k = 0; k < 3; k++){  //new location
        digitalWrite(stepper, HIGH);    // set the RX LED OFF
        delayMicroseconds(800);             // wait for a second
        digitalWrite(stepper, LOW);   // set the RX LED ON
        delayMicroseconds(800);
      }
//      delay(500);
  }
int get_TOF_meas(){
//  delay(10);
tflI2C.getData( dist, tfAddr);
return dist;
  }
