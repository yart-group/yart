#ifndef TURNABLE_H
#define TURNABLE_H
#include "../general/global.h"
namespace interface {

class Turnable
{
  public:
    enum State : bool { on = true, off = false };
    using state_type = State;

    bool turn(const state_type state);
    virtual bool turnOn();
    virtual bool turnOff();
    bool isOn() const noexcept;
    bool isOff() const noexcept;

    bool operator =(const state_type);
    bool operator ==(const state_type) const noexcept;
    bool operator !=(const state_type) const noexcept;
    bool operator ==(const Turnable &) const noexcept;
    bool operator !=(const Turnable &) const noexcept;

  protected:
    Turnable() noexcept;
    Turnable(const Turnable &) = default;
    Turnable(const Turnable &&) = default;
    Turnable & operator =(const Turnable &) = default;
    Turnable & operator =(const Turnable &&) = default;
    virtual ~Turnable() = 0;

    explicit Turnable(const state_type state) noexcept;

  private:
    state_type _state;
};

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//

inline bool Turnable::turn(const state_type state)
{
  if(state == on) return turnOn();
  return turnOff(); // assumption? (possible more state?)
}
inline bool Turnable::turnOn()
{
  _state = on;
  return true;
}
inline bool Turnable::turnOff()
{
  _state = off;
  return true;
}
inline bool Turnable::isOn() const noexcept
{
  return _state == on;
}
inline bool Turnable::isOff() const noexcept
{
  return _state == off;
}

inline bool Turnable::operator =(const Turnable::state_type state)
{
  return turn(state); // should do virtual call
}
inline bool Turnable::operator ==(const Turnable::state_type state) const noexcept
{
  return state == _state;
}
inline bool Turnable::operator !=(const Turnable::state_type state) const noexcept
{
  return !(*this == state);
}
inline bool Turnable::operator ==(const Turnable & turnable) const noexcept
{
  return (*this == turnable._state);
}
inline bool Turnable::operator !=(const Turnable & turnable) const noexcept
{
  return !(*this == turnable);
}

inline Turnable::Turnable() noexcept : _state { off } {}
inline Turnable::~Turnable() {}

Turnable::Turnable(state_type on) noexcept : _on { on } {}

} // namespace
#endif // TURNABLE_H
