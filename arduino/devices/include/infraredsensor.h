#ifndef INFRAREDSENSOR_H
#define INFRAREDSENSOR_H

#include "sensor.h"

class InfraredSensor : public Sensor
{
  public:

  private:
    MeInfraredReceiver _sensor;
};

#endif // INFRAREDSENSOR_H
