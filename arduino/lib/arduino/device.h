#ifndef DEVICE_H
#define DEVICE_H

#include "general/switch.h"

class Device
{
  public:
    Device() : _state(NOT_WORKING) {}

    Switch power;
    Switch debug;
    Switch freeze;

    virtual void init();

    enum State {
      WORKING,
      NOT_WORKING
    };

    virtual int state() { return _state; }

  protected:
    int _state;

    virtual void powerOff();

    virtual bool powerOff_addons() = 0;
    virtual bool init_addons() = 0;

    virtual bool powerCheck();
};

#endif // DEVICE_H
