#include "robot.h"

#include "microcontroller.h"

bool Robot::mountMicrocontroller(Microcontroller *microcontroller){
  if(! microcontroller->plugRobot(this)) return false;
  _microcontroller = microcontroller;
  return true;
}

bool Robot::unmountMicrocontroller(){
  if(! isMicrocontrollerMounted()) return false;
  if(! _microcontroller->unplugRobot(getId()) ) return false;
  _microcontroller = nullptr;
  return true;
}

