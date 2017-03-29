#ifndef DEVICE_H
#define DEVICE_H

class Device
{
  public:
    enum State {
      WORKING,
      NOT_WORKING
    };

    Device() : _power(false), _state(NOT_WORKING), _debug(false) {}

    virtual bool init() { if(powerEnabled() && !working()) { _state = WORKING; return true; } return false; }
    virtual int state() { return _state; }
    virtual bool working() { return (_state == WORKING); }

    virtual bool powerEnabled() { return _power; }
    virtual void setPower(bool on) { if(on) powerOn(); else powerOff(); }
    virtual void powerOn() { _power = true; }
    virtual void powerOff() { _power = false; _state = NOT_WORKING; }

    virtual bool debugEnabled() { return _debug; }
    virtual void setDebug(bool on) { if(on) debugOn(); else debugOff(); }
    virtual void debugOn() { _debug = true; }
    virtual void debugOff() { _debug = false; }

  protected:
    bool _power;
    int _state;
    bool _debug;

};

#endif // DEVICE_H
