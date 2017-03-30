#ifndef META_H
#define META_H

#include <cstring>

class Meta
{
  public:
    enum Type {
      Unknown = -1,
      Device,
      Gadget,
      InputGadget,
      OutputGadget,
      IOGadget,
      Program = 10,
      Driver,
    };

    Meta(const char * name_ = "unknown", int type_ = Unknown) : name(new char[20]), type(type_) {
      strcpy(name, name_);
    }

    Meta(int type_) : name(new char[20]), type(type_) {
      strcpy(name, "unknown");
    }

    char * const name;
    int type;
};

#endif // META_H
