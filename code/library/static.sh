#!/bin/bash

SRC='src/src'
BUILD='unknown'
HEADER='static/libarduino.h'
LIBRARY='static/libarduino.a'

echo '' > $HEADER

add() {
  echo -e "\033[32m adding: \033[00m $1"
  cat $SRC/$1 >> $HEADER
  if [ $? -ne 0 ]; then
    echo -e " >\033[31m error: \033[00m idk what :D"
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
add gadgets/input/battery.h
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

echo ""
echo -e "\033[32m transforming #include's \033[00m..."

sed -i -e 's/#include/\/\/kappa/g' $HEADER

echo ""
echo -e "\033[32m done\033[00m!"
