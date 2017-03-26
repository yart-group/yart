#include "programmer.h"

Programmer::Programmer() :
  _gadget(new *Gadget[10]),
  _gadgets(0),
  _robot(nullptr),
  _kernel(nullptr)
{}

bool Programmer::powerOff_addons()
{
  return true;
}

bool Programmer::init_addons()
{
  return true;
}

void Programmer::plug(Gadget *gadget)
{
  if(!gadget) return;
  _gadget[_gadgets] = gadget;
  _gadgets++;
}

void Programmer::plug(Robot *robot)
{
  if(robot) _robor = robot;
}

void Programmer::load(Kernel *kernel)
{
  if(kernel) _kernel = kernel;
}
