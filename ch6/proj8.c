#include <stdio.h>

int main(void)
{
  int n, day, i;

  printf("Enter number of days in month: ");
  scanf("%d", &n);
  printf("Enter starting day of the week (1 = Sun, 7 = Sat): ");
  scanf("%d", &day);
  for (i = 1; i < day; i++) {
    printf("   ");
  }
  for (i = 1; i <= n; i++) {
    printf("%3d", i);
    if ((i + day) % 7 == 1)
      printf("\n");
  }
  printf("\n");
  return 0;
}
