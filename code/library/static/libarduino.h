
#ifndef CONFIG_H
#define CONFIG_H

#ifndef COMPILE_FOR_ARDUINO_UPLOAD
  #define COMPILE_FOR_ARDUINO_UPLOAD false
#endif

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  #warning use it only as with .tgz version of library
  ////kappa "portable/sketchbook/libraries/makeblock/src/MeOrion.h"
#endif

#endif // CONFIG_H
#ifndef GLOBAL_H
#define GLOBAL_H

//kappa "config.h"

#if COMPILE_FOR_ARDUINO_UPLOAD == false
  #include <cstring>
#else

  #define nullptr 0

  char * strcpy(char *a, const char *b);
  int strcmp(const char * a, const char * b);
#endif

#endif // GLOBAL_H
#ifndef PORT_H
#define PORT_H


class Port
{
  public:
    Port();

    bool isUsable() { return _usable; }

    bool setPort(int port);
    int getPort();

  private:
    bool _usable;
    int _port;

    int _min;
    int _max;
};

#endif // PORT_H
#ifndef META_H
#define META_H

#include <cstring>

class Meta
{
  public:
    enum Type {
      Unknown = -1,
      Device,
      Gadget,
      InputGadget,
      OutputGadget,
      IOGadget,
      Program,
      Driver,
      Logger
    };

    Meta(const char * name_ = "unknown", int type_ = Unknown) : name(new char[20]), type(type_) {
      strcpy(name, name_);
    }

    Meta(int type_) : name(new char[20]), type(type_) {
      strcpy(name, "unknown");
    }

    char * const name;
    int type;
};

#endif // META_H
#ifndef LOGGER_H
#define LOGGER_H

//kappa "general/meta.h"

class Logger
{
  public:
    Logger() : meta(Meta::Logger) {}

    Meta meta;

    virtual Logger & operator << (const char * data) = 0;
    virtual Logger & operator << (double data) = 0;
    virtual Logger & operator << (Meta data) = 0;
};

#endif // LOGGER_H
#ifndef DEBUGMANAGER_H
#define DEBUGMANAGER_H

//kappa "logger.h"

class DebugManager
{
  public:
    DebugManager();

    DebugManager & operator << (const char * data);
    DebugManager & operator << (double data);
    DebugManager & operator << (Meta data);

    bool add(Logger * logger);
    bool del(Logger * logger);

    bool isEnabled() { return _enabled; }
    void set(bool on) { if(on) setOn(); else setOff(); }
    void setOn() { _enabled = true; }
    void setOff() { _enabled = false; }

  private:
    bool _enabled;

    Logger **_logger;
    int _loggers;
};

#endif // DEBUGMANAGER_H
#ifndef DEVICE_H
#define DEVICE_H

//kappa "general/meta.h"
//kappa "debugmanager.h"

class Device
{
  public:
    enum State {
      WORKING,
      NOT_WORKING
    };

    Meta meta;

    Device() : _power(false), _state(NOT_WORKING), meta(Meta::Device) {}

    virtual bool init() { if(isPowerEnabled() && !isWorking()) { _state = WORKING; return true; } return false; }
    virtual int getState() { return _state; }
    virtual bool isWorking() { return (_state == WORKING); }

    virtual bool isPowerEnabled() { return _power; }
    virtual void setPower(bool on) { if(on) setPowerOn(); else setPowerOff(); }
    virtual void setPowerOn() { _power = true; }
    virtual void setPowerOff() { _power = false; _state = NOT_WORKING; }

    virtual bool isDebugEnabled() { return debug.isEnabled(); }
    virtual void setDebug(bool on) { if(on) setDebugOn(); else setDebugOff(); }
    virtual void setDebugOn() { debug.setOn(); }
    virtual void setDebugOff() { debug.setOff(); }

  protected:
    int _state;
    DebugManager debug;

  private:
    bool _power;

};

#endif // DEVICE_H
#ifndef GADGET_H
#define GADGET_H

//kappa "device.h"
//kappa "general/port.h"
//kappa "general/meta.h"

class Gadget : public Device
{
  public:
    Gadget() { meta.type = Meta::Gadget; }

    Port port;

