#ifndef CONFIG_H
#define CONFIG_H

#ifndef COMPILE_FOR_ARDUINO_UPLOAD
  #warning COMPILE_FOR_ARDUINO_UPLOAD not set, using default
  #define COMPILE_FOR_ARDUINO_UPLOAD false
#endif

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  #warning use it only as with .tgz version of library
  //#include "portable/sketchbook/libraries/makeblock/src/MeOrion.h"
#endif

#endif // CONFIG_H
