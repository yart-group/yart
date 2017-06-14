#ifndef MONITORABLE_H
#define MONITORABLE_H

namespace interface {
#include <string>
#include <memory>

class Monitorable
{
  public:
    class Identifier final
    {
      public:
        using valid_mark = bool;
        using orphan_mark = const bool;
        using id_type = counter_type;
        using name_type = Monitorable::name_type;
        enum : id_type { null = -1 };

        Identifier(const Identifier & identifier) noexcept;
        Identifier & operator =(const Identifier & identifier) noexcept;
        bool operator ==(const Identifier & identifier) const noexcept;
        bool operator !=(const Identifier & identifier) const noexcept;

        Identifier() noexcept;

        operator bool() const noexcept;

        valid_mark isValid() const noexcept;
        orphan_mark isOrphan() const noexcept;

        id_type getId() const noexcept;
        bool isNull() const noexcept;
        void setNull() noexcept;

        name_type getName() const noexcept;

        ~Identifier() noexcept;

      private:
        std::shared_ptr<valid_mark> _valid = nullptr;
        orphan_mark _orphan = true;
        id_type _id = null;
        name_type _name = "null";

        explicit Identifier(name_type name);
    };

    using counter_type = int;
    using identifier_type = Identifier;
    using name_type = std::string;

    static counter_type getInstancesAmount() noexcept;
    identifier_type getIdentifier() const noexcept;

    virtual ~Monitorable() noexcept;

  protected:
    Monitorable(name_type name);

  private:
    static counter_type _instances;
    const identifier_type _identifier;
};

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Monitorable::Identifier

inline Monitorable::Identifier::Identifier(const Identifier &identifier) noexcept :
  _valid { identifier._valid },
  _id { identifier._id },
  _name { identifier._name }
{}

inline bool Monitorable::Identifier::operator ==(Monitorable::Identifier & identifier) const noexcept
{
  return _id == identifier._id;
}
inline bool Monitorable::Identifier::operator !=(Monitorable::Identifier & identifier) const noexcept
{
  return !(*this == identifier);
}

inline Monitorable::Identifier::Identifier() noexcept {}

inline Monitorable::Identifier::operator bool() const noexcept
{
  return isValid();
}

inline Monitorable::Identifier::valid_mark Monitorable::Identifier::isValid() const noexcept
{
  return *_valid;
}
inline Monitorable::Identifier::orphan_mark Monitorable::Identifier::isOrphan() const noexcept
{
  return _orphan;
}

inline Monitorable::Identifier::id_type Monitorable::Identifier::getId() const noexcept
{
  return _id;
}
inline bool Monitorable::Identifier::isNull() const noexcept
{
  return _id == null;
}

inline Monitorable::Identifier::name_type Monitorable::Identifier::getName() const noexcept
{
  return _name;
}

inline Monitorable::Identifier::~Identifier() noexcept
{
  if(_orphan == false) *_valid = false;
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Monitorable

inline Monitorable::Monitorable(name_type name) : _identifier { name } {}
inline Monitorable::identifier_type Monitorable::getIdentifier() const noexcept
{
  return _identifier;
}
inline Monitorable::~Monitorable() {}


} // namespace
#endif // MONITORABLE_H
