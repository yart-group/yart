#ifndef PORT_H
#define PORT_H


class Port
{
  public:
    Port();

    bool usable() { return _usable; }

    void setPort(int port);
    int getPort();

  private:
    bool _usable;
    int _port;

    int _min;
    int _max;
};

#endif // PORT_H
