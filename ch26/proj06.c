#include <stdio.h>
#include <time.h>

int main(void)
{
  time_t now = time(NULL);
  struct tm *now_tm = localtime(&now);
  char timedatestr[50];
  strftime(timedatestr,sizeof(timedatestr),"%A, %B %e, %Y  %I:%M%%c\n", now_tm);
  printf("Format 1:\n");
  printf(timedatestr, now_tm->tm_hour < 12 ? 'a' : 'p');
  strftime(timedatestr,sizeof(timedatestr),"%a, %e %b %g  %R", now_tm);
  printf("\nFormat 2:\n");
  puts(timedatestr);
  strftime(timedatestr,sizeof(timedatestr),"%m/%d/%g  %%d:%M:%S %p\n", now_tm);
  printf("\nFormat 3:\n");
  printf(timedatestr, (now_tm->tm_hour + 11) % 12 + 1);

  /* OK, fine, I suppose that constructing output from strftime so it constituted valid format
   * string for printf was a bit insane, but I'm keeping it exactly because of that.
   */
}
