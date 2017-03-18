

#define ULTRASONIC_PORT 3

class UltrasonicSensor {
  public:
    typedef double Value;
  
    Value read() { return ultrasonic.distanceCm(); }
  
  private:
    MeUltrasonicSensor ultrasonic(ULTRASONIC_PORT);
};





#define IR_PORT 6

class IrSensor {
  public:
    typedef int Value;

    Value read() { return ir.getCode(); }

    void init() { ir.begin(); }
    void loop() { ir.loop();  }
    
  private:
    MeInfraredReceiver ir(IR_PORT);
};

