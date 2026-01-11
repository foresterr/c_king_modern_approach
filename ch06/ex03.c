#include <stdio.h>

int main(void)
{
  int i, j;
  for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
    printf("%d ", i);
  //this will print 5 4 3 2 (because the loop will terminate when j <= 0, not i - compound expression i > 0, j > 0 returns output of the second expression, output of first expression is discarded
  return 0;
}
