#ifndef INPUTGADGET_H
#define INPUTGADGET_H

#include "gadget.h"

class InputGadget : public Gadget
{
  public:
    InputGadget() {}

    virtual double read();

  protected:
    virtual double read_addons() = 0;
};

#endif // INPUTGADGET_H
