#ifndef LOGGER_H
#define LOGGER_H

#include "general/meta.h"

class Logger
{
  public:
    Meta meta;

    virtual Logger & operator << (const char * data) = 0;
    virtual Logger & operator << (double data) = 0;
    virtual Logger & operator << (Meta data) = 0;
};

#endif // LOGGER_H
