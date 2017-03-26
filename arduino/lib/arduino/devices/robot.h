#ifndef ROBOT_H
#define ROBOT_H

#include "device.h"
#include "gadgets/input/sensors/ultrasonicsensor.h"
#include "gadgets/output/chassis.h"
//#include "programmer/programmer.h" // preprocessor error (#include loop)
class Programmer;

// @TODO: wszystko :)

class Robot : public Device
{
  public:
    Robot();

    virtual void powerOff() {}

    virtual void init() {}


    void mount(Programmer * /*programmer*/) {}

  private:
    Chassis _chassis;
    UltrasonicSensor _ultrasonicSensor;

    Programmer * _programmer;
};

#endif // ROBOT_H
