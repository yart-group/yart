#ifndef PROGRAM_H
#define PROGRAM_H

#include "general/meta.h"
class Kernel;

class Program
{
  public:
    Program() : lastMsg(nullptr), meta(Meta::Program), _kernel(nullptr) {}

    virtual int main(int argc = 0, char const * const * argv = 0) = 0;
    bool pair(Kernel * kernel);
    bool unpair();
    bool paired();

    char * lastMsg;
    virtual int controller(int /*argc*/, char const * const * /*argv*/) { return -1; }
    virtual bool install() { return false; }
    virtual bool uninstall() { return false; }

    Meta meta;
  protected:
    Kernel * _kernel;

};

#endif // PROGRAM_H
