

#define MOTOR_A_PORT 9
#define MOTOR_B_PORT 10

class Motors {
  public:
    Motors() : motor_A(MOTOR_A_PORT), motor_B(MOTOR_B_PORT) {}
    
    typedef int Speed;
    typedef int Distance;

    void setSpeed(Speed speed);
    void setSpeed(Speed speed_left, Speed speed_right);

    Speed getSpeed()       { return CurrentSpeed_left ; }
    Speed getSpeed_left()  { return CurrentSpeed_left ; }
    Speed getSpeed_right() { return CurrentSpeed_right; }
     
  private:
    MeDCMotor motor_A;
    MeDCMotor motor_B;
  
    Speed      CurrentSpeed_left;
    Speed      CurrentSpeed_right;
    Distance   CurrentDistance;

    void setMotorASpeed(Speed speed) { motor_A.run(-speed); CurrentSpeed_left  = speed; }
    void setMotorBSpeed(Speed speed) { motor_B.run( speed); CurrentSpeed_right = speed; }
};

void Motors::setSpeed(Speed speed) {
  setMotorASpeed(speed);
  setMotorBSpeed(speed);
}

void Motors::setSpeed(Speed speed_left, Speed speed_right) {
  setMotorASpeed(speed_left);
  setMotorBSpeed(speed_right);
}
