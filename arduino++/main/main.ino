#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/main/usb.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/main/sensors.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/main/pilot.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/main/motors.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/main/robot.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/main/program.ino"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/main/program-0.ino"

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

