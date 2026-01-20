#include <time.h>
#include <stdio.h>

int main(void)
{
  int n;
  struct tm date = {0}; /* it's important to initialize this; mktime does weird things to struct tm
                           with uninitialized fields */
  printf("Enter date (d/m/y): ");
  scanf("%d/%d/%d", &date.tm_mday, &date.tm_mon, &date.tm_year);
  printf("Enter number of days: ");
  scanf("%d", &n);
  date.tm_year -= 1900;
  date.tm_mon -= 1; /* remember that months are zero-based */
  printf("%d days after %02d/%02d/%d is ", n, date.tm_mday, date.tm_mon + 1, date.tm_year + 1900);
  date.tm_mday += n;
  mktime(&date);
  printf("%02d/%02d/%d\n", date.tm_mday, date.tm_mon + 1, date.tm_year + 1900);
}
