#ifndef KERNEL_H
#define KERNEL_H

#include "general/meta.h"
#include "motherboard.h"
#include "programcontainer.h"
#include "driver.h"
#include "commandtable.h"

class Kernel
{
  public:
    friend class Program;
    friend class Driver;
    friend class CommandTable;

    Kernel() : _enabled(false), _motherboard(nullptr) {}

    bool run();
    bool quit();
    bool load(Program * program);
    bool unload(Meta meta);
    bool start(Meta meta);
    bool stop(Meta meta);
    int command(const char * cmd);

    CommandTable _commandTable;
    Motherboard * _motherboard;
  private:
    bool _enabled;
    ProgramContainer _programs;
    ProgramContainer _drivers;
    ProgramContainer _startedPrograms;
    ProgramContainer _startedDrivers;

};

#endif // KERNEL_H
