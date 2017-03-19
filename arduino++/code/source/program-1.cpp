
class Program_0 : public Program {
  public:
    Program_0();

    virtual ExitCode init();
    virtual ExitCode run();

    void assign(Robot * robot) { if(robot) Program_0::robot = robot; }
    void assign(Pilot * pilot) { if(pilot) Program_0::pilot = pilot; }

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

Program_0::Program_0() :
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

Program_0::ExitCode Program_0::init() {
  return ok;
}

Program_0::ExitCode Program_0::run() {
  if(!robot) return startup_error;
  if(!pilot) return startup_error;

  while( (pilotCode = pilot->getCode()) != Pilot::button_B )
  {
    pilot->loop();

    if(pilotCode != button_START){
        if(pause == false){
          pilotCode = Pilot::button_UP;
        }
    }


    /// Safety
    if(safety){

      if(!inDanger)
      {
        if(robot->getUltrasonicValue() <= safeDistance){
          robot->move(Robot::STOP, 0);
          inDanger = true;
          if(pilotCode == Pilot::button_UL || pilotCode == Pilot::button_UP || pilotCode == Pilot::button_UR)
            continue;
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

        continue;
      }

    }

    // Basic movement
    if(pilotCode == Pilot::button_UP){
      robot->move(Robot::FORWARD, speed);
    }

    // Stop
    else if(pilotCode == Pilot::button_START){
      pause = !pause;
      if(pause) robot->move(Robot::STOP, 0);
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

  robot->move(Robot::STOP, 0);

  return ok;
}
