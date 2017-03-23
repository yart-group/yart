#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#include "device.h"

class InputDevice : public Device
{
  public:
    virtual void write(const char * data, int size = 0) = 0;
};

#endif // INPUTDEVICE_H
