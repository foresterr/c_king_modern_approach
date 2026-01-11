#include <stdio.h>

int main(void)
{
  int d,m,y;

  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &m, &d, &y);
  printf ("You entered the date %4.4d%2.2d%2.2d\n", y, m, d);

  return 0;
}
