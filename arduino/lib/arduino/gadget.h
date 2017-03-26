#ifndef GADGET_H
#define GADGET_H

#include "device.h"
#include "programmer/port.h"

class Gadget : public Device
{
  public:
    //Device
    virtual void init() { refresh(); }

    Gadget();

    Port port;

    virtual void refresh() = 0;
};

#endif // GADGET_H
