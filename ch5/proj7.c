#include <stdio.h>

int main(void)
{
  int i1, i2, i3, i4, min, max, min1, max1;

  printf("Enter four integers: ");
  scanf("%d %d %d %d", &i1, &i2, &i3, &i4);
  
  if (i1 > i2) {
    min = i2;
    max = i1;
  }
  else {
    min = i1;
    max = i2;
  }
  if (i3 > i4) {
    min1 = i4;
    max1 = i3;
  }
  else {
    min1 = i3;
    max1 = i4;
  }
  if (max1 > max) max = max1;
  if (min1 < min) min = min1;

  printf("Largest: %d\n", max);
  printf("Smallest: %d\n", min);

  return 0;
}
