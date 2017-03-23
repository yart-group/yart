#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "sensor.h"

class UltrasonicSensor : public Sensor
{
  public:

  private:
    MeUltrasonicSensor _sensor;
};

#endif // ULTRASONICSENSOR_H
