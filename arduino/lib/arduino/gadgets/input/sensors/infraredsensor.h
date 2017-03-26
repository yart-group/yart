#ifndef INFRAREDSENSOR_H
#define INFRAREDSENSOR_H

#include "gadgets/input/sensor.h"
#include "general/config.h"

class InfraredSensor : public Sensor
{
  public:
    InfraredSensor();

    //Device
    virtual void powerOff();

    virtual void loop() {
#if COMPILE_FOR_ARDUINO_UPLOAD == true
      _sensor->loop();
#else
      // null
#endif
    }

    //Gadget
    virtual void refresh();

    //InputGadget
    virtual double read();

  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeInfraredSensor * _sensor;
#else
    int * _sensor;
#endif
};

#endif // INFRAREDSENSOR_H
