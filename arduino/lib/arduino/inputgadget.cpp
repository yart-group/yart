#include "inputgadget.h"

double InputGadget::read()
{
  if(powerCheck())
    return read_addons();
  else
    return -1;
}
