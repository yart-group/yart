

#define ULTRASONIC_PORT 3

class UltrasonicSensor {
  public:
    UltrasonicSensor() : ultrasonic(ULTRASONIC_PORT) {}
    typedef double Value;
  
    Value read() { return ultrasonic.distanceCm(); }
  
  private:
    MeUltrasonicSensor ultrasonic;
};





#define IR_PORT 6

class IrSensor {
  public:
    IrSensor() : ir(IR_PORT) {}
    typedef int Value;

    Value read() { return ir.getCode(); }

    void init() { ir.begin(); }
    void loop() { ir.loop();  }
    
  private:
    MeInfraredReceiver ir;
};

