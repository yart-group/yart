#include "pilot.h"

Pilot::Pilot()
{

}

void Pilot::powerOff()
{
  _state = NOT_WORKING;
}

void Pilot::init()
{
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _infraredSensor.init();
#endif
  _state = WORKING;
}

void Pilot::loop()
{
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _infraredSensor.loop();
#endif
}

int Pilot::getCode()
{
  if(power.enabled() == false){
    powerOff();
    return 1;
  }

  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return 1;
  if(_state == NOT_WORKING) return 1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return (_lastCode = _infraredSensor.read());
#else
  return 0;
#endif

}

int Pilot::getLast()
{
  if(power.enabled() == false){
    powerOff();
    return 1;
  }

  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return 1;
  if(_state == NOT_WORKING) return 1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _lastCode;
#else
  return 0;
#endif
}
