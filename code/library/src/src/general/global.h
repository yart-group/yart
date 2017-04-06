#ifndef GLOBAL_H
#define GLOBAL_H

#include "config.h"

#if COMPILE_FOR_ARDUINO_UPLOAD == false
  #include <cstring>
#else

  #define nullptr 0

  char * strcpy(char *a, const char *b);
  int strcmp(const char * a, const char * b);
#endif

#endif // GLOBAL_H
