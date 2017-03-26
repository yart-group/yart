#include "motor.h"

Motor::Motor() : _motor(nullptr)
{

}

void Motor::powerOff()
{
  delete _motor;
  _motor = nullptr;
  _state = NOT_WORKING;
}

void Motor::refresh()
{
  if(power.enabled() == false){
    powerOff();
    return ;
  }

  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return;

  if(_motor) delete _motor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motor = new MeDCMotor( port.getPort() );
#else
  _motor = new int;
#endif
  _state = WORKING;
}

void Motor::write(const char *data, int size)
{
  if(power.enabled() == false){
    powerOff();
    return ;
  }

  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return;
  if(_state != WORKING) return;

  // null
}

void Motor::write(double data)
{
  if(power.enabled() == false){
    powerOff();
    return ;
  }

  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return;
  if(_state != WORKING) return;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motor->run(data);
#else
  // null
#endif
}
