#ifndef OUTPUTGADGET_H
#define OUTPUTGADGET_H

#include "gadget.h"

class OutputGadget : public Gadget
{
  public:
    OutputGadget() {}

    virtual void write(const char * data, int size = 0);
    virtual void write(double data);

  protected:
    virtual void write_addons(const char * data, int size = 0) = 0;
    virtual void write_addons(double data) = 0;
};

#endif // OUTPUTGADGET_H