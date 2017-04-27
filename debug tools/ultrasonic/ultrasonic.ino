#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

MeUltrasonicSensor ultrasonic_3(3);
double ultrasonic_value;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ultrasonic_value = ultrasonic_3.distanceCm();

  Serial.print("ultrasonic value: ");
  Serial.println(ultrasonic_value);

  if(ultrasonic_value == 2)
    exit(0);
  
  _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){ 
}
