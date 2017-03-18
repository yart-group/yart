class Robot {
  public:
    Robot() : currentDirection(STOP) {}

    typedef float Time;
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

    void move(Direction direction, Motors::Speed speed);
    void delay(Time seconds);

    Direction getDirection() { return currentDirection; }
    Motors::Speed getSpeed() { return currentSpeed; }

    UltrasonicSensor::Value getUltrasonicValue() { return sensor.read(); }


  private:
    UltrasonicSensor sensor;
    Motors motors;

    Direction currentDirection;
    Motors::Speed currentSpeed;

};

void Robot::move(Direction direction, Motors::Speed speed) {

  if(direction == LEFT){
    motors.setSpeed(-speed, speed);
  }
  else if(direction == RIGHT){
    motors.setSpeed(speed, -speed);
  }
  else if(direction == FORWARD){
    motors.setSpeed(speed);
  }
  else if(direction == BACK){
    motors.setSpeed(-speed);
  }
  else if(direction == ARC_FL){
    motors.setSpeed(speed-(0.5 * speed), speed+(0.5 * speed));
  }
  else if(direction == ARC_FR){
    motors.setSpeed(speed+(0.5 * speed), speed-(0.5 * speed));
  }
  else if(direction == ARC_BL){
    motors.setSpeed( -(speed-(0.5 * speed)), -(speed+(0.5 * speed)));
  }
  else if(direction == ARC_BR){
    motors.setSpeed( -(speed+(0.5 * speed)), -(speed-(0.5 * speed)));
  }
  else{
    motors.setSpeed(0);
  }

  currentDirection = direction;
  currentSpeed = speed;
}

void Robot::delay(Time seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime) ; //_loop();
}
