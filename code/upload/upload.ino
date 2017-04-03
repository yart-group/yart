#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MeOrion.h>

#define COMPILE_FOR_ARDUINO_UPLOAD true
#include "/home/robert/Projects/current/Goofy/code/library/tarball/libarduino.h"

//*********************************************************************************************//
//*********************************************************************************************//
//*********************************************************************************************//

class Drive : public Program
{
  public:
    Drive() { strcpy(meta.name, "drive"); }

    int main(int argc, const char * const *argv);
};

int Drive::main(int /*argc*/, const char * const */*argv*/)
{
  int exit_code = _kernel->command("move 100");
  if(exit_code == -1) /*cout << " > unknown command " << endl*/ ;
}

//*********************************************************************************************//

class BasicMovement : public Driver
{
  public:
    BasicMovement() { strcpy(meta.name, "basic_movement"); }

    int controller(int argc, const char * const *argv);
    bool install();
    bool uninstall();

    void move(int speed);
};

int BasicMovement::controller(int argc, const char * const *argv)
{
  if(argc != 2) return -1;
  if(strcmp(argv[0], "move")) return -1;

  move(100);

  return 0;
}
bool BasicMovement::install()
{
  return _kernel->_commandTable.add("echo", this);
}
bool BasicMovement::uninstall()
{
  return _kernel->_commandTable.del("echo", this);
}
void BasicMovement::move(int speed)
{
  OutputGadget * motor_left =  static_cast<OutputGadget *>( _kernel->_motherboard->get(Meta("left motor",  Meta::OutputGadget)) );
  OutputGadget * motor_right = static_cast<OutputGadget *>( _kernel->_motherboard->get(Meta("right motor", Meta::OutputGadget)) );

  motor_left->write(speed);
  motor_right->write(speed);

  delay(3000);

  motor_left->write(0);
  motor_right->write(0);
}

//*********************************************************************************************//
//*********************************************************************************************//
//*********************************************************************************************//

void setup() {
  Serial.begin(9600);

  Serial.println("creating hardware ...");
  
  Robot robot;
  Motherboard motherboard;

  Serial.println("creating kernel ...");
  
  Kernel kernel;

  Serial.println("creating software ...");
  
  Drive program;
  BasicMovement driver;

  Serial.println("power on ...");

  motherboard.setPowerOn();
  robot.setPowerOn();

  Serial.println("init ...");

  robot.init();
  motherboard.init();

  Serial.println("mount ...");
  
  robot.mount(&motherboard);

  Serial.println("load ...");

  motherboard.load(&kernel);

  Serial.println("run ...");
  
  kernel.run();

  Serial.print("load driver: ");
  Serial.println( kernel.load(&driver) );

  Serial.print("load program: ");
  Serial.println( kernel.load(&program) );

  Serial.print("start driver: ");
  Serial.println( kernel.start(Meta("basic_movement", Meta::Driver)) );

  Serial.print("start program: ");
  Serial.println( kernel.start(Meta("drive", Meta::Program)) );  
}

void loop() {
  // put your main code here, to run repeatedly:
  
}


//*********************************************************************************************//
#include "/home/robert/Projects/current/Goofy/code/library/tarball/libarduino.cpp"
