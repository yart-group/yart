#include "port.h"

bool Port::setPort(int port)
{
  if(port < min || port > max) return false;
  _port = port;
  _usable = true;
  return true;
}
