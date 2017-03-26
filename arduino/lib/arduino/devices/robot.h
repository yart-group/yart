#ifndef ROBOT_H
#define ROBOT_H

#include "device.h"
#include "gadgets/input/sensors/ultrasonicsensor.h"
#include "gadgets/output/chassis.h"
//#include "programmer/programmer.h" // preprocessor error (#include loop)
class Programmer;

class Robot : public Device
{
  public:
    Robot() : _programmer(nullptr) {}

    virtual bool powerOff_addons();
    virtual bool init_addons();


    void mount(Programmer * programmer);

  private:
    Chassis _chassis;
    UltrasonicSensor _ultrasonicSensor;

    Programmer * _programmer;
};

#endif // ROBOT_H
