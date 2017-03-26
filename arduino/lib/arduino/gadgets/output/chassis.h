#ifndef CHASSIS_H
#define CHASSIS_H

#include "outputgadget.h"
#include "motor.h"
#include "general/config.h"

class Chassis : public OutputGadget
{
  public:
    Chassis() :
      _motorLeft(nullptr),
      _motorRight(nullptr)
    {}

    virtual bool powerOff_addons();
    virtual bool init_addons();

    virtual bool reconnect_addons();

    virtual void write_addons(const char * data, int size = 0);
    virtual void write_addons(double data);

  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    Motor * _motorLeft;
    Motor * _motorRight;
#else
    int * _motorLeft;
    int * _motorRight;
#endif
};

#endif // CHASSIS_H
