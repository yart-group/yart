#ifndef SWITCH_H
#define SWITCH_H


class Switch
{
  public:
    Switch();

    void set(bool on) { _on = on; }
    void setOn() { _on = true; }
    void setOff() { _on = false; }

    bool state() { return _on; }
    bool enabled() { return _on; }

  private:
    bool _on;
};

#endif // SWITCH_H
