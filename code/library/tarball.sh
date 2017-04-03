#!/bin/bash

source paths

echo '' > $TARBALL_HEADER
echo '' > $TARBALL_SOURCE

add() {
  echo -e "\033[32m adding: \033[00m $1"

  cat $SRC/$1.h >> $TARBALL_HEADER

  if [ "$1" != "general/config" ]; then
    cat $SRC/$1.cpp >> $TARBALL_SOURCE
  fi

  if [ $? -ne 0 ]; then
    echo -e " >\033[31m error: \033[00m idk what :D"
  fi
}

source files

echo ""
echo -e "\033[32m transforming #include's \033[00m..."

sed -i -e 's/#include/\/\/kappa/g' $TARBALL_HEADER
sed -i -e 's/#include/\/\/kappa/g' $TARBALL_SOURCE

echo ""
echo -e "\033[32m adding to tarball \033[00m..."

tar -czf $TARBALL/$TARBALL_NAME $TARBALL_HEADER $TARBALL_SOURCE

echo ""
echo -e "\033[32m done\033[00m!"
