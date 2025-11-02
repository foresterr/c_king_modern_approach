
/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* broker.c (Chapter 5, page 81) */
/* Calculates a broker's commission */

#include <stdio.h>

int main(void)
{
  float commission, rival_comission, value, shareprice;
  int shares;

  printf("Enter price per share: ");
  scanf("%f", &shareprice);
  printf("Enter number of shares: ");
  scanf("%d", &shares);

  value = shares * shareprice;

  if (value < 2500.00f)
    commission = 30.00f + .017f * value;
  else if (value < 6250.00f)
    commission = 56.00f + .0066f * value;
  else if (value < 20000.00f)
    commission = 76.00f + .0034f * value;
  else if (value < 50000.00f)
    commission = 100.00f + .0022f * value;
  else if (value < 500000.00f)
    commission = 155.00f + .0011f * value;
  else
    commission = 255.00f + .0009f * value;

  if (commission < 39.00f)
    commission = 39.00f;

  if (shares < 2000)
    rival_comission = 33.00f + .03f * shares;
  else
    rival_comission = 33.00f + .02f * shares;

  printf("Commission: $%.2f\n", commission);
  printf("Rival comission: $%.2f\n", rival_comission);

  return 0;
}
