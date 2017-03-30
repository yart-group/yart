#!/bin/bash

echo '' > libarduino.h

add() {
  echo -e "\033[1;32m adding: \033[00m $1"
  cat $1 >> libarduino.h
  if [ $? -ne 0 ]; then
    echo -e " >\033[1;31m error: \033p[00m idk what :D"
  fi
}

add general/config.h
add general/port.h
add general/meta.h
add device.h
add gadget.h
add inputgadget.h
add outputgadget.h
add iogadget.h
add gadgets/io/cable.h
add gadgets/output/motor.h
add gadgets/input/battety.h
add gadgets/input/sensor.h
add gadgets/input/sensors/infraredsensor.h
add gadgets/input/sensors/ultrasonicsensor.h
add devices/flash.h
add devices/usb.h
add devices/pilot.h
add devices/robot.h
add programmer/programmer.h
add programmer/program.h
add programmer/driver.h
add programmer/programcontainer.h
add programmer/commandtable.h
add programmer/kernel.h
