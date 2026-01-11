#include <stdio.h>

int main(void)
{
  //this will print powers of 2 from 1 to 128
  int i = 1;
  while (i <= 128) {
    printf("%d ", i);
    i *= 2;
  }
  return 0;
}
