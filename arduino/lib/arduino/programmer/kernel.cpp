#include "kernel.h"

#include <cstring>

bool Kernel::run()
{
  if(_enabled) return false;
  _enabled = true;
  return true;
}
bool Kernel::quit()
{
  if(!_enabled) return false;
  _enabled = false;
  return true;
}
bool Kernel::load(Program *program)
{
  if(!_enabled) return false;
  if(!program) return false;

  program->pair(this);

  if(program->meta.type == Meta::Program)
    return _programs.add(program);
  else
    return _drivers.add(program);
}
bool Kernel::unload(Meta meta)
{
  if(!_enabled) return false;

  if(meta.type == Meta::Program)
    return _programs.remove(meta);
  else
    return _drivers.remove(meta);

}
bool Kernel::start(Meta meta)
{
  if(!_enabled) return false;

  Program * program;

  if(meta.type == Meta::Program)
    program = _programs.get(meta);
  else
    program = _drivers.get(meta);

  if(!program) return false;

  if(meta.type == Meta::Driver)
    _startedDrivers.add(program);

  return ! ( program -> main() );
}
bool Kernel::stop(Meta meta)
{
  if(!_enabled) return false;

  Program * program;

  if(meta.type == Meta::Program)
    program = _startedPrograms.get(meta);
  else
    program = _startedDrivers.get(meta);

  if(!program) return false;

  program -> uninstall();

  if(meta.type == Meta::Program)
    _startedPrograms.remove(program);
  else
    _startedDrivers.remove(program);

  return true;
}
int Kernel::command(const char *cmd)
{
  if(!_enabled) return false;
  if(!cmd) return false;

  int argc = 0;
  char ** argv = new char * [10];
  for(int i=0; i<10; i++)
    argv[i] = new char[10];

  int a = 0;
  for(int i=0; ;i++)
  {
    if(cmd[i] == ' ' || cmd[i] == 0){
      strncpy(argv[argc], cmd+a, i-a);
      argv[argc][i-a] = 0;
      argc++;
      a=i+1;
    }

    if(cmd[i] == 0) break;
  }

  return _commandTable.exec(argc, argv);
}





