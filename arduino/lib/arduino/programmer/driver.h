#ifndef DRIVER_H
#define DRIVER_H

#include "program.h"

class Driver : public Program
{
  public:
    Driver();

    int main(int argc = 0, char const * const * argv = 0);

    virtual int controller(int argc, char const * const * argv) = 0;
    virtual bool install() = 0;
    virtual bool uninstall() = 0;
};

#endif // DRIVER_H
