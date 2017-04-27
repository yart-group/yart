#ifndef PATHS_H
#define PATHS_H

#define TO_STRING(a) #a

#if DEVICE_LIB == arduino
  #define DEVICE_LIB_PATH ARDUINO_PATH/devices/
#elif DEVICE_LIB_PATH == emulator
  #define DEVICE_LIB_PATH EMULATOR_PATH/devices/
#elif DEVICE_LIB_PATH == simulator
  #define DEVICE_LIB_PATH SIMULATOR_PATH/devices/
#endif

#if COMPONENT_LIB == arduino
  #define COMPONENT_LIB_PATH ARDUINO_PATH/devices/
#elif COMPONENT_LIB_PATH == emulator
  #define COMPONENT_LIB_PATH EMULATOR_PATH/devices/
#elif COMPONENT_LIB_PATH == simulator
  #define COMPONENT_LIB_PATH SIMULATOR_PATH/devices/
#endif

#if PROGRAM_LIB == arduino
  #define PROGRAM_LIB_PATH ARDUINO_PATH/devices/
#elif PROGRAM_LIB_PATH == emulator
  #define PROGRAM_LIB_PATH EMULATOR_PATH/devices/
#elif PROGRAM_LIB_PATH == simulator
  #define PROGRAM_LIB_PATH SIMULATOR_PATH/devices/
#endif

#if DRIVER_LIB == arduino
  #define DRIVER_LIB_PATH ARDUINO_PATH/devices/
#elif DRIVER_LIB_PATH == emulator
  #define DRIVER_LIB_PATH EMULATOR_PATH/devices/
#elif DRIVER_LIB_PATH == simulator
  #define DRIVER_LIB_PATH SIMULATOR_PATH/devices/
#endif


#if BUILD_FOR_ARDUINO_UPLOAD == true
  #warning "building for adruino upload"

  #include <Arduino.h>
  #include <Wire.h>
  #include <SoftwareSerial.h>
  #include <MeOrion.h>

  #include TO_STRING( DEVICE_LIB_PATH/source/device.cpp )
  #include TO_STRING( DEVICE_LIB_PATH/source/inputdevice.cpp )
  #include TO_STRING( DEVICE_LIB_PATH/source/outputdevice.cpp )
  #include TO_STRING( DEVICE_LIB_PATH/source/iodevice.cpp )
  #include TO_STRING( DEVICE_LIB_PATH/source/sensor.cpp )
  #include TO_STRING( DEVICE_LIB_PATH/source/ultrasonicsensor.cpp )
  #include TO_STRING( DEVICE_LIB_PATH/source/infraredsensor.cpp )
  #include TO_STRING( DEVICE_LIB_PATH/source/cable.cpp )
  #include TO_STRING( DEVICE_LIB_PATH/source/mator.cpp )

  #include TO_STRING( COMPONENT_LIB_PATH/source/component.cpp )
  #include TO_STRING( COMPONENT_LIB_PATH/source/chassis.cpp )
  #include TO_STRING( COMPONENT_LIB_PATH/source/robot.cpp )
  #include TO_STRING( COMPONENT_LIB_PATH/source/pilot.cpp )
  #include TO_STRING( COMPONENT_LIB_PATH/source/usb.cpp )
  #include TO_STRING( COMPONENT_LIB_PATH/source/flash.cpp )
  #include TO_STRING( COMPONENT_LIB_PATH/source/programmer.cpp )

  #include TO_STRING( PROGRAM_LIB_PATH/source/manualcontrol.cpp )
  #include TO_STRING( PROGRAM_LIB_PATH/source/walk.cpp )
  #include TO_STRING( PROGRAM_LIB_PATH/source/stay.cpp )

  #include TO_STRING( DRIVER_LIB_PATH/source/menu.cpp )
#endif

#endif // PATHS_H
