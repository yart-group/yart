#ifndef MOTOR_H
#define MOTOR_H

#include "outputdevice.h"

class Motor : public OutputDevice
{
  public:
    typedef int Speed;
    typedef int Distance;

    virtual void stop();
    virtual void setSpeed(Speed speed);
    virtual Speed getSpeed();

    virtual void distance(bool on);
    virtual void distanceOn();
    virtual void distanceOff();
    virtual void distanceEnabled();
    virtual void resetDistance();
    virtual void setDistance(Distance distance);
    virtual Distance getDistance();

    virtual void distanceToStop(bool on);
    virtual void distanceToStopOn();
    virtual void distanceToStopOff();
    virtual void distanceToStopEnabled();
    virtual void resetDistanceToStop();
    virtual void setDistanceToStop(Distance distance);
    virtual Distance getDistanceToStop();



  private:
    MeDCMotor _motor;

    bool _distance;
    bool _distanceToStop;

    Speed _currentSpeed;
    Distance _currentDistance;
    Distance _distanceToStop;
};

#endif // MOTOR_H
