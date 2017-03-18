class Robot {
  public:
    typedef float Time;
    enum Direction {
      LEFT,
      RIGHT,
      FORWARD,
      BACK,
      STAND,
      ARC_FL,
      ARC_FR,
      ARC_BL,
      ARC_BR
    };
    
    void move(Direction direction, Motors::Speed speed);
    void delay(Time seconds);

    Direction getDirection() { return currentDirection; }
    Motors::Speed getSpeed() { return currentSpeed; }

    
  private:
    UltrasonicSensor sensor;
    Motors motors;

    Direction currentDirection;
    Motors::Speed currentSpeed;

};

void Robot::move(Direction direction, Motors::Speed speed) {
  
  bool gate = false;
  
  if(direction == LEFT){
    motors.setSpeed(-100, 100);
  }
  else if(direction == RIGHT){
    motors.setSpeed(100, -100);
  }
  else if(direction == FORWARD){
    motors.setSpeed(speed);
  }
  else if(direction == BACK){
    motors.setSpeed(-speed);
  }
  else{
    motors.setSpeed(0);
    currentDirection = STAND;
    currentSpeed = 0;
    gate = true;
  }

  if(!gate){
    currentDirection = direction;
    currentSpeed = speed;
    gate = true;
  }
}

void Robot::delay(Time seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime) ; //_loop();
}








