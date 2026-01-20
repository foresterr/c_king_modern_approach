#include <stdio.h>
#include <time.h>

int main(void)
{
  struct tm dt1 = {0}, dt2 = {0};
  printf("Enter first date (d/m/y): ");
  scanf("%d/%d/%d", &dt1.tm_mday, &dt1.tm_mon, &dt1.tm_year);
  dt1.tm_mon--;
  dt1.tm_year -= 1900;
  printf("Enter second date (d/m/y): ");
  scanf("%d/%d/%d", &dt2.tm_mday, &dt2.tm_mon, &dt2.tm_year);
  dt2.tm_mon--;
  dt2.tm_year -= 1900;
  printf("Difference between those dates is %g days\n",
          difftime(mktime(&dt2), mktime(&dt1)) / (24 * 60 * 60));
}
