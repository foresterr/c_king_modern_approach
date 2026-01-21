#include <stdio.h>
#include <complex.h>

int main(void)
{
  double a, b;
  complex double c;
  printf("Enter a (real): ");
  scanf("%lf", &a);
  printf("Enter b (imaginary): ");
  scanf("%lf", &b);
  c = a + b * I;

  printf("r = %g, θ = %g\n", cabs(c), carg(c));
  return 0;
}
