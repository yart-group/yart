#include "software.h"

#include "general/global.h"

int Software::_instances = 0;

Software::Software(const char * name_) :
  _id(_instances),
  name(new char[name_size]),
  _hardware(nullptr)
{
  _instances++;
  strcpy(name, name_);
}

Software::~Software()
{
  _instances--;
}

