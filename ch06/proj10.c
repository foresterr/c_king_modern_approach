#include <stdio.h>

int main(void)
{
  int d1, m1, y1,
      d2, m2, y2 = 100;

  for (;;) {
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m1, &d1, &y1);

    if (m1 == 0 && d1 == 0 && y1 == 0)
      break;

    if (y2 > y1 || (y1 == y2 && m2 > m1) || (y1 == y2 && m1 == m2 && d2 > d1))
      d2 = d1, m2 = m1, y2 = y1;
  }

  printf("%d/%d/%2.2d is the earliest date\n", m2, d2, y2);

  return 0;
}
