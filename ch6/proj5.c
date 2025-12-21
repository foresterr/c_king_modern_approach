
#include <stdio.h>

int main(void) {
  int n;
  printf("Enter an integer: ");
  scanf("%d", &n);
  printf("The reversal is: ");
  do {
    printf("%d", n % 10);
    n = n / 10;
  } while (n > 0);
  printf("\n");
  return 0;
}
