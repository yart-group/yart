#include "debugmanager.h"

DebugManager::DebugManager() :
  _enabled(false),
  _logger(nullptr),
  _loggers(0)
{
  _logger = new Logger * [10];
  for(int i=0; i<10; i++)
    _logger[i] = nullptr;
}

DebugManager & DebugManager::operator << (const char * data)
{
  if(isEnabled() == false) return *this;

  for(int i=0; i<_loggers; i++)
    *_logger[i] << data;

  return *this;
}
DebugManager & DebugManager::operator << (double data)
{
  if(isEnabled() == false) return *this;

  for(int i=0; i<_loggers; i++)
    *_logger[i] << data;

  return *this;
}
DebugManager & DebugManager::operator << (Meta data)
{
  if(isEnabled() == false) return *this;

  for(int i=0; i<_loggers; i++)
    *_logger[i] << data;

  return *this;
}

bool DebugManager::add(Logger *logger)
{
  if(! logger) return false;

  for(int i=0; i<_loggers; i++)
    if(_logger[i] == logger)
      return false;

  _logger[_loggers] = logger;
  _loggers++;
  return true;
}
bool DebugManager::del(Logger *logger)
{
  if(! logger) return false;

  for(int i=0; i<_loggers; i++)
    if(_logger[i] == logger){
      for(; i<_loggers-1; i++)
        _logger[i] = _logger[i+1];
      _logger[i] = nullptr;
      _loggers--;
      return true;
    }

  return false;
}
