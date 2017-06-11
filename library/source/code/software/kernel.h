#ifndef KERNEL_H
#define KERNEL_H

#include "../software.h"
#include "../hardware/devices/gadget.h"
#include "../general/global.h"

class Kernel : public Software
{
  public:
    class Program : public Software{
      public:
        enum Type { Program, Driver };
        int getType();
        bool pair(Kernel * kernel);
        bool unpair();
        bool isPaired();
        Program();
      protected:
        int _type;
      private:
        Kernel * _kernel;
    };

    class Driver : public Program {
      public:
        enum { msg_size = 40 };
        int controller(int argc, const char * argv[]);
        bool install();
        bool uninstall();
        bool isInstalled();
        const char * getLastMessage();
        Driver();
      private:
        bool _installed;
        char * const _lastMessage;
    };

    bool run();
    bool quit();

    bool load(Program * program);
    bool unload(Program * program);

    bool start(int type, const char * name);
    bool stop(int type, const char * name);

    int command(const char * cmd);

    virtual int main(int argc, const char *argv[]);

    Kernel();
    ~Kernel();

  private:
    bool _running;
    vector<Gadget *> * _gadgets;
    vector<Program *> _programs;
    vector<Driver *>  _drivers;
    vector<Program *> _startedPrograms;
    vector<Driver *>  _startedDrivers;
    CommandTable * _commandTable;
};

//****************************************************************//
// Program

inline Kernel::Program::Program() :
  _type(Program),
  _kernel(nullptr)
{}

inline int Kernel::Program::getType(){
  return _type;
}

inline bool Kernel::Program::pair(Kernel *kernel){
  if(isPaired()) return false;
  _kernel = kernel;
  return true;
}
inline bool Kernel::Program::unpair(){
  if(! isPaired()) return false;
  _kernel = nullptr;
  return true;
}
inline bool Kernel::Program::isPaired(){
  return ! (_kernel == nullptr);
}


//****************************************************************//
// Driver

Kernel::Driver::Driver() :
  _installed(false),
  _lastMessage(new char[msg_size])
{
  strcpy(_lastMessage, "obj created");
}

const char * Kernel::Driver::getLastMessage(){
  return _lastMessage;
}


//****************************************************************//
// Kernel

inline Kernel::Kernel() :
  _running(false),
  _gadgets(nullptr),
  _commandTable(new CommandTable)
{}

inline Kernel::~Kernel(){
  delete _commandTable;
}

inline bool Kernel::run(){
  if(_running) return false;
  _running = true;
  return true;
}

inline bool Kernel::quit(){
  if(! _running) return false;
  _running = false;
  return true;
}








#endif // KERNEL_H
