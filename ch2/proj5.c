#include <stdio.h>

int main(void)
{
  int x;

  printf("Enter value: ");
  scanf("%d", &x);
  printf("Polynomial result: %d\n", 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6);

  return 0;
}
