#include <stdio.h>

int main(void)
{
  int i, j, k;

  i = 3; j = 4; k = 5;
  printf("%d\n", i < j || ++j < k);
  printf("%d %d %d\n", i, j, k);
  //1 then 3, 4, 5 (side effect not evaluated)
  i = 7; j = 8; k = 9;
  printf("%d\n", i - 7 && j++ < k);
  printf("%d %d %d\n", i, j, k);
  //0 then 7, 8, 9 (i - 7 = 0, so && is always false and it short circuits)
  i = 7; j = 8; k = 9;
  printf("%d\n", (i = j) || (j = k));
  printf("%d %d %d\n", i, j, k);
  //1 then 8, 8, 9
  i = 1; k = 1; j = 1;
  printf("%d\n", ++i || ++j && ++k);
  printf("%d %d %d\n", i, j, k);
  //1 then 2, 1, 1

  return 0;
}
