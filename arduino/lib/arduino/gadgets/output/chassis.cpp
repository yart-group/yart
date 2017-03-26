#include "chassis.h"

void Chassis::powerOff_addons()
{
  delete _motorLeft;
  delete _motorRight;
  _motorLeft = nullptr;
  _motorRight = nullptr;
  return true;
}

bool Chassis::init_addons()
{
  return reconnect();
}

bool Chassis::reconnect_addons()
{
  if(debug.enabled()){
    // debug msg
  }

  if(freeze.enabled()) return false;
  if(port.usable() == false) return false;

  if(_motorLeft) delete _motorLeft;
  if(_motorRight) delete _motorRight;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motorLeft = new Motor(  );
  _motorLeft = new Motor(  );
#else
  _motorLeft = new int;
  _motorLeft = new int;
#endif

  return true;
}

void Chassis::write_addons(const char *data, int size)
{
  if(debug.enabled()){
    // debug msg
  }

  if(_state != WORKING) return;
  if(freeze.enabled()) return;

  // null
}

void Chassis::write_addons(double data)
{
  if(debug.enabled()){
    // debug msg
  }

  if(_state != WORKING) return;
  if(freeze.enabled()) return;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motorLeft->write(data);
  _motorRight->write(data);
#endif
}
