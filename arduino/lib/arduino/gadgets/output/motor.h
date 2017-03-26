#ifndef MOTOR_H
#define MOTOR_H

#include "outputgadget.h"
#include "general/config.h"
#include "general/switch.h"

class Motor : public OutputGadget
{
  public:
    Motor() : _motor(nullptr) {}

    virtual bool powerOff_addons();
    virtual bool init_addons();

    virtual bool reconnect_addons();

    virtual void write_addons(const char * data, int size = 0);
    virtual void write_addons(double data);

  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeDCMotor * _motor;
#else
    int * _motor;
#endif
};

#endif // MOTOR_H
