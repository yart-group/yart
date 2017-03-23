#ifndef OUTPUTDEVICE_H
#define OUTPUTDEVICE_H

#include "device.h"

class OutputDevice : public Device
{
  public:
    virtual double read() = 0;
};

#endif // OUTPUTDEVICE_H
