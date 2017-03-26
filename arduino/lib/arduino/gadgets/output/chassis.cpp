#include "chassis.h"

Chassis::Chassis() : _motorLeft(nullptr), _motorRight(nullptr)
{

}

void Chassis::powerOff()
{
  delete _motorLeft;
  delete _motorRight;
  _motorLeft = nullptr;
  _motorRight = nullptr;
  _state = NOT_WORKING;
}

void Chassis::refresh()
{
  if(power.enabled() == false){
    powerOff();
    return ;
  }

  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return;

  if(_motorLeft) delete _motorLeft;
  if(_motorRight) delete _motorRight;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motorLeft = new Motor(  );
  _motorLeft = new Motor(  );
#else
  _motorLeft = new int;
  _motorLeft = new int;
#endif

  //@TODO: handle: port, init(), loop() etc.
  _state = WORKING;
}

void Chassis::write(const char *data, int size)
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

void Chassis::write(double data)
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
  _motorLeft->write(data);
  _motorRight->write(data);
#else
  // null
#endif
}
