#ifndef GADGET_H
#define GADGET_H

#include "../device.h"
#include "../meta.h"
#include "port.h"

class Gadget : public Device
{
  public:
    Port port;

    virtual bool reconnect();
    virtual bool loop();

    Gadget();

    bool init();
};

//************************************************************************//

inline Gadget::Gadget(){
  meta.setType(Device::Meta::Gadget);
}

inline bool Gadget::reconnect(){
  if(! isPowerEnabled()) return false;
  return true;
}

inline bool Gadget::loop(){
  if(! isWorking()) return false;
  return true;
}


#endif // GADGET_H
