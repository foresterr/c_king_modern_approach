/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* xor.c (Chapter 20, page 515) */
/* Performs XOR encryption */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
  FILE *fp_in, *fp_out;
  int orig_char, new_char;

  if (argc != 3) {
    printf("usage: xor filename1 filename2\n");
    exit(EXIT_FAILURE);
  }
  if ((fp_in = fopen(argv[1], "rb")) == NULL) {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((fp_out = fopen(argv[2], "wb")) == NULL) {
    printf("%s can't be opened\n", argv[2]);
    fclose(fp_in);
    exit(EXIT_FAILURE);
  }

  while ((orig_char = getc(fp_in)) != EOF) {
    new_char = orig_char ^ KEY;
    putc(new_char, fp_out);
  }

  return 0;
}
