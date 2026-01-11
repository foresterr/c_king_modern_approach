/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* upc.c (Chapter 4, page 57) */
/* Computes a Universal Product Code check digit */

#include <stdio.h>

int main(void)
{
  int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12,
      first_sum, second_sum, total;

  printf("Enter the first 12 digits of an EAN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);

  first_sum = i2 + i4 + i6 + i8 + i10 + i12;
  second_sum = i1 + i3 + i5 + i7 + i9 + i11;
  total = 3 * first_sum + second_sum;

  printf("Check digit: %d\n", 9 - ((total - 1) % 10));

  return 0;
}
