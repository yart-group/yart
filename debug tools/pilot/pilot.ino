#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

MeInfraredReceiver ir_6(6);
int ir_code;

void setup() {
  ir_6.begin();
  Serial.begin(9600);
}

void loop() {
  ir_code = ir_6.getCode();
  
  if( ir_code != 0 ) {
    Serial.print("got code: ");
    Serial.println(ir_code);
  }

  if( ir_code == 74 ) // button 9
    exit(0);
  
  _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    ir_6.loop();
    
    
}
