#include "program.h"

bool Program::pair(Kernel *kernel)
{
  if(paired()) return false;
  _kernel = kernel;
  return true;
}
bool Program::unpair()
{
  if(! paired()) return false;
  _kernel = nullptr;
  return true;
}
bool Program::paired()
{
  return _kernel;
}
