
/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* repdigit.c (Chapter 8, page 166) */
/* Checks numbers for repeated digits */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
  int digit_seen[10] = {0};
  int digit;
  long n;
  bool any_rep = false;

  printf("Enter a number: ");
  scanf("%ld", &n);

  printf("Repeated digit(s): ");

  while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit] == 1) {
      printf("%d ", digit);
      any_rep = true;
    }
    ++digit_seen[digit];
    n /= 10;
  }

  if (!any_rep)
    printf("none");
  printf("\n");

  return 0;
}
