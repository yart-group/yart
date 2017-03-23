#ifndef ROBOT_H
#define ROBOT_H

#include "component.h"
#include "chassis.h"
#include "programmer.h"
#include "../../devices/include/ultrasonicsensor.h"

class Robot : public Component
{
  public:
    Programmer _programmer;
    Chassis _chassis;
    UltrasonicSensor _ultrasonicSensor;

};

#endif // ROBOT_H
