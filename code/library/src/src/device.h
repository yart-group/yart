#ifndef DEVICE_H
#define DEVICE_H

#include "general/meta.h"
#include "debugmanager.h"

class Device
{
  public:
    enum State {
      WORKING,
      NOT_WORKING
    };

    Meta meta;

    Device() : _power(false), _state(NOT_WORKING), meta(Meta::Device) {}

    virtual bool init() { if(isPowerEnabled() && !isWorking()) { _state = WORKING; return true; } return false; }
    virtual int getState() { return _state; }
    virtual bool isWorking() { return (_state == WORKING); }

    virtual bool isPowerEnabled() { return _power; }
    virtual void setPower(bool on) { if(on) setPowerOn(); else setPowerOff(); }
    virtual void setPowerOn() { _power = true; }
    virtual void setPowerOff() { _power = false; _state = NOT_WORKING; }

    virtual bool isDebugEnabled() { return debug.isEnabled(); }
    virtual void setDebug(bool on) { if(on) setDebugOn(); else setDebugOff(); }
    virtual void setDebugOn() { debug.setOn(); }
    virtual void setDebugOff() { debug.setOff(); }

  protected:
    int _state;
    DebugManager debug;

  private:
    bool _power;

};

#endif // DEVICE_H
