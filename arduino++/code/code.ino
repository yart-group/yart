#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/usb.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/sensors.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/pilot.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/motors.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/robot.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/program.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/program-0.ino"

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;

Robot * robot;
Pilot * pilot;

Program_0 program;

void setup(){
    robot = new Robot;
    pilot = new Pilot;

    pilot->init();
  
    program.init();
    program.assign( robot );
    program.assign( pilot );
    
}

void _loop(){
    pilot->loop();
}

void loop(){
    program.run();
    exit(0);

    //_delay pilot;
    
    _loop();
}

