#ifndef PROGRAMMABLE_H
#define PROGRAMMABLE_H

#include "software.h"
class Software;

class Programmable
{
  public:
    bool uplaodSoftware(Software * software);
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


#endif // PROGRAMMABLE_H
