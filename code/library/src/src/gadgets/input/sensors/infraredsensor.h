#ifndef INFRAREDSENSOR_H
#define INFRAREDSENSOR_H

#include "gadgets/input/sensor.h"
#include "general/config.h"

class InfraredSensor : public Sensor
{
  public:
    InfraredSensor() : _sensor(nullptr) {}

    void setPowerOff();

    bool reconnect();
    bool loop();

    double read();

  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeInfraredReceiver * _sensor;
#else
    int * _sensor;
#endif
};

#endif // INFRAREDSENSOR_H
