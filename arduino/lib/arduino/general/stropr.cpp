#include "stropr.h"

bool Stropr::strcmp(const char *a, const char *b){
  while( *(a++) == *(b++) ); a--; b--;
  if( !(*a && *b) ) return true;
  if(*a == *b) return true;
  return false;
}
