#ifndef IOGADGET_H
#define IOGADGET_H

#include "inputgadget.h"
#include "outputgadget.h"

class IOGadget : public InputGadget, public OutputGadget
{
  public:
    Meta meta;

    IOGadget();
};

//**************************************************************************//

inline IOGadget::IOGadget() :
  meta(Device::Meta::IOGadget)
{}


#endif // IOGADGET_H
