
class Program_2 : public Program {
  public:
    Program_2();

    virtual ExitCode init();
    virtual ExitCode run();

    void assign(Robot * robot) { if(robot) Program_2::robot = robot; }
    void assign(Pilot * pilot) { if(pilot) Program_2::pilot = pilot; }

  private:
    Robot * robot;
    Pilot * pilot;

    Pilot::Code pilotCode;

    bool safety;
    bool inDanger;
    const UltrasonicSensor::Value safeDistance;

    const Motors::Speed defaultSpeed;
    const Motors::Speed speedUnit;
    const Motors::Speed maxSpeed;

    // Motor::Speed leftArcSpeed;
    // Motor::Speed rightArcSpeed;
    Motors::Speed speed;


};

Program_2::Program_2() :
  robot(0),
  pilot(0),

  pilotCode(Pilot::button_START),

  safety(true),
  inDanger(false),
  safeDistance(20),

  defaultSpeed(100),
  speedUnit(50),
  maxSpeed(250),

  speed(defaultSpeed)
{}

Program_2::ExitCode Program_2::init() {
  return ok;
}

Program_2::ExitCode Program_2::run() {
  if(!robot) return startup_error;
  if(!pilot) return startup_error;

  while( (pilotCode = pilot->getCode()) != Pilot::button_B )
  {
    pilot->loop();

    /// Safety
    if(safety){

      if(!inDanger){
        if(robot->getUltrasonicValue() <= safeDistance){
          robot->move(Robot::FORWARD, 0);
          inDanger = true;
        }
      }

      else{
        if(pilotCode == Pilot::button_UL || pilotCode == Pilot::button_UP || pilotCode == Pilot::button_UR)
          continue;

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
      }

    }

    // Safety control
    if(pilotCode == Pilot::button_A){
      safety = true;
    }
    else if(pilotCode == Pilot::button_C){
      safety = false;
    }

    // Basic movement
    else if(pilotCode == Pilot::button_UP){
      robot->move(Robot::FORWARD, speed);
    }
    else if(pilotCode == Pilot::button_LEFT){
      robot->move(Robot::LEFT, speed);
    }
    else if(pilotCode == Pilot::button_RIGHT){
      robot->move(Robot::RIGHT, speed);
    }
    else if(pilotCode == Pilot::button_DOWN){
      robot->move(Robot::BACK, speed);
    }

    // Stop
    else if(pilotCode == Pilot::button_START){
      robot->move(Robot::STOP, 0);
    }

    // Arc movement
    else if(pilotCode == Pilot::button_UL){
      robot->move(Robot::ARC_FL, speed);
    }
    else if(pilotCode == Pilot::button_UR){
      robot->move(Robot::ARC_FR, speed);
    }
    else if(pilotCode == Pilot::button_DL){
      robot->move(Robot::ARC_BL, speed);
    }
    else if(pilotCode == Pilot::button_DR){
      robot->move(Robot::ARC_BR, speed);
    }

    // Settings
    else if(pilotCode == Pilot::button_2){
      if(speed + speedUnit <= maxSpeed){
        speed += speedUnit;
        robot->move(robot->getDirection(), speed);
      }
    }
    else if(pilotCode == Pilot::button_5){
      speed = defaultSpeed;
      robot->move(robot->getDirection(), speed);
    }
    else if(pilotCode == Pilot::button_8){
      if(speed - speedUnit > 0){
        speed -= speedUnit;
        robot->move(robot->getDirection(), speed);
      }
    }



  }

  robot->move(Robot::FORWARD, 0);

  return ok;
}
