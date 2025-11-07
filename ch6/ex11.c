#include <stdio.h>

int main(void)
{
  int i, sum;
  sum = 0;
  for (i = 0; i < 10; i++) {
    if (i % 2)
      continue;
    sum += i;
  }
  printf("%d\n", sum);
  // this will print sum of even numbers < 10 (odd numbers are skipped with continue), so, 20
  return 0;
}
