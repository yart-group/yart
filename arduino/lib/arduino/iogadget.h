#ifndef IOGADGET_H
#define IOGADGET_H

#include "inputgadget.h"
#include "outputgadget.h"

class IOGadget : public InputGadget, public OutputGadget
{
  public:
    IOGadget();
};

#endif // IOGADGET_H
