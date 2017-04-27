#include <MeOrion.h>

MeLineFollower lineFinder(PORT_3);
MeDCMotor motor_A(PORT_9), motor_B(PORT_10);

void move(byte direction, byte speed, byte gate = 0x44);
enum
{
  STOP, FORWARD, BACKWARD, LEFT, RIGHT
};

//************************************************
//****************** PROGRAM *********************
//************************************************

byte SPEED = 255;
byte mode = 0x0f;
byte code;
byte previousCode = mode;

void setup()
{
  Serial.begin(9600);
}

void loop()
{ 
  code = read();

  if(code == mode || code == 0xff)
    move(FORWARD, SPEED);
  else if(code == 0x00)
  {
    if(previousCode == 0xff) mode = ~mode;
    move(mode, SPEED, 0x00);
  }
  else
    mode = ~mode; 
 
  if(code != previousCode && code != 0x00) previousCode = code;
}

//************************************************
//************************************************
//************************************************
byte currentDirection = STOP;
void move(byte direction, byte speed, byte gate)
{
  if( direction == currentDirection) return; 
  
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
    case 0xf0:
      motor_A.run(speed);
      motor_B.run(speed);
      break;
    case RIGHT:
    case 0x0f:
      motor_A.run(-speed);
      motor_B.run(-speed);
      break;
  }

  currentDirection = direction;
  
  while(read() == gate) ;
}

//************************************************

byte read()
{
  byte sensorState = lineFinder.readSensors();
  switch(sensorState)
  {
    case S1_OUT_S2_OUT: return 0xff;
    case S1_OUT_S2_IN: return 0x0f;
    case S1_IN_S2_OUT: return 0xf0;
    case S1_IN_S2_IN: return 0x00;
  }
}
