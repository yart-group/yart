#include "pilot.h"

bool Pilot::init()
{
  if(! Device::init()) return false;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _infraredSensor.port.setPort(6);
  _infraredSensor.init();
  if( _infraredSensor.isWorking() )
    return true;
  else{
    wreck(Device::NOT_WORKING);
    return false;
  }
#endif
  return true;
}
void Pilot::setPowerOn()
{
  Device::setPowerOn();
  _infraredSensor.setPowerOn();
}
void Pilot::setPowerOff()
{
  _infraredSensor.setPowerOff();
  Device::setPowerOff();
}

int Pilot::getCode()
{
  if(! isWorking()) return false;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _lastCode = _infraredSensor.read();
  _infraredSensor.loop();
  return _lastCode;
#else
  _lastCode = true;
  return _lastCode;
#endif

}
int Pilot::getLast()
{
  if(! isWorking()) return false;

  return _lastCode;
}
