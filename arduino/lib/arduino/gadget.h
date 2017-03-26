#ifndef GADGET_H
#define GADGET_H

#include "device.h"
#include "programmer/port.h"

class Gadget : public Device
{
  public:
    Gadget() {}

    Port port;
    virtual bool reconnect();
    virtual void loop();

  protected:
    virtual bool reconnect_addons() = 0;
    virtual void loop_addons() {}
};

#endif // GADGET_H
