#ifndef MOTOR_H
#define MOTOR_H

#include "outputgadget.h"
#include "general/config.h"

class Motor : public OutputGadget
{
  public:
    Motor() : _motor(nullptr) {}

    void setPowerOff();

    bool reconnect();
    bool loop() { return true; }

    void write(double data);


  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeDCMotor * _motor;
#else
    int * _motor;
#endif
};

#endif // MOTOR_H
