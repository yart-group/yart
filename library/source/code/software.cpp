#include "software.h"

#include "general/global.h"

int Software::_instances = 0;

Software::Software() :
  _id(_instances),
  _name(new char[name_size]),
  _hardware(nullptr)
{
  _instances++;
  strcpy(_name, "unknown");
}

Software::~Software()
{
  _instances--;
}

