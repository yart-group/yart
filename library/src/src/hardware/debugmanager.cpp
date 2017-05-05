#include "debugmanager.h"

DebugManager & DebugManager::operator << (const char * data)
{
  if(isEnabled() == false) return *this;

  int amount = logger.size();
  for(int i=0; i<amount; ++i)
    *logger[i] << data;

  return *this;
}
DebugManager & DebugManager::operator << (double data)
{
  if(isEnabled() == false) return *this;

  int amount = logger.size();
  for(int i=0; i<amount; ++i)
    *logger[i] << data;

  return *this;
}
