#ifndef INPUTGADGET_H
#define INPUTGADGET_H

#include "gadget.h"

class InputGadget : public Gadget
{
  public:
    virtual double read();

    InputGadget();
};

//*******************************************************************//

inline InputGadget::InputGadget(){
  meta.setType(Device::Meta::InputGadget);
}

inline double InputGadget::read(){
  if(! isWorking()) return false;
  return true;
}

#endif // INPUTGADGET_H
