#include <stdio.h>

int main(void)
{
  int d1, m1, y1,
      d2, m2, y2;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &m1, &d1, &y1);

  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &m2, &d2, &y2);

  if (y2 > y1 || (y1 == y2 && m2 > m1) || (y1 == y2 && m1 == m2 && d2 > d1))
    printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
  else
    printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);

  return 0;
}
