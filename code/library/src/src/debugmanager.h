#ifndef DEBUGMANAGER_H
#define DEBUGMANAGER_H

#include "logger.h"

class DebugManager
{
  public:
    DebugManager();

    DebugManager & operator << (const char * data);
    DebugManager & operator << (double data);
    DebugManager & operator << (Meta data);

    bool add(Logger * logger);
    bool del(Logger * logger);

    bool isEnabled() { return _enabled; }
    void set(bool on) { if(on) setOn(); else setOff(); }
    void setOn() { _enabled = true; }
    void setOff() { _enabled = false; }

  private:
    bool _enabled;

    Logger **_logger;
    int _loggers;
};

#endif // DEBUGMANAGER_H
