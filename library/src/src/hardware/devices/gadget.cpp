#include "gadget.h"

bool Gadget::init()
{
  if( ! Device::init() ) return false;

  if( ! reconnect() )
    _state = NOT_WORKING;

  return isWorking();
}
