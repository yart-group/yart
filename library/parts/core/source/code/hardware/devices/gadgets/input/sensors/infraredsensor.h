#ifndef INFRAREDSENSOR_H
#define INFRAREDSENSOR_H

#include "../sensor.h"
#include "../../../../../general/config.h"

class InfraredSensor : public Sensor
{
  public:
    void setPowerOff();

    bool reconnect();
    bool loop();

    double read();

    InfraredSensor();

  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeInfraredReceiver * _sensor;
#else
    int * _sensor;
#endif
};

//************************************************************************//

inline InfraredSensor::InfraredSensor() :
  _sensor(nullptr)
{}

#endif // INFRAREDSENSOR_H
