
class Program_0 : public Program {
  public:
    Program_0();
  
    void assign(Robot * robot) { if(robot) program_0::robot = robot; }
    void assign(Pilot * pilot) { if(pilot) program_0::pilot = pilot; }

  private:
    Robot * robot;
    Pilot * pilot;

};

Program_0::Program_0() : 
  robot(nullptr),
  pilot(nullptr)
{}

ExitCode Program_0::init() {
  return ok;
}

ExitCode Program_0::run() {
  if(!robot) return startup_error;
  if(!pilot) return startup_error;

  while( pilot->getCode() != Pilot::button_B )
  {
    pilot->loop();
    if(pilot->getLast() == Pilot::button_UP){
      robot->move(Robot::FORWARD, 100);
    }
    if(pilot->getLast() == Pilot::button_LEFT){
      robot->move(Robot::LEFT, 100);
    }
    if(pilot->getLast() == Pilot::button_RIGHT){
      robot->move(Robot::RIGHT, 100);
    }
    if(pilot->getLast() == Pilot::button_DOWN){
      robot->move(Robot::BACK, 100);
    }
    if(pilot->getLast() == Pilot::button_START){
      robot->move(Robot::FORWARD, 0);
    }
  }

  robot->move(Robot::FORWARD, 0);

  return ok;
}
