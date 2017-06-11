
#include "global.h"

#if COMPILE_FOR_ARDUINO_UPLOAD == false

char *strcpy(char *a, const char *b)
{
   char *saved = a;
   while (*b) *a++ = *b++;
   *a = 0;
   return saved;
}

int strcmp(const char * a, const char * b)
{
  const unsigned char *p1 = (const unsigned char *)a;
  const unsigned char *p2 = (const unsigned char *)b;

  while (*p1 != '\0') {
      if (*p2 == '\0') return  1;
      if (*p2 > *p1)   return -1;
      if (*p1 > *p2)   return  1;

      p1++;
      p2++;
  }

  if (*p2 != '\0') return -1;

  return 0;
}


#endif
