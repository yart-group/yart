#include "pilot.h"

bool Pilot::init()
{
  if(! Device::init()) return false;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _infraredSensor.port.setPort(6);
  _infraredSensor.init();
  if( _infraredSensor.working() )
    return true;
  else
    return false;
#endif
  return true;
}
void Pilot::powerOn()
{
  Device::powerOn();
  _infraredSensor.powerOn();
}
void Pilot::powerOff()
{
  _infraredSensor.powerOff();
  Device::powerOff();
}

int Pilot::getCode()
{
  if(! working()) return -1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _lastCode = _infraredSensor.read();
  _infraredSensor.loop();
  return _lastCode;
#else
  return 0;
#endif

}
int Pilot::getLast()
{
  if(! working()) return -1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _lastCode;
#else
  return 0;
#endif
}
