#include "device.h"

void Device::powerOff()
{
  if ( powerOff_addons() == false ) return ;
  power.setOff();
  _state = NOT_WORKING;
}
void Device::init()
{
  if(power.enabled() == false) return ;
  if(_state == WORKING) return ;
  if( init_addons() == false ) return ;
  _state = WORKING;
}

bool Device::powerCheck()
{
  if(power.enabled() == false){
    powerOff();
    return false;
  }
  return true;
}
