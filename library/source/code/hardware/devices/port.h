#ifndef PORT_H
#define PORT_H


class Port
{
  public:
    enum { min = 1, max = 10 };

    bool isUsable();

    bool setPort(int port);
    int getPort();

    Port();

  private:
    bool _usable;
    int _port;
};

//*********************************************************************************//

inline Port::Port() :
  _usable(false),
  _port(0)
{}

inline bool Port::isUsable(){
  return _usable;
}

inline int Port::getPort(){
  return (isUsable() ? _port : -1);
}


#endif // PORT_H
