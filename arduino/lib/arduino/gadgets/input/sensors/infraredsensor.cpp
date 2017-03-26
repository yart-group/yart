#include "infraredsensor.h"

bool InfraredSensor::powerOff_addons()
{
  delete _sensor;
  _sensor = nullptr;
  return true;
}

bool InfraredSensor::init_addons()
{
  return reconnect();
}

bool InfraredSensor::reconnect_addons()
{
  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return false;
  if(port.usable() == false) return false;

  if(_sensor) delete _sensor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor = new MeInfraredSensor( port.getPort() );
  _sensor->begin();
#else
  _sensor = new int;
#endif

  return true;
}

void InfraredSensor::loop_addons()
{
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor->loop();
#endif
}

double InfraredSensor::read_addons()
{
  if(debug.enabled()){
    // debug msg
  }

  if(_state != WORKING) return -1;
  if(freeze.enabled()) return -1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _sensor->getCode();
#else
  return 0;
#endif
}
