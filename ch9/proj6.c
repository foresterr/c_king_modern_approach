#include <stdio.h>

double poly(double x);

int main(void)
{
  double x;
  printf("Input a number: ");
  scanf("%lf", &x);
  printf("Calculated polynomial: %g\n", poly(x));
  return 0;
}

double poly(double x)
{
  const int factors[] = {-6, 7, -1, -5, 2, 3};
  double pow = 1.0, result = 0.0;

  for (int n = 0; n < sizeof(factors) / sizeof(factors[0]); n++) {
    result += factors[n] * pow;
    pow *= x;
  }

  return result;
}
