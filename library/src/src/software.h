#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "hardware.h"

class Programmable;

class Software
{
    friend class Programmable;

  public:
    enum { name_size = 20 };

    static int getInstancesAmount();
    int getId();

    virtual int main(int argc, const char * argv[]) = 0;

    Software();
    virtual ~Software();

  private:
    static int _instances;
    int _id;

    char * const _name;
    Hardware * _hardware;
};

//***************************************************//

inline int Software::getInstancesAmount(){
  return _instances;
}

inline int Software::getId(){
  return _id;
}

#endif // SOFTWARE_H
