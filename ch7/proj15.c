#include <stdio.h>

int main(void)
{
  int n;
  long double factorial = 1;
  //short works up to 7
  //int works up to 16
  //long works up to 25
  //long long works but is equivalent to long
  //float works up to 34
  //double works up to 170
  //long double works up to 1754 (and the digits take up half the screen)
  
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    factorial *= i;
  }
  printf("Factorial of %d: %.0Lf\n", n, factorial);
  return 0;
}
