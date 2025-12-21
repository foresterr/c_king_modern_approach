#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
  int num, den, num_r, den_r;

  printf("Enter a fraction: ");
  (void) scanf("%d/%d", &num, &den);
  reduce(num, den, &num_r, &den_r);
  printf("In lowest terms: %d/%d\n", num_r, den_r);
  return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
  int m = numerator, n = denominator, tmp;
  while (n > 0) {
    tmp = n;
    n = m % n;
    m = tmp;
  }
  *reduced_numerator = numerator / m;
  *reduced_denominator = denominator /m;
}
