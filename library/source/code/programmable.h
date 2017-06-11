#ifndef PROGRAMMABLE_H
#define PROGRAMMABLE_H

#include "software.h"

class Programmable
{
  public:
    bool uploadSoftware(Software * software);
    bool removeSoftware();
    bool isProgrammed();
    Software * getSoftware();

    Programmable();

  private:
    Software * _software;
};

//*************************************************************//

inline Programmable::Programmable() :
  _software(nullptr)
{}

inline bool Programmable::isProgrammed(){
  return ! (_software == nullptr);
}

inline Software * Programmable::getSoftware(){
  return _software;
}


#endif // PROGRAMMABLE_H
