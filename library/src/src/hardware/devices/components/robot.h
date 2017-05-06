#ifndef ROBOT_H
#define ROBOT_H

#include "../component.h"
class Microcontroller;

class Robot : public Component
{
  public:
    bool mountMicrocontroller(Microcontroller * microcontroller);
    bool unmountMicrocontroller();
    bool isMicrocontrollerMounted();

    Robot();

  private:
    Microcontroller * _microcontroller;
};

inline Robot::Robot() :
  _microcontroller(nullptr)
{}

inline bool Robot::isMicrocontrollerMounted(){
  return ! (_microcontroller == nullptr);
}

#endif // ROBOT_H
