#ifndef DEVICE_H
#define DEVICE_H

#include "../hardware.h"

class Device : public Hardware
{
  public:
    class Meta;
    enum State { WORKING, NOT_WORKING };

    Meta meta;

    virtual bool init();
    virtual int getState();
    virtual bool isWorking();

    virtual bool isPowerEnabled();
    virtual void setPower(bool on);
    virtual void setPowerOn();
    virtual void setPowerOff();

    virtual bool isDebugEnabled();
    virtual void setDebug(bool on);
    virtual void setDebugOn();
    virtual void setDebugOff();

    Device();

  protected:
    DebugManager _debug;

  private:
    bool _power;
    int _state;

};

//************************************************************************//

inline Device::Device() :
  _power(false),
  _state(NOT_WORKING)
{}

inline bool Device::init(){
  if(isPowerEnabled() && !isWorking())
  {
    _state = WORKING; return true;
  }
  return false;
}
inline int Device::getState(){
  return _state;
}
inline bool Device::isWorking(){
  return (_state == WORKING);
}

inline bool Device::isPowerEnabled(){
  return _power;
}
inline void Device::setPower(bool on){
  if(on)
    setPowerOn();
  else
    setPowerOff();
}
inline void Device::setPowerOn(){
  _power = true;
}
inline void Device::setPowerOff(){
  _power = false;
  _state = NOT_WORKING;
}

inline bool Device::isDebugEnabled(){
  return _debug.isEnabled();
}
inline void Device::setDebug(bool on){
  if(on)
    setDebugOn();
  else
    setDebugOff();
}
inline void Device::setDebugOn(){
  _debug.setOn();
}
inline void Device::setDebugOff(){
  _debug.setOff();
}

#endif // DEVICE_H
