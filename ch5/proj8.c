#include <stdio.h>

int main(void)
{
  int h, m, mcount;

  printf("Enter a 24-h time: ");
  scanf("%d:%d", &h, &m);

  mcount = h * 60 + m;

  printf("Closest departure time is ");
  if (mcount <= (8 * 60) || mcount > (21 * 60 + 45))
    printf("8:00 a.m., arriving at 10:16 a.m.");
  else if (mcount <= 9 * 60 + 43)
    printf("9:43 a.m., arriving at 11:52 a.m.");
  else if (mcount <= 11 * 60 + 19)
    printf("11:19 a.m., arriving at 1:31 p.m.");
  else if (mcount <= 12 * 60 + 47)
    printf("12:47 p.m., arriving at 3:00 p.m.");
  else if (mcount <= 14 * 60)
    printf("2:00 p.m., arriving at 4:08 p.m.");
  else if (mcount <= 15 * 60 + 45)
    printf("3:45 p.m., arriving at 5:55 p.m.");
  else if (mcount <= 19 * 60)
    printf("7:00 p.m., arriving at 9:20 p.m.");
  else
    printf("9:00 p.m., arriving at 11:58 p.m.");
  printf("\n");

  return 0;
}
