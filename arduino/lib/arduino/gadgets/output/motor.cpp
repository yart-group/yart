#include "motor.h"

bool Motor::powerOff_addons()
{
  delete _motor;
  _motor = nullptr;
  return true;
}

bool Motor::init_addons()
{
  return reconnect();
}

bool Motor::reconnect_addons()
{
  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return false;
  if(port.usable() == false) return false;

  if(_motor) delete _motor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motor = new MeDCMotor( port.getPort() );
#else
  _motor = new int;
#endif

  return true;
}

void Motor::write_addons(const char *data, int size)
{
  if(debug.enabled()){
    // debug msg
  }

  if(_state != WORKING) return;
  if(freeze.enabled()) return;

  // null
}

void Motor::write_addons(double data)
{
  if(debug.enabled()){
    // debug msg
  }

  if(_state != WORKING) return;
  if(freeze.enabled()) return;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motor->run(data);
#endif
}
