#ifndef KERNEL_H
#define KERNEL_H

#include "../software.h"

class Kernel : public Software
{
  public:
    bool run();
    bool quit();

    bool load(Program * program);
    bool unload(Program * program);

    bool start(int type, const char * name);
    bool stop(int type, const char * name);

    int command(const char * cmd);

  private:
    bool _running;
    vector<Gadget *> * _gadgets;
    vector<Program *> _programs;
    vector<Program *> _drivers;
    vector<Program *> _startedPrograms;
    vector<Program *> _startedDrivers;
    CommandTable * _commandTable;
};

#endif // KERNEL_H
