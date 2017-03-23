#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "component.h"

class Programmer : public Component
{
  public:
    void plug(Component * component);

  private:
     Component * _component;
     int _components;
};

#endif // PROGRAMMER_H
