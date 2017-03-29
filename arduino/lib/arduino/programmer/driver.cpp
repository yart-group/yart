#include "driver.h"

Driver::Driver()
{
  meta.type = Meta::Driver;
  lastMsg = new char[20];

  strcpy(lastMsg, "created");
}

int Driver::main(int argc, char const * const * argv)
{
  if(!argc)
    return ! install();

  if(argc == 1 && strcmp(argv[0], "uninstall"))
    return ! uninstall();

  const char * a;
  char * b;

  return controller(argc, argv);
}
