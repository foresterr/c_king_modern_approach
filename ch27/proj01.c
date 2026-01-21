/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* quadratic.c (Chapter 27, page 723) */
/* Finds the roots of the equation 5x**2 + 2x + 1 = 0 */

#include <complex.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
  double a, b, c;
  printf("Enter coefficient of a quadratic polynomial (ax^2 + bx + c = 0): ");
  scanf("%lf %lf %lf", &a, &b, &c);
  double discriminant = b * b - 4 * a * c;
  double complex discriminant_sqrt = csqrt(b * b - 4 * a * c);
  double complex root1 = (-b + discriminant_sqrt) / (2 * a);
  double complex root2 = (-b - discriminant_sqrt) / (2 * a);

  if (discriminant >= 0) {
  printf("root1 = %g\n", creal(root1));
  printf("root2 = %g\n", creal(root2));
  }
  else {
    double img1 = cimag(root1), img2 = cimag(root2);
  printf("root1 = %g %c %gi\n", creal(root1), signbit(img1) ? '-' : '+', fabs(img1));
  printf("root2 = %g %c %gi\n", creal(root2), signbit(img2) ? '-' : '+', fabs(img2));
  }

  return 0;
}
