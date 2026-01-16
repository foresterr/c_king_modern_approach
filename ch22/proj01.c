/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* canopen.c (Chapter 22, page 547) */
/* Checks whether a file can be opened for reading */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int exit_status = EXIT_SUCCESS;

  if (argc < 2) {
    printf("usage: canopen filename1 [... filenameN]\n");
    exit(EXIT_FAILURE);
  }
  while(*++argv != NULL) {
    if ((fp = fopen(*argv, "r")) == NULL) {
      printf("%s can't be opened\n", *argv);
      exit_status = EXIT_FAILURE;
    }
    else {
      printf("%s can be opened\n", *argv);
      fclose(fp);
    }
  }
  exit(exit_status);
}
