#include <vector>
#include <memory>
#include <string>
using namespace std;

#include <libarduino_api>
#include <libarduino_goofy_gadgets>
#include <libarduino_basic_components>

#include <interfaces> // Monitorable, Turnable, Debuggable, Stream, Programmable

#include <hardware> // Device -> IOGadget
#include <gadgets> // UltrasonicSensor, InfraredSensor, Motor, BatterySensor
#include <devices> // Pilot, Microcontroller, Usb, FlashDrive
#include <robots>  // Goofy

#include <software> // Software -> Kernel::Driver
#include <kernel> // kernel
#include <kernel/drivers> // kernel drivers

// Library / Toolkit for programming robots in easy way

namespace libarduino {
  namespace hardware {
    namespace interfaces {}
    namespace gadgets {}
    namespace devices {}
  }
  namespace software {
    namespace interfaces {}
  }
}

/*
 * library
 * |- hardware
 * |  |- gadgets
 * |  '- devices
 * |
 * |- software
 *    '- kernel
 *        |- drivers
 *        '- programs
 *
 *
 *
 * library
 * gadgets
 * devices
 * kernel
 * soft
 * simulator
 *
 * namespace avrrobot
 * namespace interface
 * namespace hardware
 * namespace hardware::interfaces
 * namespace software
 *
 */


class Turnable {};
class Debuggable {};
class Monitorable {};

class Device : public Turnable, public Debuggable, public Monitorable
{
  // ...
};

class MyLogger : public Logger
{
    public:
        ostream & operator<< (string text){
            return cout << text;
        }
};

MyLogger x;
x << "cos" << " tam";

_debug << "debug message" << endl;
_debug.add( new Logger); / del / get
_debug : Turnable;


using Hardware = Device;

class Stream // : InputStream, OutputStream
{
  public:
    Stream & operator<< ();
    Stream & operator>> ();
};

class Gadget : public Device, public Stream
{
  // ...
};

class Programmable {};

class Microcontroller : public Device, public Programmable
{}

class Robot : public Device
{
  public:
    Robot();


  private:
    vector<unique_ptr<Gadget>> gadgets;
    Microcontroller microcontroller;
};

Robot::Robot() {
  gadgets.push_back(new UltrasonicSensor);
  gadgets.push_back(new InfraredSensor);
  gadgets.push_back(new Motor);
  gadgets.push_back(new Motor);

  microcontroller.upload(new Kernel);
}




template <typename T>
class OutputGadget : public Gadget
{
    public:
        virtual T read() const = 0;
};

class InfraredSensor : public OutputGadget
{
    public:
        int read() const { return 10; }

};

class UltrasonicSensor : public OutputGadget
{
    public:
        double read() const { return 3.14; }
};

class Keyboard : public OutputGadget
{
    public:
        string read() const { return "keyboard output"; }
};

using Number = double;
using NumberOutputGadget = OutputGadget<Number>;

using Text = string;
using TextOutputGadget = OutputGadget<Text>;

int main() {
    shared_ptr<NumberOutputGadget> gadget1 { new InfraredSensor };
    shared_ptr<NumberOutputGadget> gadget2 { new UltrasonicSensor };

    auto v1 = gadget1->read();
    auto v2 = gadget2->read();

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    any a = 10;
    any b = "asd";
    any c = DebugManager();

    vector<shared_ptr<OutputGadget<string>>> wektor;

    auto x = wektor.begin();
}



///---------///


template<typename T>
class Logger
{
  public:
    virtual Logger & operator<<(T output) = 0;
};

class DebugManager
{
  public:
    vector<shared_ptr<Logger>> loggers;

    template<typename T>
    DebugManager & operator<<(T output){
      for(auto v : loggers){
        *v << output;
      }
      return * this;
    }
};

class CoutLogger : public Logger<string>
{
  public:
    template<typename T>
    CoutLogger & operator<<(T output){
      cout << output;
      return * this;
    }
};

class CerrLogger : public Logger<string>
{
  public:
    template<typename T>
    CerrLogger & operator<<(T output){
      cerr << "cerr(" << output << ")";
      return * this;
    }
};

int main()
{
  DebugManager dm;

  dm.loggers.push_back(shared_ptr<Logger> { new CoutLogger } );
  dm.loggers.push_back(shared_ptr<Logger> { new CerrLogger } );

  dm << "tekst" << 10 << 'x' << ' ' << 3.14 ;//<< endl;
}




