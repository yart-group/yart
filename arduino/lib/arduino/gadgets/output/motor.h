#ifndef MOTOR_H
#define MOTOR_H

#include "outputgadget.h"
#include "general/config.h"
#include "general/switch.h"

class Motor : public OutputGadget
{
  public:
    Motor();

    typedef int Speed;
    typedef int Distance;

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
    MeDCMotor * _motor;
#else
    int * _motor;
#endif
};

#endif // MOTOR_H
