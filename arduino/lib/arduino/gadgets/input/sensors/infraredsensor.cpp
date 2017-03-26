#include "infraredsensor.h"

InfraredSensor::InfraredSensor() : _sensor(nullptr)
{

}

void InfraredSensor::powerOff()
{
  delete _sensor;
  _sensor = nullptr;
  _state = NOT_WORKING;
}

void InfraredSensor::refresh()
{
  if(power.enabled() == false){
    powerOff();
    return ;
  }

  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return;

  if(_sensor) delete _sensor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor = new MeInfraredSensor( port.getPort() );
  _sensor->begin();
#else
  _sensor = new int;
#endif
  _state = WORKING;
}

double InfraredSensor::read()
{
  if(power.enabled() == false){
    powerOff();
    return 0;
  }

  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return 0;
  if(_state != WORKING) return 0;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _sensor->getCode();
#else
  return 0;
#endif
}
