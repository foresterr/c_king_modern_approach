#include <stdio.h>

int main(void)
{
  int *i, *j;
  j = *&i;
  return 0;
}
