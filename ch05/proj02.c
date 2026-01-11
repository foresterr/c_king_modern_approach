#include <stdio.h>

int main(void)
{
  int h24, h12, m;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &h24, &m);
  h12 = ((h24 - 1) % 12) + 1;
  printf("Equivalent 12-hour time: %.2d:%.2d ", h12, m);
  if (h24 < 12) printf("AM\n");
  else printf("PM\n");

  return 0;
}
