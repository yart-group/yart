#ifndef COMMANDTABLE_H
#define COMMANDTABLE_H

#include "program.h"

class CommandTable
{
  public:
    CommandTable();

    bool add(const char * cmd, Program * driver);
    bool del(const char * cmd, Program * driver);
    int exec(int argc, char const * const * argv);

  private:
    int _commands;
    const char ** _command;
    Program ** _driver;

};

#endif // COMMANDTABLE_H
