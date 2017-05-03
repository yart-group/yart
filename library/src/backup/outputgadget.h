#ifndef OUTPUTGADGET_H
#define OUTPUTGADGET_H

#include "gadget.h"

class OutputGadget : public Gadget
{
  public:
    OutputGadget() { meta.type = Meta::OutputGadget; }

    virtual void write(double data) = 0;
};

#endif // OUTPUTGADGET_H
