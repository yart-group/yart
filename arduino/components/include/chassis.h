#ifndef CHASSIS_H
#define CHASSIS_H

#include "component.h"
#include "../../devices/include/motor.h"

class Chassis : public Component
{
  public:
    enum Direction {
      LEFT,
      RIGHT,
      FORWARD,
      BACK,
      STOP,
      ARC_FL,
      ARC_FR,
      ARC_BL,
      ARC_BR
    };

    void move(Direction direction, Motor::Speed speed);
    Motor::Speed getSpeed() { return _currentSpeed; }


  private:
    Motor _motorLeft;
    Motor _motorRight;

    Direction _currentDirection;
    Motor::Speed _currentSpeed;
};

#endif // CHASSIS_H
