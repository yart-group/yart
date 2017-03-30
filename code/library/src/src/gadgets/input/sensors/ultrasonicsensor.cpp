#include "ultrasonicsensor.h"

void UltrasonicSensor::powerOff()
{
  Sensor::powerOff();
  if(_sensor) delete _sensor;
  _sensor = nullptr;
}

bool UltrasonicSensor::reconnect()
{
  if(port.usable() == false) return false;

  if(_sensor) delete _sensor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor = new MeUltrasonicSensor( port.getPort() );
#else
  _sensor = new int;
#endif

  return true;
}

double UltrasonicSensor::read()
{
  if(! working()) return -1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _sensor->distanceCm();
#else
  return 0;
#endif
}
