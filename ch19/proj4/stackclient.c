/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackclient.c (Chapter 19, page 494) */

#include <stdio.h>
#include "stackADT.h"

int main(void)
{
  Stack s1, s2;
  char *str = "hello";

  s1 = create();
  s2 = create();

  push(s1, "kitty");
  push(s1, "world");

  str = pop(s1);
  printf("Popped \"%s\" from s1\n", str);
  push(s2, str);
  str = pop(s1);
  printf("Popped \"%s\" from s1\n", str);
  push(s2, str);

  destroy(s1);

  while (!is_empty(s2))
    printf("Popped \"%s\" from s2\n", (char *) pop(s2));

  push(s2, "goodbye");
  make_empty(s2);
  if (is_empty(s2))
    printf("s2 is empty\n");
  else
    printf("s2 is not empty\n");

  destroy(s2);

  return 0;
}
