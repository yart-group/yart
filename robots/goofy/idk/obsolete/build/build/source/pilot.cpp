
class Pilot {
  public:
    enum Code {
      button_A = 69,
      button_B = 70,
      button_C = 71,
      button_D = 68,
      button_E = 67,
      button_F = 13,
      
      button_UP    = 64,
      button_DOWN  = 25,
      button_LEFT  = 7,
      button_RIGHT = 9,
      button_START = 21,
      
      button_0 = 22,
      button_1 = 12,
      button_2 = 24,
      button_3 = 94,
      button_4 = 8,
      button_5 = 28,
      button_6 = 90,
      button_7 = 66,
      button_8 = 82,
      button_9 = 74,

      button_UL = button_D,
      button_UR = button_E,
      button_DL = button_0,
      button_DR = button_F,
    };

    Code getCode() { return (lastCode = translate( sensor.read() ) ); }
    Code getLast() { return lastCode; }

    Code translate(IrSensor::Value value);

    void init() { sensor.init(); }
    void loop() { sensor.loop(); }
  
  private:
    IrSensor sensor;
    Code lastCode;
    
};

Pilot::Code Pilot::translate(IrSensor::Value value)
{
  Code code;
  
  switch( value ) {
    case 69: code = button_A; break; 
    case 70: code = button_B; break; 
    case 71: code = button_C; break; 
    case 68: code = button_D; break; 
    case 67: code = button_E; break; 
    case 13: code = button_F; break; 

    case 64: code = button_UP; break; 
    case 25: code = button_DOWN; break; 
    case 7:  code = button_LEFT; break; 
    case 9:  code = button_RIGHT; break; 
    case 21: code = button_START; break; 

    case 22: code = button_0; break; 
    case 12: code = button_1; break; 
    case 24: code = button_2; break; 
    case 94: code = button_3; break; 
    case 8:  code = button_4; break; 
    case 28: code = button_5; break; 
    case 90: code = button_6; break; 
    case 66: code = button_7; break; 
    case 82: code = button_8; break; 
    case 74: code = button_9; break; 
  }
  
  return code;
}




