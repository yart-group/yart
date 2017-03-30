#ifndef ROBOT_H
#define ROBOT_H

#include "device.h"
#include "gadgets/input/sensors/ultrasonicsensor.h"
#include "gadgets/output/motor.h"

class Programmer;

class Robot : public Device
{
  public:
    Robot();

    bool init();
    void powerOn();
    void powerOff();

    bool mount(Programmer * programmer);
    bool unmount();
    bool programmerMounted();


  private:
    Motor _leftMotor;
    Motor _rightMotor;
    UltrasonicSensor _ultrasonicSensor;

    Programmer * _programmer;
};

#endif // ROBOT_H
