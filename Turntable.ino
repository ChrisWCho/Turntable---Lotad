
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// int prev = 0;
// int button = 2;
int stepspeed = 10;
bool cwONstep = false;
bool ccwONstep = false;
const int cwbutton = 2;
const int ccwbutton = 3;
const int stopbutton = 4;
int cwbut;
int ccwbut;
int stopbut;
int cwbutstate = 0;
int ccwbutstate = 0;

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(cwbutton, INPUT_PULLUP);
  pinMode(ccwbutton, INPUT_PULLUP);  
  pinMode(stopbutton, INPUT_PULLUP);  
  myStepper.setSpeed(stepspeed);
  Serial.println("Please enter stepper speed value (INTEGER)");
}

void loop() {
  cwbut = digitalRead(cwbutton);
  ccwbut = digitalRead(ccwbutton);
  stopbut = digitalRead(stopbutton);
  
  Serialcomms();
  Buttoncomms();

  // Serial.println(fwdONstep);
  if (cwONstep == true || cwbutstate == 1){
    cwsteptest();
  }
  if (ccwONstep == true || ccwbutstate == 1){
    ccwsteptest();
  }
}

void Buttoncomms(){
  if (cwbut == 0){        // if cw button is pressed, all states regarding the stepper
    ccwbutstate = 0;       // is turned off and only cw will become active
    ccwONstep = false;
    cwONstep = false;
    cwbutstate = 1;
    Serial.println("CLOCKWISE");
    delay(500);
  }
  if (ccwbut == 0){       // if ccw button is pressed, all states regarding the stepper
    cwbutstate = 0;       // is turned off and only ccw will become active
    ccwONstep = false;
    cwONstep = false;
    ccwbutstate = 1;
    Serial.println("COUNTER CLOCKWISE");
    delay(500);
  }
  if (stopbut == 0){
    ccwONstep = false;
    cwONstep = false;
    cwbutstate = 0;
    ccwbutstate = 0;
    Serial.println("HALT");
    delay(500);
  }
}

void Serialcomms(){
  if (Serial.available() > 0) {
    // Serial.println("imbatman");
    String input = Serial.readStringUntil('\n');
    input.trim();

    int value = input.toInt();

    Serial.print("You entered: ");
    Serial.println(value);
    if (value == 1){      // if 1 is entered in the serial monitor all states regarding stepper
      cwbutstate = 0;     // is turned off and only cw will become active
      ccwbutstate = 0;
      ccwONstep = false;
      cwONstep = true;
      Serial.println("clockwise"); 
      delay(500);
    }
    if (value == 2){      // if 2 is entered in the serial monitor all states regarding stepper
      cwbutstate = 0;     // is turned off and only ccw will become active
      ccwbutstate = 0;
      cwONstep = false;
      ccwONstep = true;
      Serial.println("counter clockwise");
      delay(500);
    }
    if (value == 0){      // all states are off
      cwONstep = false;
      ccwONstep = false;
      cwbutstate = 0;
      ccwbutstate = 0;
      Serial.println("halt");
      delay(500);
    }

    Serial.println("Enter another value:");
  }  
}

void cwsteptest(){
  // Serial.println("clockwise"); 
  myStepper.step(20);
}

void ccwsteptest(){
  // Serial.println("counter clockwise");
  myStepper.step(-20);
}

