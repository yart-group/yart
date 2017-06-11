#include "ultrasonicsensor.h"

void UltrasonicSensor::setPowerOff()
{
  if(_sensor) delete _sensor;
  _sensor = nullptr;
  Sensor::setPowerOff();
}

bool UltrasonicSensor::reconnect()
{
  if(! Sensor::reconnect()) return false;

  if(port.isUsable() == false) return false;

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
  if(! Sensor::read()) return false;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _sensor->distanceCm();
#else
  return true;
#endif
}
