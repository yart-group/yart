#ifndef INPUTGADGET_H
#define INPUTGADGET_H

#include "gadget.h"

class InputGadget : public Gadget
{
  public:
    InputGadget() { meta.type = Meta::InputGadget; }

    virtual double read() = 0;
};

#endif // INPUTGADGET_H
