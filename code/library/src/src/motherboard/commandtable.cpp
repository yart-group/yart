#include "commandtable.h"


CommandTable::CommandTable() : _commands(0)
{
  _command = new const char * [30];
  _driver = new Program * [30];

  for(int i=0; i<30; i++){
    _command[i] = nullptr;
    _driver[i] = nullptr;
  }
}

bool CommandTable::add(const char *cmd, Program *driver)
{
  if(!cmd || !driver) return false;

  for(int i=0; i<_commands; i++)
    if(_driver[i] == driver && !strcmp(_command[i], cmd))
      return false;

  _command[_commands] = cmd;
  _driver[_commands] = driver;
  _commands++;
  return true;

}
bool CommandTable::del(const char *cmd, Program *driver)
{
  if(!cmd || !driver) return false;

  for(int i=0; i<_commands; i++)
    if(_driver[i] == driver && !strcmp(_command[i], cmd)){
      for(; i<_commands-1; i++){
        _command[i] = _command[i+1];
        _driver[i] = _driver[i+1];
      }
      _command[i] = nullptr;
      _driver[i] = nullptr;

      _commands--;
      return true;
    }

  return false;
}

int CommandTable::exec(int argc, char const * const * argv)
{
  int exit_code = -1;

  for(int i=0; i<_commands; i++){
    if(!strcmp(_command[i], argv[0])){
      exit_code = _driver[i]->controller(argc, argv);
      if(exit_code != -1) return exit_code;
    }
  }

  return -1;
}

