#include <MeOrion.h>

enum
{
  STOP, FORWARD, BACKWARD, LEFT, RIGHT, 
  ALL, ZERO
};

MeLineFollower lineFinder(PORT_3);
MeDCMotor motor_A(PORT_9), motor_B(PORT_10);
int SPEED = 255;
int sensorState = 0;
int mode = RIGHT;
int code;
int previousCode = RIGHT;
short currentDirection = STOP;
bool kappa = true;

bool needToChange = false;

//************************************************
void move(short direction, short speed, short gate = 12);
void move(short direction, short speed, short gate)
{
  if(direction == currentDirection) return; 
  
  switch (direction)
  {
    case STOP:
      motor_A.run(0);
      motor_B.run(0);
      break;
    case FORWARD:
      motor_A.run(-speed);
      motor_B.run(speed);
      break;
    case BACKWARD:
      motor_A.run(speed);
      motor_B.run(-speed);
      break;
    case LEFT:
      motor_A.run(speed);
      motor_B.run(speed);
      break;
    case RIGHT:
      motor_A.run(-speed);
      motor_B.run(-speed);
      break;
  }
  while(read() == gate) ;
}
//************************************************
int read()
{
  sensorState = lineFinder.readSensors();
  switch(sensorState)
  {
    case S1_OUT_S2_OUT: return ALL;
    case S1_OUT_S2_IN: return RIGHT;
    case S1_IN_S2_OUT: return LEFT;
    case S1_IN_S2_IN: return ZERO;
  }
}
//************************************************
void switchMode(){
  if(mode == LEFT) mode = RIGHT;
  else mode = LEFT;
}
//************************************************
void setup()
{
  Serial.begin(9600);
}
//************************************************
void loop()
{ 
  code = read();
  if(code == mode || code == ALL){
    move(FORWARD, SPEED);
    currentDirection = FORWARD;
  }
  else if(code == ZERO){
    if(previousCode == ALL){
      switchMode();
    } 
    move(mode, SPEED, ZERO);
    currentDirection = mode;
  }
  else{
    switchMode();
//    if(kappa) Serial.print(">");
//    Serial.println("> SWITCH");
    kappa = !kappa;
    
  }
  
  
  if(code != previousCode && code != ZERO) previousCode = code;
}
