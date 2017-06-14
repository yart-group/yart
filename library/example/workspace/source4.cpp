
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Monitorable {};
class Device {};

class Software : public Monitorable
{
  public:
    int main(vector<string> args);

  private:
    shared_ptr<Programmable> _device;
};

class Programmable
{
  public:
    bool uploadSoftware(shared_ptr<Software> software);
    bool removeSoftware();
    shared_ptr<Software> getSoftware();
    bool isProgrammed();

    // gadget accesors


  private:
    shared_ptr<Software> _software;
};


class Microcontroller : public Device, public Programmable
{
  public:

};


struct Goofy
{
  Microcontroller _microcontroller;
  OutputGadget<double> _leftMotor;
  OutputGadget<double> _rightMotor;
  InputGadget<int> _infraredSensor;
  InputGadget<double> _ultrasonicSensor;


};

class Pilot {};
