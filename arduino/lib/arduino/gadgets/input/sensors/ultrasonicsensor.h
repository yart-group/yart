#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "gadgets/input/sensor.h"
#include "general/config.h"

class UltrasonicSensor : public Sensor
{
  public:
    UltrasonicSensor() : _sensor(nullptr) {}

    virtual bool powerOff_addons();
    virtual bool init_addons();

    virtual bool reconnect_addons();

    virtual double read_addons();

  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeUltrasonicSensor * _sensor;
#else
    int * _sensor;
#endif
};

#endif // ULTRASONICSENSOR_H
