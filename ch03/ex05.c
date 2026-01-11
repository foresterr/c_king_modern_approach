#include <stdio.h>

int main(void)
{
  float x, y;
  int i;

  scanf("%f%d%f", &x, &i, &y);
  //this will print 12.300000 45 0.600000 after inputting 12.3 45.6 789
  printf("%f %d %f\n", x, i, y);

  return 0;
}
