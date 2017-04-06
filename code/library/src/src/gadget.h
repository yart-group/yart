#ifndef GADGET_H
#define GADGET_H

#include "device.h"
#include "general/port.h"
#include "general/meta.h"

class Gadget : public Device
{
  public:
    Gadget() { meta.type = Meta::Gadget; }

    Port port;

    virtual bool reconnect() = 0;
    virtual bool loop() = 0;

    bool init();
};

#endif // GADGET_H
