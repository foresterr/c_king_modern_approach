#include <stdio.h>

int main(void)
{
  int n, fa = 1;
  float e = 1.0f;

  printf("Enter n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    fa *= i;
    e += 1.0f / fa;
  }

  printf("Approximation of e to term %d: %f\n", n, e);
  return 0;
}