    virtual bool reconnect() = 0;
    virtual bool loop() = 0;

    bool init();
};

#endif // GADGET_H
#ifndef INPUTGADGET_H
#define INPUTGADGET_H

//kappa "gadget.h"

class InputGadget : public Gadget
{
  public:
    InputGadget() { meta.type = Meta::InputGadget; }

    virtual double read() = 0;
};

#endif // INPUTGADGET_H
#ifndef OUTPUTGADGET_H
#define OUTPUTGADGET_H

//kappa "gadget.h"

class OutputGadget : public Gadget
{
  public:
    OutputGadget() { meta.type = Meta::OutputGadget; }

    virtual void write(double data) = 0;
};

#endif // OUTPUTGADGET_H
#ifndef IOGADGET_H
#define IOGADGET_H

//kappa "inputgadget.h"
//kappa "outputgadget.h"

class IOGadget : public InputGadget, public OutputGadget
{
  public:
    IOGadget() : meta(Meta::IOGadget) { OutputGadget::meta.type = InputGadget::meta.type = Meta::IOGadget; }

    Meta meta;
};

#endif // IOGADGET_H
#ifndef CABLE_H
#define CABLE_H

//kappa "iogadget.h"

class Cable : public IOGadget
{
  public:
};

#endif // CABLE_H
#ifndef MOTOR_H
#define MOTOR_H

//kappa "outputgadget.h"
//kappa "general/config.h"

class Motor : public OutputGadget
{
  public:
    Motor() : _motor(nullptr) {}

    void setPowerOff();

    bool reconnect();
    bool loop() { return true; }

    void write(double data);


  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeDCMotor * _motor;
#else
    int * _motor;
#endif
};

#endif // MOTOR_H
#ifndef BATTERY_H
#define BATTERY_H

//kappa "iogadget.h"

class Battery : public InputGadget
{
  public:
};

#endif // BATTERY_H
#ifndef SENSOR_H
#define SENSOR_H

//kappa "inputgadget.h"

class Sensor : public InputGadget
{
  public:
};

#endif // SENSOR_H
#ifndef INFRAREDSENSOR_H
#define INFRAREDSENSOR_H

//kappa "gadgets/input/sensor.h"
//kappa "general/config.h"

class InfraredSensor : public Sensor
{
  public:
    InfraredSensor() : _sensor(nullptr) {}

    void setPowerOff();

    bool reconnect();
    bool loop();

    double read();

  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeInfraredReceiver * _sensor;
#else
    int * _sensor;
#endif
};

#endif // INFRAREDSENSOR_H
#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

//kappa "gadgets/input/sensor.h"
//kappa "general/config.h"

class UltrasonicSensor : public Sensor
{
  public:
    UltrasonicSensor() : _sensor(nullptr) {}

    void setPowerOff();

    bool reconnect();
    bool loop() { return true; }

    double read();


  private:
#if COMPILE_FOR_ARDUINO_UPLOAD == true
    MeUltrasonicSensor * _sensor;
#else
    int * _sensor;
#endif
};

#endif // ULTRASONICSENSOR_H
#ifndef FLASH_H
#define FLASH_H

//kappa "device.h"

class Flash : public Device
{
  public:
    Flash();
};

#endif // FLASH_H
#ifndef USB_H
#define USB_H

//kappa "device.h"

class Usb : public Device
{
  public:
    Usb();
};

#endif // USB_H
#ifndef PILOT_H
#define PILOT_H

//kappa "device.h"
//kappa "gadgets/input/sensors/infraredsensor.h"

class Pilot : public Device
{
  public:
    Pilot() : _lastCode(0) {}

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

    bool init();
    void setPowerOn();
    void setPowerOff();

    int getCode();
    int getLast();

  private:
    InfraredSensor _infraredSensor;
    int _lastCode;
};

#endif // PILOT_H
#ifndef ROBOT_H
#define ROBOT_H

//kappa "device.h"
//kappa "gadgets/input/sensors/ultrasonicsensor.h"
//kappa "gadgets/output/motor.h"

class Motherboard;

class Robot : public Device
{
  public:
    Robot();

    bool init();
    void setPowerOn();
    void setPowerOff();

