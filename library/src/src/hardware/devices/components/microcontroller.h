#ifndef MICROCONTROLLER_H
#define MICROCONTROLLER_H

#include "../component.h"
#include "../../../programmable.h"
class Robot;

// pro tip: DO NOT USE PUBLIC Component::gadget INTERFACE!!! thanks.
class Microcontroller : public Component, public Programmable
{
  public:
    bool plugRobot(Robot * robot);
    bool unplugRobot(int id);
    bool isRobotPlugged(int id);
    int getPluggedRobotsAmount();

  private:
    vector<int> _ids;
};

#endif // MICROCONTROLLER_H
