#ifndef PROGRAMCONTAINER_H
#define PROGRAMCONTAINER_H

#include "program.h"

class ProgramContainer
{
  public:
    ProgramContainer();

    bool add(Program * program);
    bool remove(Program * program);
    bool remove(Meta meta);
    bool check(Program * program);
    bool check(Meta meta);
    Program * get(Meta meta);

  private:
    Program ** _table;
    int _loads;
};

#endif // PROGRAMCONTAINER_H
