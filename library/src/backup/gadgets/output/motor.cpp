#include "motor.h"

void Motor::setPowerOff()
{
  OutputGadget::setPowerOff();
  if(_motor) delete _motor;
  _motor = nullptr;
}


bool Motor::reconnect()
{
  if(port.isUsable() == false) return false;

  if(_motor) delete _motor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motor = new MeDCMotor( port.getPort() );
#else
  _motor = new int;
#endif

  return true;
}

void Motor::write(double data)
{
  if(! isWorking()) return;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motor->run(data);
#endif
}
