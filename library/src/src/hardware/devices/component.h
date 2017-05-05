#ifndef COMPONENT_H
#define COMPONENT_H

#include "../device.h"
#include "gadget.h"

class Component : public Device
{
  public:
    vector<Gadget *> gadget;
};



#endif // COMPONENT_H
