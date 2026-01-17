#include <math.h>

double evaluate_polynomial(double a[], int n, double x)
{
  double result = 1.0; /* initializing a multiplicative accumulator - it's like 0 for additive one */
  for (int i = n; i > 0; i--) {
    result *= fma(a[i], x, a[i - 1]);
  }
  return result;
}