    bool mount(Motherboard * motherboard);
    bool unmount();
    bool motherboardMounted();


  private:
    Motor _leftMotor;
    Motor _rightMotor;
    UltrasonicSensor _ultrasonicSensor;

    Motherboard * _motherboard;
};

#endif // ROBOT_H
#ifndef PROGRAMMER_H
#define PROGRAMMER_H

//kappa "general/meta.h"
//kappa "device.h"
//kappa "devices/robot.h"
//kappa "gadget.h"

class Kernel;

class Motherboard : public Device
{
  public:
    friend class Kernel;

    Motherboard();

    void setPowerOff();

    int gadgets(){ return _gadgets; }
    bool plug(Gadget * gadget);
    bool plug(Robot * robot);
    bool unplug(Gadget * gadget);
    bool unplug();
    bool unplug(Meta meta);
    bool plugged();
    bool plugged(Gadget * gadget);
    bool plugged(Robot * robot);
    bool plugged(Meta meta);
    Gadget * get(Meta meta);
    bool load(Kernel * kernel);
    bool unload();
    Kernel * kernel(){ if(! isWorking()) return nullptr; return _kernel; }

  private:
    Kernel * _kernel;
    Robot * _robot;

    int _gadgets;
    Gadget ** _gadget;
};

////kappa "kernel.h"

#endif // PROGRAMMER_H
#ifndef PROGRAM_H
#define PROGRAM_H

//kappa "general/meta.h"
class Kernel;

class Program
{
  public:
    Program() : lastMsg(nullptr), meta(Meta::Program), _kernel(nullptr) {}

    virtual int main(int argc = 0, char const * const * argv = 0) = 0;
    bool pair(Kernel * kernel);
    bool unpair();
    bool paired();

    char * lastMsg;
    virtual int controller(int /*argc*/, char const * const * /*argv*/) { return -1; }
    virtual bool install() { return false; }
    virtual bool uninstall() { return false; }

    Meta meta;
  protected:
    Kernel * _kernel;

};

#endif // PROGRAM_H
#ifndef DRIVER_H
#define DRIVER_H

//kappa "program.h"

class Driver : public Program
{
  public:
    Driver();

    int main(int argc = 0, char const * const * argv = 0);

    virtual int controller(int argc, char const * const * argv) = 0;
    virtual bool install() = 0;
    virtual bool uninstall() = 0;
};

#endif // DRIVER_H
#ifndef PROGRAMCONTAINER_H
#define PROGRAMCONTAINER_H

//kappa "program.h"

class ProgramContainer
{
  public:
    ProgramContainer();

    bool add(Program * program);
    bool remove(Program * program);
    bool remove(Meta meta);
    bool check(Program * program);
    bool check(Meta meta);
    Program * get(Meta meta);

  private:
    Program ** _table;
    int _loads;
};

#endif // PROGRAMCONTAINER_H
#ifndef COMMANDTABLE_H
#define COMMANDTABLE_H

//kappa "program.h"

class CommandTable
{
  public:
    CommandTable();

    bool add(const char * cmd, Program * driver);
    bool del(const char * cmd, Program * driver);
    int exec(int argc, char const * const * argv);

  private:
    int _commands;
    const char ** _command;
    Program ** _driver;

};

#endif // COMMANDTABLE_H
#ifndef KERNEL_H
#define KERNEL_H

//kappa "general/meta.h"
//kappa "motherboard.h"
//kappa "programcontainer.h"
//kappa "driver.h"
//kappa "commandtable.h"

class Kernel
{
  public:
    friend class Program;
    friend class Driver;
    friend class CommandTable;

    Kernel() : _enabled(false), _motherboard(nullptr) {}

    bool run();
    bool quit();
    bool load(Program * program);
    bool unload(Meta meta);
    bool start(Meta meta);
    bool stop(Meta meta);
    int command(const char * cmd);

    CommandTable _commandTable;
  private:
    bool _enabled;
    Motherboard * _motherboard;
    ProgramContainer _programs;
    ProgramContainer _drivers;
    ProgramContainer _startedPrograms;
    ProgramContainer _startedDrivers;

};

#endif // KERNEL_H
