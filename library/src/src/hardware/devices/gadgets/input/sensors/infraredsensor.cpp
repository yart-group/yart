#include "infraredsensor.h"

void InfraredSensor::setPowerOff()
{
  if(_sensor) delete _sensor;
  _sensor = nullptr;
  Sensor::setPowerOff();
}

bool InfraredSensor::reconnect()
{
  if(! Sensor::reconnect()) return false;

  if(port.isUsable() == false) return false;

  if(_sensor) delete _sensor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor = new MeInfraredReceiver( port.getPort() );
  _sensor->begin();
#else
  _sensor = new int;
#endif

  return true;
}

bool InfraredSensor::loop()
{
  if(! Sensor::loop()) return false;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor->loop();
#endif

  return true;
}

double InfraredSensor::read()
{
  if(! Sensor::read()) return false;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _sensor->getCode();
#else
  return true;
#endif
}
