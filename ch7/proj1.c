
/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* square2.c (Chapter 6, page 110) */
/* Prints a table of squares using a for statement */

#include <stdio.h>

int main(void)
{
  long i, n;
  //int is stored in 4 bytes (max 2^31-1) 46340 2147395600
  //short is stored in 2 bytes (max 2^15-1) 181 32761
  //long is stored in 8 bytes (max 2^63-1) 3037000499 9223372030926249001
  //also, for long, the program would run quite a long time before reaching this number

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%ld", &n);

  for (i = 1; i <= n; i++)
    printf("%30ld%30ld\n", i, i * i);

  return 0;
}
