#include <stdio.h>
#include <math.h>

int main(void)
{
  double a, b, c, delta;
  printf("Computing the roots of equation ax^2 + bx + c = 0\n");
  printf("Enter a, b, c: ");
  while (scanf(" %lf%*[ ,] %lf%*[ ,] %lf", &a, &b, &c) != 3) {
    while(getchar() != '\n') {};
    printf("Enter a, b, c: ");
  }
  delta = b*b - 4*a*c;
  if (delta < 0) {
    printf("Roots of the equation are complex\n");
    return 0;
  }
  delta = sqrt(delta);
  printf("x1: %g, x2: %g\n", (-b+delta)/2*a, (-b-delta)/2*a);
  return 0;
}
