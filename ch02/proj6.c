#include <stdio.h>

int main(void)
{
  int x;

  printf("Enter value: ");
  scanf("%d", &x);
  printf("Polynomial result: %d\n", ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6 );

  return 0;
}
