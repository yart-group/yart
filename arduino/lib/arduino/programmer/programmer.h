#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "device.h"
#include "devices/robot.h"
#include "gadget.h"
#include "port.h"

class Programmer : public Device
{
  public:
    friend class Port;
    friend class Kernel;
//    class Port; // Preprocessor error (#include loop)
    class Kernel;

    Programmer();

    virtual bool powerOff_addons();
    virtual bool init_addons();

    void plug(Gadget * gadget);
    void plug(Robot * robot);

    void load(Kernel * kernel);

  private:
    Gadget ** _gadget;
    int _gadgets;

    Robot * _robot;
    Kernel * _kernel;
};

#include "kernel.h"

#endif // PROGRAMMER_H
