#ifndef PILOT_H
#define PILOT_H

#include "../component.h"
#include "../gadgets/input/sensors/infraredsensor.h"

class Pilot : public Device
{
  public:
    enum Code {
      button_A = 69,
      button_B = 70,
      button_C = 71,
      button_D = 68,
      button_E = 67,
      button_F = 13,

      button_UP    = 64,
      button_DOWN  = 25,
      button_LEFT  = 7,
      button_RIGHT = 9,
      button_START = 21,

      button_0 = 22,
      button_1 = 12,
      button_2 = 24,
      button_3 = 94,
      button_4 = 8,
      button_5 = 28,
      button_6 = 90,
      button_7 = 66,
      button_8 = 82,
      button_9 = 74,

      button_UL = button_D,
      button_UR = button_E,
      button_DL = button_0,
      button_DR = button_F,
    };

    int getCode();
    int getLast();

    bool init();
    void setPowerOn();
    void setPowerOff();

    Pilot();

  private:
    InfraredSensor _infraredSensor;
    int _lastCode;
};

//**********************************************************************//

inline Pilot::Pilot() :
  _lastCode(false)
{}

#endif // PILOT_H
