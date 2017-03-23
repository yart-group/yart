#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void move(double direction, double speed);
double LEFT;
double RIGHT;
double FORWARD;
double BACK;
MeDCMotor motor_9(9);
MeDCMotor motor_10(10);
void PROGRAM_1();
double DIRECTION;
double STAND;
MeInfraredReceiver ir_6(6);
MeUltrasonicSensor ultrasonic_3(3);
void PROGRAM_0();


void move(double direction, double speed)
{
    if(((direction)==(LEFT))){
        motor_9.run(speed);
        motor_10.run(speed);
    }
    
    if(((direction)==(RIGHT))){
        motor_9.run((0) - (speed));
        motor_10.run((0) - (speed));
    }
    
    if(((direction)==(FORWARD))){
        motor_9.run((0) - (speed));
        motor_10.run(speed);
    }
    
    if(((direction)==(BACK))){
        motor_9.run(speed);
        motor_10.run((0) - (speed));
    }
    
}

void PROGRAM_1()
{
    move(FORWARD,100);
    
    DIRECTION += FORWARD;
    
    while(!(((ir_6.getCode())==(12))))
    {
        _loop();
        if((ultrasonic_3.distanceCm()) < (20)){
            move(RIGHT,100);
            _delay(2);
            move(FORWARD,0);
            _delay(1);
            move(DIRECTION,100);
        }
    }
    
    move(FORWARD,0);
    
    DIRECTION += STAND;
    
}

void PROGRAM_0()
{
    while(!(((ir_6.getCode())==(22))))
    {
        _loop();
        if(((ir_6.getCode())==(25))){
            move(BACK,100);
            DIRECTION += BACK;
        }
        if(((ir_6.getCode())==(64))){
            move(FORWARD,100);
            DIRECTION += FORWARD;
        }
        if(((ir_6.getCode())==(7))){
            move(LEFT,100);
            DIRECTION += LEFT;
        }
        if(((ir_6.getCode())==(9))){
            move(RIGHT,100);
            DIRECTION += RIGHT;
        }
        if(((ir_6.getCode())==(21))){
            move(FORWARD,0);
            DIRECTION += STAND;
        }
    }
    
    move(FORWARD,0);
    
    DIRECTION += STAND;
    
}


void setup(){
    ir_6.begin();
    LEFT = 0;
    RIGHT = 1;
    FORWARD = 2;
    BACK = 3;
    STAND = 4;
    DIRECTION = FORWARD;
    
}

void loop(){
    
    if(((ir_6.getCode())==(22))){
        _delay(1);
        PROGRAM_0();
        _delay(1);
    }
    if(((ir_6.getCode())==(12))){
        _delay(1);
        PROGRAM_1();
        _delay(1);
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    ir_6.loop();
    
    
}

