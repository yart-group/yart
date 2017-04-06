#ifndef PORT_H
#define PORT_H


class Port
{
  public:
    Port();

    bool isUsable() { return _usable; }

    bool setPort(int port);
    int getPort();

  private:
    bool _usable;
    int _port;

    int _min;
    int _max;
};

#endif // PORT_H
