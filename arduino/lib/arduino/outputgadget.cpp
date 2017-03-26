#include "outputgadget.h"

void OutputGadget::write(const char *data, int size)
{
  if(powerCheck())
    write_addons(data, size);
}

void OutputGadget::write(double data)
{
  if(powerCheck())
    write_addons(data);
}
