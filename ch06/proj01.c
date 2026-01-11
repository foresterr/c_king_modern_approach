#include <stdio.h>

int main(void)
{
  float f, max = 0;

  do {
    printf("Enter a number: ");
    scanf("%f", &f);
    if (f > max)
      max = f;
  } while (f > 0);
  printf("The largest number entered was %g\n", max);
  return 0;
}
