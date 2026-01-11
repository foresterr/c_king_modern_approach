#include <stdio.h>
#include <math.h>

int main(void)
{
  double n, sqr, sqr2 = 1.0;

  printf("Enter a positive number: ");
  scanf("%lf", &n);
  do {
    sqr = sqr2;
    sqr2 = (sqr + (n / sqr)) / 2;
  } while (fabs(sqr - sqr2) > 0.00001);
  printf("Square root: %g\n", sqr2);
  return 0;
}
