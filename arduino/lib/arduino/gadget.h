#ifndef GADGET_H
#define GADGET_H

#include "device.h"
#include "general/port.h"
#include "general/meta.h"

class Gadget : public Device
{
  public:
    Gadget() : meta(Meta::Gadget) {}

    Port port;
    Meta meta;

    virtual bool reconnect() = 0;
    virtual bool loop() = 0;

    bool init();
};

#endif // GADGET_H
