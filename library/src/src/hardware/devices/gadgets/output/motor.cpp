#include "motor.h"

void Motor::setPowerOff()
{
  if(_motor) delete _motor;
  _motor = nullptr;
  OutputGadget::setPowerOff();
}


bool Motor::reconnect()
{
  if(! OutputGadget::reconnect()) return false;

  if(port.isUsable() == false) return false;

  if(_motor) delete _motor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motor = new MeDCMotor( port.getPort() );
#else
  _motor = new int;
#endif

  return true;
}

bool Motor::write(double data)
{
  if(! OutputGadget::write(data)) return false;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motor->run(data);
#endif

  return true;
}
