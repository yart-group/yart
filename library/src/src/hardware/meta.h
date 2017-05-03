#ifndef META_H
#define META_H

#include "device.h"
#include <cstring>

class Device::Meta
{
  public:
    char * const name;

    Device::Meta(const char * name = "unknown", int type = Device);
    Device::Meta(int type);

  private:
    int _type;
};

inline Device::Meta::Meta(const char * name, int type) :
  name(new char[20]), type(type_)
{
  strcpy(name, name_);
}

inline Device::Meta::Meta(int type) :
  name(new char[20]), type(type_)
{
  strcpy(name, "unknown");
}

#endif // META_H
