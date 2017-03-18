#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;

Robot * robot;
Pilot * pilot;

Program_0 program;

void setup(){
    robot = new Robot;
    pilot = new Pilot;

    Pilot->init();
  
    program.init();
    program.assign( robot );
    program.assign( pilot );
    
}

void loop(){
    program.run();
    exit(0);

    //_delay pilot;
    
    _loop();
}

void _loop(){
    pilot->loop();
}

