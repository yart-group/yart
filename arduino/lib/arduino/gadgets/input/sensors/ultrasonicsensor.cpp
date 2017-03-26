#include "ultrasonicsensor.h"

UltrasonicSensor::UltrasonicSensor() : _sensor(nullptr)
{

}

void UltrasonicSensor::powerOff()
{
  delete _sensor;
  _sensor = nullptr;
  _state = NOT_WORKING;
}

void UltrasonicSensor::refresh()
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
  _sensor = new MeUltrasonicSensor( port.getPort() );
#else
  _sensor = new int;
#endif
  _state = WORKING;
}

double UltrasonicSensor::read()
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
  return _sensor->distanceCm();
#else
  return 0;
#endif
}
