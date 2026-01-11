#include <stdio.h>

int main(void) {
  int i, j, k;

  i = 7; j = 8; i *= j + 1;
  //i = 63, j = 8
  printf("%d %d\n", i, j);
  i = j = k = 1;
  i += j += k;
  //i = 3, j = 2, k = 1
  printf("%d %d %d\n", i, j, k);
  i = 1; j = 2; k = 3;
  i -= j -= k;
  //i = 2, j = -1, k = 3
  printf("%d %d %d\n", i, j, k);
  i = 2; j = 1; k = 0;
  i *= j *= k;
  //i = 0, j = 0, k = 0
  printf("%d %d %d\n", i, j, k);
  i = 6;
  j = i += i;
  //i = 12, j = 12
  printf("%d %d\n", i, j);
  i = 5;
  j = (i -= 2) + 1;
  // i = 3, j = 4
  printf("%d %d\n", i, j);
  i = 7;
  j = 6 + (i = 2.5);
  // i = 2, j = 8
  printf("%d %d\n", i, j);
  i = 2; j = 8;
  j = (i = 6) + (j = 3);
  // i = 6, j = 9 
  printf("%d %d\n", i, j);
  i = 1;
  // i1 = 0, i2 = 2
  printf("%d ", i++ - 1);
  printf("%d\n", i);
  i = 10; j = 5;
  // o1 = 4, i = 11, j = 6
  printf("%d ", i++ - ++j);
  printf("%d %d\n", i, j);
  i = 7; j = 8;
  // o1 = 0, i = 8, j = 7
  printf("%d ", i++ - --j);
  printf("%d %d\n", i, j);
  i = 3; j = 4; k = 5;
  // o1 = 3, i = 4, j = 5, k = 4
  printf("%d ", i++ - j++ + --k);
  printf("%d %d %d\n", i, j, k);
  i = 5;
  j = ++i * 3 - 2;
  // i = 6, j = 16
  printf("%d %d\n", i, j);
  i = 5;
  j = 3 - 2 * i++;
  // i = 6, j = -7
  printf("%d %d\n", i, j);
  i = 7;
  j = 3 * i-- + 2;
  // i = 6, j = 23 
  printf("%d %d\n", i, j);
  i = 7;
  j = 3 + --i * 2;
  // i = 6, j = 15 
  printf("%d %d\n", i, j);

  return 0;
}
