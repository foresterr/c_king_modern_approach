#include <stdio.h>

int main(void)
{
  int i;
  i = 17;
  printf("%d\n", i >= 0 ? i : -i);
  //will print 17
  i = -17;
  printf("%d\n", i >= 0 ? i : -i);
  //will also print 17
  return 0;
}
