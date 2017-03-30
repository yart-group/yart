#ifndef CONFIG_H
#define CONFIG_H


#define COMPILE_FOR_ARDUINO_UPLOAD false

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  #warning use it only as with .tgz version of library
  //#include "portable/sketchbook/libraries/makeblock/src/MeOrion.h"
#endif

#endif // CONFIG_H
