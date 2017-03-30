#include "robot.h"
#include "programmer/programmer.h"

Robot::Robot() : _programmer(nullptr)
{
  strcpy(_leftMotor.meta.name, "left motor");
  strcpy(_rightMotor.meta.name, "right motor");
  strcpy(_ultrasonicSensor.meta.name, "ultrasonic");
}

bool Robot::init()
{
  if(! Device::init()) return false;

  _leftMotor.port.setPort(9);
  _rightMotor.port.setPort(10);
  _ultrasonicSensor.port.setPort(3);

  bool success = true;
  success &= _leftMotor.init();
  success &= _rightMotor.init();
  success &= _ultrasonicSensor.init();

  return success;
}
void Robot::powerOn()
{
  Device::powerOn();
  _leftMotor.powerOn();
  _rightMotor.powerOn();
  _ultrasonicSensor.powerOn();
}
void Robot::powerOff()
{
  _leftMotor.powerOff();
  _rightMotor.powerOff();
  _ultrasonicSensor.powerOff();
  Device::powerOff();
}

bool Robot::mount(Programmer *programmer)
{
  if(programmerMounted()) return false;
  _programmer = programmer;
  _programmer->plug(this);
  _programmer->plug(& _leftMotor);
  _programmer->plug(& _rightMotor);
  _programmer->plug(& _ultrasonicSensor);
  return true;
}
bool Robot::unmount()
{
  if(! programmerMounted()) return false;
  _programmer->unplug(& _leftMotor);
  _programmer->unplug(& _rightMotor);
  _programmer->unplug(& _ultrasonicSensor);
  _programmer->unplug();
  _programmer = nullptr;
  return true;
}
bool Robot::programmerMounted()
{
  return _programmer;
}
