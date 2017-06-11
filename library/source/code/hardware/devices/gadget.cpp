#include "gadget.h"

bool Gadget::init()
{
  if( ! Device::init() ) return false;

  if( ! reconnect() )
    wreck(Device::NOT_WORKING);

  return isWorking();
}
