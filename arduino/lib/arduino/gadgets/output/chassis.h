#ifndef CHASSIS_H
#define CHASSIS_H

#include "outputgadget.h"
#include "motor.h"
#include "general/config.h"

class Chassis : public OutputGadget
{
  public:
    Chassis();

    //Device
    virtual void powerOff();

    virtual void loop() {}

    //Gadget
    virtual void refresh();

    //OutputGadget
    virtual void write(const char * data, int size = 0);
    virtual void write(double data);

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
