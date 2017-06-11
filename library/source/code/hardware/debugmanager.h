#ifndef DEBUGMANAGER_H
#define DEBUGMANAGER_H

#include "logger.h"
#include "../general/global.h"

class DebugManager
{
  public:
    vector<Logger *> logger;

    DebugManager & operator << (const char * data);
    DebugManager & operator << (double data);

    bool isEnabled();
    void set(bool on);
    void setOn();
    void setOff();

    DebugManager();

  private:
    bool _enabled;
};

//*************************************************************************//

inline DebugManager::DebugManager() :
  _enabled(false)
{}

inline bool DebugManager::isEnabled(){
  return _enabled;
}
inline void DebugManager::set(bool on){
  if(on)
    setOn();
  else
    setOff();
}
inline void DebugManager::setOn(){
  _enabled = true;
}
inline void DebugManager::setOff(){
  _enabled = false;
}


#endif // DEBUGMANAGER_H
