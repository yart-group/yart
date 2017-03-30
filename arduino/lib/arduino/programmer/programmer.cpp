#include "programmer.h"

Programmer::Programmer() :
  _kernel(nullptr),
  _robot(nullptr),
  _gadgets(0),
  _gadget(nullptr)
{
  _gadget = new Gadget*[10];
  for(int i=0; i<10; i++) _gadget[i] = nullptr;
}

void Programmer::powerOff()
{
  Device::powerOff();
  unload();
}

bool Programmer::plug(Gadget *gadget)
{
  if(!gadget) return false;

  for(int i=0; i<_gadgets; i++)
    if(_gadget[i] == gadget || !strcmp(_gadget[i]->meta.name, gadget->meta.name))
       return false;

  _gadget[_gadgets] = gadget;
  _gadgets++;
  return true;

}
bool Programmer::plug(Robot *robot)
{
  if(!robot) return false;
  if(plugged()) return false;
  _robot = robot;
  return true;
}

bool Programmer::unplug(Gadget *gadget)
{
  if(!gadget) return false;

  for(int i=0; i<_gadgets; i++){
    if(_gadget[i] == gadget){
      for(; i<_gadgets-1; i++){
        _gadget[i] = _gadget[i+1];
      }
      _gadget[i] = nullptr;
      _gadgets--;
      return true;
    }
  }

  return false;
}
bool Programmer::unplug()
{
  if(!plugged()) return false;
  _robot = nullptr;
  return true;
}
bool Programmer::unplug(Meta meta)
{
  for(int i=0; i<_gadgets; i++){
    if(_gadget[i]->meta.type == meta.type && !strcmp(_gadget[i]->meta.name, meta.name)){
      for(; i<_gadgets-1; i++){
        _gadget[i] = _gadget[i+1];
      }
      _gadget[i] = nullptr;
      _gadgets--;
      return true;
    }
  }

  return false;
}

bool Programmer::plugged()
{
  return _robot;
}
bool Programmer::plugged(Gadget *gadget)
{
  if(!gadget) return false;

  for(int i=0; i<_gadgets; i++)
    if(_gadget[i] == gadget)
       return true;

  return false;
}
bool Programmer::plugged(Robot *robot)
{
  if(!robot) return false;
  return _robot == robot;
}
bool Programmer::plugged(Meta meta)
{
  for(int i=0; i<_gadgets; i++)
    if(_gadget[i]->meta.type == meta.type && !strcmp(_gadget[i]->meta.name, meta.name))
       return true;

  return false;
}

Gadget * Programmer::get(Meta meta)
{
  for(int i=0; i<_gadgets; i++)
    if(_gadget[i]->meta.type == meta.type && !strcmp(_gadget[i]->meta.name, meta.name))
       return _gadget[i];

  return nullptr;
}

bool Programmer::load(Kernel *kernel)
{
  if(! working()) return false;
  if(_kernel) return false;
  _kernel = kernel;
  return true;
}
bool Programmer::unload()
{
  if(! working()) return false;
  if(! _kernel) return false;
  _kernel = nullptr;
  return true;
}
