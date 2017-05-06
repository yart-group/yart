/* NOW INSIDE device.h
#ifndef META_H
#define META_H

#include "device.h"

class Device::Meta
{
  public:
    enum { name_size = 20 };
    char * const name;

    enum Type { Device, Gadget, InputGadget, OutputGadget, IOGadget, Component, Chip, Robot };
    int getType();
    bool setType(int type);

    Meta(const char * name_ = "unknown", int type = Device);
    Meta(int type);

  private:
    int _type;
};
*/
//***********************************************************************//

/*

#include "../general/global.h"

inline int Device::Meta::getType()
{
  return _type;
}
inline bool Device::Meta::setType(int type){
  if(type < 0 || type > Robot) return false;
  _type = type;
  return true;
}

inline Device::Meta::Meta(const char * name_, int type) :
  name(new char[name_size]), _type(type)
{
  strcpy(name, name_);
}

inline Device::Meta::Meta(int type) :
  name(new char[name_size]), _type(type)
{
  strcpy(name, "unknown");
}

#endif // META_H

*/
