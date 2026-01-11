#include <stdio.h>

struct timetable_entry {
  int departure;
  int arrival;
};

int main(void)
{
  int i, last, h, m, mcount;
  const struct timetable_entry timetable[] = {
    { 8*60,    10*60+16},
    { 9*60+43, 11*60+52},
    {11*60+19, 13*60+31},
    {12*60+47, 15*60   },
    {14*60,    16*60+8 },
    {15*60+45, 17*60+55},
    {19*60,    21*60+20},
    {21*60+45, 23*60+58}
  };

  printf("Enter a 24-h time: ");
  scanf("%d:%d", &h, &m);

  mcount = h * 60 + m;

  last = (int) (sizeof(timetable) / sizeof(timetable[0])) - 1;

  for (i = 0; i <= last; i++) {
    if (mcount < timetable[i].departure) {
      break;
    } else if (i == last) {
      i = 0;
      break;
    }
  }

  printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n", 
    (timetable[i].departure / 60 + 11) % 12 + 1,
    timetable[i].departure % 60,
    timetable[i].departure / 60 < 12 ? 'a' : 'p',
    (timetable[i].arrival / 60 + 11) % 12 + 1,
    timetable[i].arrival % 60,
    timetable[i].arrival / 60 < 12 ? 'a' : 'p'
  );

  return 0;
}
