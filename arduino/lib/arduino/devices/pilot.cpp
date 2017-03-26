#include "pilot.h"

bool Pilot::powerOff_addons()
{
  _infraredSensor.power.setOff();
  return true;
}

bool Pilot::init_addons()
{
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _infraredSensor.power.setOn();
  _infraredSensor.port.setPort(6);
  _infraredSensor.init();
  if(_infraredSensor.state() == WORKING)
    return true;
  else
    return false;
#endif
  return true;
}

int Pilot::getCode()
{
  if(!powerCheck())
    return -1;

  if(debug.enabled()){
    // debug msg
  }

  if(_state == NOT_WORKING) return 1;
  if(freeze.enabled()) return 1;

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
  if(!powerCheck())
    return -1;

  if(debug.enabled()){
    // debug msg
  }

  if(_state == NOT_WORKING) return 1;
  if(freeze.enabled()) return 1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _lastCode;
#else
  return 0;
#endif
}
