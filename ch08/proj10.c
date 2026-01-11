#include <stdio.h>

int main(void)
{
  int arrivals[8] = {
    10*60 + 16,
    11*60 + 52,
    13*60 + 31,
    15*60,
    16*60 + 8,
    17*60 + 55,
    21*60 + 20,
    11*60 + 58
  };
  int departures[8] = {
    8*60,
    9*60 + 43,
    11*60 + 19,
    12*60 + 47,
    14*60,
    15*60 + 45,
    19*60,
    21*60
  };
  int i, h, m, mcount;

  printf("Enter a 24-h time: ");
  scanf("%d:%d", &h, &m);

  mcount = h * 60 + m;
  i = 0;

  while (mcount > departures[i]) {
    i++;
  }

  m = arrivals[i] % 60;
  h = ((arrivals[i] / 60) - 1) % 12 + 1;

  printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
      ((departures[i] / 60) - 1) % 12 + 1,
      departures[i] % 60,
      departures[i] < 12*60 ? 'a' : 'p',
      ((arrivals[i] / 60) - 1) % 12 + 1,
      arrivals[i] % 60,
      arrivals[i] < 12*60 ? 'a' : 'p'
  );

  return 0;
}

