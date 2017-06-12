#ifndef LOGGER_H
#define LOGGER_H

#include "../general/global.h"

class Logger
{
  public:
    enum { name_size = 20 };
    char * const name;

    virtual Logger & operator << (const char * data) = 0;
    virtual Logger & operator << (double data) = 0;

    Logger(const char * name_ = "unknown");
};

//*************************************************************************//

inline Logger::Logger(const char *name_) :
  name(new char[name_size])
{
  strcpy(name, name_);
}




#endif // LOGGER_H
