#include "ultrasonicsensor.h"

bool UltrasonicSensor::powerOff_addons()
{
  delete _sensor;
  _sensor = nullptr;
  return true;
}

bool UltrasonicSensor::init_addons()
{
  return reconnect();
}

bool UltrasonicSensor::reconnect_addons()
{
  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return false;
  if(port.usable() == false) return false;

  if(_sensor) delete _sensor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor = new MeUltrasonicSensor( port.getPort() );
#else
  _sensor = new int;
#endif

  return true;
}

double UltrasonicSensor::read_addons()
{
  if(debug.enabled()){
    // debug msg
  }

  if(_state != WORKING) return -1;
  if(freeze.enabled()) return -1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _sensor->distanceCm();
#else
  return 0;
#endif
}
