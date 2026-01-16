#!/bin/bash
gcc -O -Wall -Wextra -Wno-unused-value -pedantic -std=c99 -o $1 $1.c && chmod +x $1
if [ -n "$2" ]
then
  mv $1 $2 && ./$2
else
  ./$1
fi
