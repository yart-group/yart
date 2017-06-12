#ifndef MOTOR_H
#define MOTOR_H

#include "../../outputgadget.h"
#include "../../../../general/config.h"

class Motor : public OutputGadget
{
  public:
    void setPowerOff();

    bool reconnect();
    bool loop();

    bool write(double data);

    Motor();

  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeDCMotor * _motor;
#else
    int * _motor;
#endif
};

//******************************************************************//

inline Motor::Motor() :
  _motor(nullptr)
{}

inline bool Motor::loop(){
  if(! OutputGadget::loop()) return false;
  return true;
}

#endif // MOTOR_H
