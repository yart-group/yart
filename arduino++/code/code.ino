#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/usb.cpp"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/sensors.cpp"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/pilot.cpp"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/motors.cpp"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/robot.cpp"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/program.cpp"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/program-0.cpp"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/program-1.cpp"
#include "/run/media/robert/C09C-28FD/GitHub/Goofy/arduino++/code/source/program-2.cpp"

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;

Robot * robot;
Pilot * pilot;

Program_0 manualControl;
Program_1 walk;
Program_2 stay;

void setup(){
    robot = new Robot;
    pilot = new Pilot;

    pilot->init();
  
    manualControl.init();
    manualControl.assign( robot );
    manualControl.assign( pilot );

    walk.init();
    walk.assign( robot );
    walk.assign( pilot );

    stay.init();
    stay.assign( robot );
    stay.assign( pilot );
    
}

void _loop(){
    pilot->loop();
}

#define exec_program(button,program) \
if(pilot->getCode() == Pilot:: button ){ \
  robot->delay(1); \
  program .run() ; \
  robot->delay(1); \
}

void loop(){
    
    
    exec_program(button_1, manualControl)
    else exec_program(button_2, walk)
    // else exec_program(button_3, stay)

    //_delay pilot;
    
    _loop();
}

#undef exec_program


