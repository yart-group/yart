#include "monitorable.h"
using namespace interface;

#include <stdexcept>

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Monitorable

Monitorable::counter_type Monitorable::_instances = 0;
Monitorable::counter_type Monitorable::getInstancesAmount() noexcept
{
  return _instances;
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Monitorable::Identifier

Monitorable::Identifier & Monitorable::Identifier::operator =(const Identifier & identifier) noexcept
{
  _valid = identifier._valid;
  _orphan = true;
  _id = identifier._id;
  _name = identifier._name;
  return *this;
}

Monitorable::Identifier::Identifier(name_type name) :
  _valid { new valid_mark(true) },
  _orphan { false },
  _id { Monitorable::_instances },
  _name { name }
{
  if( _name == "null" ) {
    _name = "unknown";
    throw std::invalid_argument( "identifier name cannot be set to 'null'" );
  }
  ++Monitorable::_instances;
}

void Monitorable::Identifier::setNull() noexcept
{
  if(_orphan == false)
    *_valid = false;

  _valid = nullptr;
  _orphan = true;
  _id = null;
  _name = "null";
}
