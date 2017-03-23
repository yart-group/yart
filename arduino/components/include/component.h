#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
  public:
    enum State {
      WORKING = 0,
      NOT_WORKING = 1
    };

    virtual void turn(bool on) = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool enabled() = 0;

    virtual void debug(bool on) = 0;
    virtual void debugOn() = 0;
    virtual void debugOff() = 0;
    virtual void debugEnabled() = 0;

    virtual void freeze(bool on) = 0;
    virtual void freezeOn() = 0;
    virtual void freezeOff() = 0;
    virtual void freezeEnabled() = 0;

    virtual void init() = 0;
    virtual void loop() = 0;
    virtual int state() = 0;


  private:
    bool _enabled;
    bool _debug;
    bool _freeze;

    int _state;

    const char * name;
};

#endif // COMPONENT_H
