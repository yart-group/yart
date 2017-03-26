#include "gadget.h"

bool Gadget::reconnect()
{
  if(powerCheck())
    return reconnect_addons();
  else
    return false;
}
void Gadget::loop()
{
  if(powerCheck())
    loop_addons();
}
