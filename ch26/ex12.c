#include <time.h>
#include <stdlib.h>
#include <stdio.h>

time_t year_start(int year) {
  /* initializes all fields to 0. I mean, screw "12:00 AM", I'll assume that's midnight / 00:00 */
 struct tm ys = {0};
  ys.tm_year = year - 1900;
  /* note: tm_mday is initialized to 0, which mktime will treat as "1 day in the past" for the
   * ranges adjustment, so it's necessary to set to 1 */
  ys.tm_mday = 1;
  return mktime(&ys);
}

int main(void)
{
  char timestr[100];
  time_t yearstart_time = year_start(2024);
  strftime(timestr, sizeof(timestr), "%F %T", localtime(&yearstart_time));
  printf("%s\n", timestr);
}
