#ifndef HARDWARE_H
#define HARDWARE_H

class Hardware
{
  public:
    static int getInstancesAmount();
    int getId();

    Hardware();
    virtual ~Hardware();

  private:
    static int _instances;
    int _id;
};

//*************************************************//

inline int Hardware::getInstancesAmount(){
  return _instances;
}

inline int Hardware::getId(){
  return _id;
}

#endif
