#include "hardware.h"

int Hardware::_instances = 0;

Hardware::Hardware() : _id(_instances)
{
  _instances++;
}

Hardware::~Hardware()
{
  _instances--;
}

