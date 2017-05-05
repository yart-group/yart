#ifndef GLOBAL_H
#define GLOBAL_H

#include "config.h"

#warning check trello for module concept note

#if COMPILE_FOR_ARDUINO_UPLOAD == false
  #include <cstring>
#else
  #warning global.h can cause troubles (check it)

  #define nullptr 0
  char * strcpy(char *a, const char *b);
  int strcmp(const char * a, const char * b);
#endif

#endif // GLOBAL_H
