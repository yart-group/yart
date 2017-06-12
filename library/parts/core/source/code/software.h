#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "hardware.h"

class Programmable;

class Software
{
    friend class Programmable;

  public:
    enum { name_size = 20 };
    char * const name;

    static int getInstancesAmount();
    int getId();

    virtual int main(int argc, const char * argv[]) = 0;

    Software(const char * name_ = "unknown");
    virtual ~Software();

  private:
    static int _instances;
    int _id;

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
