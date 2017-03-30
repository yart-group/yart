#ifndef KERNEL_H
#define KERNEL_H

#include "general/meta.h"
#include "programmer.h"
#include "programcontainer.h"
#include "driver.h"
#include "commandtable.h"

class Kernel
{
  public:
    friend class Program;
    friend class Driver;
    friend class CommandTable;

    Kernel() : _enabled(false), _programmer(nullptr) {}

    bool run();
    bool quit();
    bool load(Program * program);
    bool unload(Meta meta);
    bool start(Meta meta);
    bool stop(Meta meta);
    int command(const char * cmd);

    CommandTable _commandTable;
  private:
    bool _enabled;
    Programmer * _programmer;
    ProgramContainer _programs;
    ProgramContainer _drivers;
    ProgramContainer _startedPrograms;
    ProgramContainer _startedDrivers;

};

#endif // KERNEL_H
