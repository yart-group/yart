#ifndef PORT_H
#define PORT_H


class Port
{
  public:
    Port();

    void setPort(int port);
    int getPort();

  private:
    int _port;
};

#endif // PORT_H
