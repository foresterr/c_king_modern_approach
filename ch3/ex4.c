#include <stdio.h>

int main(void)
{
  int x, y;
  float i;

  scanf("%d%f%d", &x, &i, &y);
  //this will print 10 0.300000 5 after scanning 10.3 5 6
  printf("%d %f %d", x, i, y);

  return 0;
}
