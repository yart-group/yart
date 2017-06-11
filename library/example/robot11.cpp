#include <vector>
#include <memory>
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
class Monitrable {};

class Device : public Turnable, public Debuggable, public Monitorable
{
  // ...
};

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


int main() {




}
