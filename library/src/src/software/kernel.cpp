#include "kernel.h"

#include <algorithm>

//===================================================================//
// kernel


bool Kernel::load(Program * program){
  if(! _running) return false;
  if(! program) return false;

  program->pair(this);

  if(program->getType() == Kernel::Program::Program){
    if(std::find(_programs.begin(), _programsv.end(), program) != _programs.end())
        return false;
    else{
        _programs.push_back( program );
        return true;
    }
  }
  else{
    if(std::find(_drivers.begin(), _drivers.end(), program) != _drivers.end())
      return false;
    else{
      _drivers.push_back( program );
      return true;
    }
  }
}

bool Kernel::unload(Program *program){
  if(! _running) return false;
  if(! program) return false;

  if(program->getType() == Kernel::Program::Program){
    vector<Program *>::iterator it = std::find(_programs.begin(), _programs.end(), program);
    if(it == _programs.end()){
      return false;
    }
    else{
      _programs.erase(it);
      it = std::find(_startedPrograms.begin(), _startedPrograms.end(), program);
      if(it != _startedPrograms.end())
        _startedPrograms.erase(it);
    }
  }
  else{
    vector<Driver *>::iterator it = std::find(_drivers.begin(), _drivers.end(), program);
    if(it == _drivers.end()){
      return false;
    }
    else{
      _drivers.erase(it);
      it = std::find(_startedDrivers.begin(), _startedDrivers.end(), program);
      if(it != _startedDrivers.end())
        _startedDrivers.erase(it);
    }
  }

  program->unpair();
  return true;
}

bool Kernel::start(int type, const char *name){
  if(! _running) return false;
  if(! name) return false;

  if(type == Kernel::Program::Program){
    for( Program * x : _programs){
      if(! strcmp(x->name, name)){
        if(std::find(_startedPrograms.begin(), _startedPrograms.end(), x) != _startedPrograms.end())
          return false;
        _startedPrograms.push_back(x);
        return x->main();
      }
    }
  }else if(type == Kernel::Program::Driver){
    for( Driver * x : _drivers){
      if(! strcmp(x->name, name)){
        if(std::find(_startedDrivers.begin(), _startedDrivers.end(), x) != _startedDrivers.end())
          return false;
        _startedDrivers.push_back(x);
        return x->main();
      }
    }
  }
  return false;
}

bool Kernel::stop(int type, const char *name){

}












