#ifndef HARDWARE_H
#define HARDWARE_H

class Hardware
{
  public:
    Hardware();
    virtual ~Hardware();
    static int getInstancesAmount();
    int getId();

  private:
    static int _instances;
    int _id;
};

#endif
