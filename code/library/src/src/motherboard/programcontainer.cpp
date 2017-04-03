#include "programcontainer.h"

ProgramContainer::ProgramContainer() : _loads(0)
{
  _table = new Program*[30];

  for(int i=0; i<30; i++)
    _table[i] = nullptr;
}

bool ProgramContainer::add(Program * program)
{
  if(!program) return false;

  for(int i=0; i<_loads; i++)
    if(_table[i] == program || !strcmp(_table[i]->meta.name, program->meta.name))
      return false;

  _table[_loads] = program;
  _loads++;
  return true;
}

bool ProgramContainer::remove(Program * program)
{
  if(!program) return false;

  for(int i=0; i<_loads; i++){
    if(_table[i] == program){
      for(; i<_loads-1; i++)
        _table[i] = _table[i-1];
      _table[i] = nullptr;
      _loads--;
      return true;
    }
  }

  return false;
}
bool ProgramContainer::remove(Meta meta)
{
  for(int i=0; i<_loads; i++){
    if(_table[i]->meta.type == meta.type && !strcmp(_table[i]->meta.name, meta.name)){
      for(; i<_loads-1; i++)
        _table[i] = _table[i-1];
      _table[i] = nullptr;
      _loads--;
      return true;
    }
  }

  return false;
}

bool ProgramContainer::check(Program * program)
{
  if(!program) return false;

  for(int i=0; i<_loads; i++)
    if(_table[i] == program)
      return true;

  return false;
}
bool ProgramContainer::check(Meta meta)
{
  for(int i=0; i<_loads; i++)
    if(_table[i]->meta.type == meta.type && !strcmp(_table[i]->meta.name, meta.name))
      return true;

  return false;
}

Program * ProgramContainer::get(Meta meta)
{
  for(int i=0; i<_loads; i++)
    if(_table[i]->meta.type == meta.type && !strcmp(_table[i]->meta.name, meta.name))
      return _table[i];

  return nullptr;
}
