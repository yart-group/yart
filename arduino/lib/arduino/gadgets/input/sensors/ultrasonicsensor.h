#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "gadgets/input/sensor.h"
#include "general/config.h"

class UltrasonicSensor : public Sensor
{
  public:
    UltrasonicSensor();

    //Device
    virtual void powerOff();

    virtual void loop() {}

    //Gadget
    virtual void refresh();

    //InputGadget
    virtual double read();

  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeUltrasonicSensor * _sensor;
#else
    int * _sensor;
#endif
};

#endif // ULTRASONICSENSOR_H
