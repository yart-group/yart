
class Program_1 : public Program {
  public:
    Program_1();

    virtual ExitCode init();
    virtual ExitCode run();

    void assign(Robot * robot) { if(robot) Program_1::robot = robot; }
    void assign(Pilot * pilot) { if(pilot) Program_1::pilot = pilot; }

  private:
    Robot * robot;
    Pilot * pilot;

    Pilot::Code pilotCode;

    Robot::Time time;
    bool pause;

    bool safety;
    bool inDanger;
    const UltrasonicSensor::Value safeDistance;

    const Motors::Speed defaultSpeed;
    const Motors::Speed speedUnit;
    const Motors::Speed maxSpeed;

    Motors::Speed speed;

};

Program_1::Program_1() :
  robot(0),
  pilot(0),

  pilotCode(Pilot::button_START),

  time(0),
  pause(false),

  safety(true),
  inDanger(false),
  safeDistance(20),

  defaultSpeed(100),
  speedUnit(50),
  maxSpeed(250),

  speed(defaultSpeed)
{}

Program_1::ExitCode Program_1::init() {
  return ok;
}

Program_1::ExitCode Program_1::run() {
  if(!robot) return startup_error;
  if(!pilot) return startup_error;

  pause = false;
  speed = defaultSpeed;
  inDanger = false;

  while( (pilotCode = pilot->getCode()) != Pilot::button_B )
  {
    pilot->loop();

    speed= defaultSpeed;

    // // Stop
    // if(pilotCode == Pilot::button_START){
    //   pause = !pause;
    // }
    //
    // // Settings
    // else if(pilotCode == Pilot::button_2){
    //   if(speed + speedUnit <= maxSpeed){
    //     speed += speedUnit;
    //     //robot->move(robot->getDirection(), speed);
    //   }
    // }
    // else if(pilotCode == Pilot::button_5){
    //   speed = defaultSpeed;
    //   //robot->move(robot->getDirection(), speed);
    // }
    // else if(pilotCode == Pilot::button_8){
    //   if(speed - speedUnit > 0){
    //     speed -= speedUnit;
    //     //robot->move(robot->getDirection(), speed);
    //   }
    // }
    //
    // if(pause){
    //   robot->move(Robot::STOP, 0);
    //   continue;
    // }

    /// Safety

      if(inDanger == false)
      {
        if(robot->getUltrasonicValue() <= safeDistance){
          robot->move(Robot::STOP, 0);
          inDanger = true;
          continue;
        }else{
          robot->move(Robot::FORWARD, speed);
        }
      }

      else
      {
        //obrot
        time = random(1,(3)+1);

        if(random(1,(2)+1) == 1){
          robot->move(Robot::LEFT, speed);
        }else{
          robot->move(Robot::RIGHT, speed);
        }

        robot->delay(time);
        robot->move(Robot::STOP, 0);

        if(robot->getUltrasonicValue() > safeDistance){
          long endTime = millis() + 300;
          while(millis() < endTime) ;
          if(robot->getUltrasonicValue() > safeDistance){
            long endTime = millis() + 300;
            while(millis() < endTime) ;
            if(robot->getUltrasonicValue() > safeDistance)
              inDanger = false;
          }
        }

        if(inDanger == false) robot->move(Robot::FORWARD, speed);
        else robot->move(Robot::STOP, 0);
      }

  }

  robot->move(Robot::STOP, 0);

  return ok;
}
