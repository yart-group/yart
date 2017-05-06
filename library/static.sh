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

source files

echo ""
echo -e "\033[32m transforming #include's \033[00m..."

sed -i -e 's/#include/\/\/kappa/g' $STATIC_HEADER
sed -i -e 's/\/\/kappa <cstring>/#include <cstring>/g' $STATIC_HEADER

echo ""
echo -e "\033[32m done\033[00m!"