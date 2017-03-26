#include "port.h"

Port::Port() :
  _usable(false),
  _port(0),
  _min(1),
  _max(10)
{}

void Port::setPort(int port)
{
  if(port < _min || port > _max) return ;
  _port = port;
  _usable = true;
}
int Port::getPort()
{
  return ( _usable ? _port : -1 );
}
