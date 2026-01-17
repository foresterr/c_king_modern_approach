#!/bin/bash
gcc -O -Wall -Wextra -Wpedantic -std=c99 -o $1 $1.c -lm && chmod +x $1
if [ -n "$2" ]
then
  mv $1 $2 && ./$2
else
  ./$1
fi
