#include "programmable.h"

bool Programmable::uploadSoftware(Software *software){
  if(_software != nullptr) return false;
  _software = software;

#warning > this line can cause error due to 'this' pointer
#warning >> not contaning Microcontroller address but interface part only
  //_software->_hardware = this;

  return true;
}

bool Programmable::removeSoftware(){
  if(_software == nullptr) return false;
  _software->_hardware = nullptr;
  _software = nullptr;
  return true;
}
