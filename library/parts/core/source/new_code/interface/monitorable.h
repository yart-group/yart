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
        using original_mark = bool;
        using id_type = Monitorable::counter_type;
        using name_type = Monitorable::name_type;

        id_type getId() const noexcept;
        name_type getName() const noexcept;

        bool isValid() const noexcept;
        bool isOriginal() const noexcept;

        bool isNull() const noexcept;
        void setNull() noexcept;

        Identifier() noexcept;
        Identifier(const Identifier &) noexcept;
        Identifier(const Identifier &&) = default;
        Identifier & operator =(const Identifier &) noexcept;
        Identifier & operator =(const Identifier &&) = default;
        ~Identifier() noexcept;

        bool operator ==(const Identifier &) const noexcept;
        bool operator !=(const Identifier &) const noexcept;
        operator bool() const noexcept;

      private:
        enum : id_type { null = -1 };

        original_mark _original = false;
        std::shared_ptr<valid_mark> _valid = nullptr;
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

extern Monitorable::Identifier nullident;

inline Monitorable::Identifier::id_type Monitorable::Identifier::getId() const noexcept
{
  return _id;
}
inline Monitorable::Identifier::name_type Monitorable::Identifier::getName() const noexcept
{
  return _name;
}

inline bool Monitorable::Identifier::isValid() const noexcept
{
  return *_valid;
}
inline bool Monitorable::Identifier::isOriginal() const noexcept
{
  return _original;
}

inline bool Monitorable::Identifier::isNull() const noexcept
{
  return _id == null;
}
inline void Monitorable::Identifier::setNull() noexcept
{
  *this = nullident;
}

inline Monitorable::Identifier::Identifier() noexcept {}
inline Monitorable::Identifier::Identifier(const Identifier &identifier) noexcept :
  _original { false },
  _valid { identifier._valid },
  _id { identifier._id },
  _name { identifier._name }
{}
// operator =(const Identifier &)
inline Monitorable::Identifier::~Identifier() noexcept
{
  if( isOriginal() ) *_valid = false;
}

inline bool Monitorable::Identifier::operator ==(Monitorable::Identifier & identifier) const noexcept
{
  return _id == identifier._id;
}
inline bool Monitorable::Identifier::operator !=(Monitorable::Identifier & identifier) const noexcept
{
  return !(*this == identifier);
}
inline Monitorable::Identifier::operator bool() const noexcept
{
  return isValid();
}

// Identifier(name_type)



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
