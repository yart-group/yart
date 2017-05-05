#ifndef OUTPUTGADGET_H
#define OUTPUTGADGET_H

#include "gadget.h"

class OutputGadget : public Gadget
{
  public:
    virtual bool write(double data);

    OutputGadget();
};

//*************************************************************************//

inline OutputGadget::OutputGadget(){
  meta.setType(Device::Meta::OutputGadget);
}

inline bool OutputGadget::write(double data){
  if(! isWorking()) return false;
  return true;
}

#endif // OUTPUTGADGET_H
