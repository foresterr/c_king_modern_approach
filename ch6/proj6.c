#include <stdio.h>

int main(void)
{
  int n, m;

  printf("Enter n: ");
  scanf("%d", &n);
  for (m = 2; m * m <= n; m += 2) {
    printf("%d\n", m * m);
  }

  return 0;
}
