#include <stdio.h>

int main(void)
{
  int m, n, s;

  printf("Enter two integers: ");
  scanf("%d %d", &m, &n);
  while (n > 0) {
    s = n;
    n = m % n;
    m = s;
  }
  printf("Greatest common divisor: %d\n", m);
  return 0;
}
