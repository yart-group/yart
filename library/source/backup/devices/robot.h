#ifndef ROBOT_H
#define ROBOT_H

#include "device.h"
#include "gadgets/input/sensors/ultrasonicsensor.h"
#include "gadgets/output/motor.h"

class Motherboard;

class Robot : public Device
{
  public:
    Robot();

    bool init();
    void setPowerOn();
    void setPowerOff();

    bool mount(Motherboard * motherboard);
    bool unmount();
    bool motherboardMounted();


  private:
    Motor _leftMotor;
    Motor _rightMotor;
    UltrasonicSensor _ultrasonicSensor;

    Motherboard * _motherboard;
};

#endif // ROBOT_H
