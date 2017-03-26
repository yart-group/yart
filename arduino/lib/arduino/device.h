#ifndef DEVICE_H
#define DEVICE_H

#include "general/switch.h"

class Device
{
  public:
    Device();

    Switch power;
    Switch debug;
    Switch freeze;

    virtual void powerOff() = 0;

    virtual void init() = 0;
    virtual void loop() {}

    enum State {
      WORKING,
      NOT_WORKING
    };

    virtual int state() { return _state; }

  protected:
    int _state;
};

#endif // DEVICE_H
