#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "../sensor.h"
#include "../../../../../general/config.h"

class UltrasonicSensor : public Sensor
{
  public:
    void setPowerOff();

    bool reconnect();
    bool loop();

    double read();

    UltrasonicSensor();

  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeUltrasonicSensor * _sensor;
#else
    int * _sensor;
#endif
};

//*******************************************************************//

inline UltrasonicSensor::UltrasonicSensor() :
  _sensor(nullptr)
{}

inline bool UltrasonicSensor::loop(){
  if(! Sensor::loop()) return false;
  return true;
}



#endif // ULTRASONICSENSOR_H
