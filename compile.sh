#!/bin/bash
gcc -O -Wall -Wextra -Wno-unused-value -pedantic -std=c99 -o $1 $1.c
chmod +x $1
