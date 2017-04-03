#include "infraredsensor.h"

void InfraredSensor::setPowerOff()
{
  Sensor::setPowerOff();
  if(_sensor) delete _sensor;
  _sensor = nullptr;
}

bool InfraredSensor::reconnect()
{
  if(port.isUsable() == false) return false;

  if(_sensor) delete _sensor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor = new MeInfraredSensor( port.getPort() );
  _sensor->begin();
#else
  _sensor = new int;
#endif

  return true;
}

bool InfraredSensor::loop()
{
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor->loop();
#endif
  return true;
}

double InfraredSensor::read()
{
  if(! isWorking()) return -1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _sensor->getCode();
#else
  return 0;
#endif
}
