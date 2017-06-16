#ifndef TURNABLE_H
#define TURNABLE_H

namespace interface {

class Turnable
{
  public:
    using state_type = bool;

    virtual bool turnOn();
    virtual bool turnOff();
    virtual bool isOn() const noexcept;
    virtual bool isOff() const noexcept;

    virtual ~Turnable();

  protected:
    Turnable() = default;
    Turnable(const Turnable & turnable) = default;
    Turnable(const Turnable && turnable) = default;

    explicit Turnable(state_type on) noexcept;

  private:
    state_type _on;
};

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//

inline bool Turnable::turnOn()
{
  return _on = true;
}
inline bool Turnable::turnOff()
{
  _on = false;
  return true;
}
inline bool Turnable::isOn() const noexcept
{
  return _on;
}
inline bool Turnable::isOff() const noexcept
{
  return _on == false;
}

inline Turnable::~Turnable() {}

Turnable::Turnable(state_type on) noexcept : _on { on } {}

} // namespace
#endif // TURNABLE_H
