#include "robot.h"

bool Robot::powerOff_addons()
{
  _ultrasonicSensor.power.setOff();
  _chassis.power.setOff();
  return true;
}

bool Robot::init_addons()
{
  bool success = true;

  _ultrasonicSensor.power.setOn();
  _chassis.power.setOn();

  _ultrasonicSensor.port.setPort(3);
  // chassis port

  if(!_ultrasonicSensor.reconnect()) success = false;
  // chassis reconnect

  return success;
}


void Robot::mount(Programmer *programmer)
{
  if(!programmer) return;
  _programmer = programmer;
  _programmer->plug(&_ultrasonicSensor);
  _programmer->plug(&_chassis);
}

