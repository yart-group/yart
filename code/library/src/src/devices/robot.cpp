#include "robot.h"
#include "motherboard/motherboard.h"

Robot::Robot() : _motherboard(nullptr)
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
void Robot::setPowerOn()
{
  Device::setPowerOn();
  _leftMotor.setPowerOn();
  _rightMotor.setPowerOn();
  _ultrasonicSensor.setPowerOn();
}
void Robot::setPowerOff()
{
  _leftMotor.setPowerOff();
  _rightMotor.setPowerOff();
  _ultrasonicSensor.setPowerOff();
  Device::setPowerOff();
}

bool Robot::mount(Motherboard *motherboard)
{
  if(motherboardMounted()) return false;
  _motherboard = motherboard;
  _motherboard->plug(this);
  _motherboard->plug(& _leftMotor);
  _motherboard->plug(& _rightMotor);
  _motherboard->plug(& _ultrasonicSensor);
  return true;
}
bool Robot::unmount()
{
  if(! motherboardMounted()) return false;
  _motherboard->unplug(& _leftMotor);
  _motherboard->unplug(& _rightMotor);
  _motherboard->unplug(& _ultrasonicSensor);
  _motherboard->unplug();
  _motherboard = nullptr;
  return true;
}
bool Robot::motherboardMounted()
{
  return _motherboard;
}
