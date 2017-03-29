#ifndef PROGRAM_H
#define PROGRAM_H

#include "general/meta.h"
class Kernel;

class Program
{
  public:
    Program() : meta(Meta::Program), lastMsg(nullptr) {}

    virtual int main(int argc = 0, char const * const * argv = 0) = 0;
    bool pair(Kernel * kernel);
    bool unpair();
    bool paired();

    char * lastMsg;
    virtual int controller(int argc, char const * const * argv) {}
    virtual bool install() {}
    virtual bool uninstall() {}

    Meta meta;
  private:
    Kernel * _kernel;

};

#endif // PROGRAM_H
