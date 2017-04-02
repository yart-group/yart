#!/bin/bash

source paths

echo '' > $STATIC_HEADER

add() {
  echo -e "\033[32m adding: \033[00m $1"
  cat $SRC/$1.h >> $STATIC_HEADER
  if [ $? -ne 0 ]; then
    echo -e " >\033[31m error: \033[00m idk what :D"
  fi
}

add general/config
add general/port
add general/meta
add device
add gadget
add inputgadget
add outputgadget
add iogadget
add gadgets/io/cable
add gadgets/output/motor
add gadgets/input/battery
add gadgets/input/sensor
add gadgets/input/sensors/infraredsensor
add gadgets/input/sensors/ultrasonicsensor
add devices/flash
add devices/usb
add devices/pilot
add devices/robot
add programmer/programmer
add programmer/program
add programmer/driver
add programmer/programcontainer
add programmer/commandtable
add programmer/kernel

echo ""
echo -e "\033[32m transforming #include's \033[00m..."

sed -i -e 's/#include/\/\/kappa/g' $STATIC_HEADER

echo ""
echo -e "\033[32m done\033[00m!"
