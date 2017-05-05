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

#endif
