#include <Wire.h>
#include "Gyroscope.h"

long loop_timer;
Gyroscope mygyro(0x68);

void setup() {
  Serial.begin(57600);
  Wire.begin();                                                        //Start I2C as master
  mygyro.calibrate();
  loop_timer = micros();                                               //Reset the loop timer
}

void loop() {
  // put your main code here, to run repeatedly:
  mygyro.read_angular_movement();
  Serial.print(mygyro.get_pitch_angle()); Serial.print("\t"); 
  Serial.print(mygyro.get_roll_angle()); Serial.print("\t"); 
  Serial.print(mygyro.get_yaw_angle()); Serial.println(); 
  while(micros() - loop_timer < 4000);                                 //Wait until the loop_timer reaches 4000us (250Hz) before starting the next loop
  loop_timer = micros();                                               //Reset the loop timer
}
