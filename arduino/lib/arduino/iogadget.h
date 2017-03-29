#ifndef IOGADGET_H
#define IOGADGET_H

#include "inputgadget.h"
#include "outputgadget.h"

class IOGadget : public InputGadget, public OutputGadget
{
  public:
    IOGadget() : meta(Meta::IOGadget) {}

    Meta meta;
};

#endif // IOGADGET_H
