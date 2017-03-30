#include <iostream>
#include <cstring>
#include "../../lib/arduino/libarduino.h"
using namespace std;

class Cli : public Program
{
  public:
    Cli() { strcpy(meta.name, "cycux"); }

    int main(int argc, const char * const *argv);
};

int Cli::main(int /*argc*/, const char * const */*argv*/)
{
  char * buffer = new char [100];
  for(int i=0; i<100; i++) buffer[i] = 0;

  while(1){
    cout << "CycuX OS: ";
    //cin >> buffer;
    cin.getline(buffer, 100);

    if(!strcmp(buffer, "quit"))
      break;

    int exit_code = _kernel->command(buffer);
    if(exit_code == -1) cout << " > unknown command " << endl;
  }
  cout << "quit ..." << endl;
  return 0;
}

class Echo : public Driver
{
  public:
    Echo() { strcpy(meta.name, "kappa"); }

    int controller(int argc, const char * const *argv);
    bool install();
    bool uninstall();

    void echo(int n, const char * const * words);
};

int Echo::controller(int argc, const char * const *argv)
{
  if(argc < 2) return -1;
  if(strcmp(argv[0], "echo")) return -1;

  echo(argc, argv);

  return 0;
}
bool Echo::install()
{
  return _kernel->_commandTable.add("echo", this);
}
bool Echo::uninstall()
{
  return _kernel->_commandTable.del("echo", this);
}
void Echo::echo(int n, const char * const *words)
{
  for(int i=1; i<n; i++)
    cout << "echo: " << words[i] << endl;
}

int main()
{
  Cli * cli = new Cli;
  Echo * echo = new Echo;

  Kernel * kernel = new Kernel;

  cout << "run(): " << kernel->run() << endl;
  cout << "load(): " << kernel->load(cli) << endl;
  cout << "executing .." << endl;
  cout << "exit: " << kernel->start(Meta("cycux", Meta::Program)) << endl;
  kernel->load(echo);
  kernel->start(Meta("kappa", Meta::Driver));
  cout << "executing .." << endl;
  cout << "exit: " << kernel->start(Meta("cycux", Meta::Program)) << endl;


  return 0;
}
