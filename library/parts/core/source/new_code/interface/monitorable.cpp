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

Monitorable::Identifier nullident;

Monitorable::Identifier & Monitorable::Identifier::operator =(const Identifier & identifier) noexcept
{
  if( isOriginal() )
    *_valid = false;

  _original = false;
  _valid = identifier._valid;
  _id = identifier._id;
  _name = identifier._name;

  return *this;
}

Monitorable::Identifier::Identifier(name_type name) :
  _original { true },
  _valid { new valid_mark(true) },
  _id { Monitorable::_instances },
  _name { name }
{
  if( _name == "null" ) {
    setNull();
    throw std::invalid_argument( "identifier name cannot be set to 'null'" );
  }
  ++Monitorable::_instances;
}

