
#include <stdio.h>

int main(void)
{
  int num, den, m, n, s;

  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &den);
  m = num, n = den;
  while (n > 0) {
    s = n;
    n = m % n;
    m = s;
  }
  printf("In lowest terms: %d/%d\n", num / m, den / m);
  return 0;
}
