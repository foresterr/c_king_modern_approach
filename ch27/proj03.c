#include <stdio.h>
#include <math.h>
#include <complex.h>

int main(void)
{
  double r, theta;
  complex double c;
  printf("Enter r: ");
  scanf("%lf", &r);
  printf("Enter theta: ");
  scanf("%lf", &theta);
  c = r * cos(theta) + I * r * sin(theta);

  printf("%g%+gi\n", creal(c), cimag(c));
  return 0;
}
