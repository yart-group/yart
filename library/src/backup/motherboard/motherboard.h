#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "general/meta.h"
#include "device.h"
#include "devices/robot.h"
#include "gadget.h"

class Kernel;

class Motherboard : public Device
{
  public:
    friend class Kernel;

    Motherboard();

    void setPowerOff();

    int gadgets(){ return _gadgets; }
    bool plug(Gadget * gadget);
    bool plug(Robot * robot);
    bool unplug(Gadget * gadget);
    bool unplug();
    bool unplug(Meta meta);
    bool plugged();
    bool plugged(Gadget * gadget);
    bool plugged(Robot * robot);
    bool plugged(Meta meta);
    Gadget * get(Meta meta);
    bool load(Kernel * kernel);
    bool unload();
    Kernel * kernel(){ if(! isWorking()) return nullptr; return _kernel; }

  private:
    Kernel * _kernel;
    Robot * _robot;

    int _gadgets;
    Gadget ** _gadget;
};

//#include "kernel.h"

#endif // PROGRAMMER_H