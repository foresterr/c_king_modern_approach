#include <stdio.h>

struct date {
  int day;
  int month;
  int year;
};

int compare_dates(struct date d1, struct date d2);

int main(void)
{
  struct date d1, d2;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

  if (compare_dates(d1, d2) > 0)
    printf("%d/%d/%d is earlier than %d/%d/%d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d2.year);
  else
    printf("%d/%d/%d is earlier than %d/%d/%d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);

  return 0;
}

int compare_dates(struct date d1, struct date d2)
{
  if (d1.year != d2.year) 
    return d1.year > d2.year ? 1 : -1;
  else if (d1.month != d2.month) 
    return d1.month > d2.month ? 1 : -1;
  else if (d1.day != d2.day)
    return d1.day > d2.day ? 1 : -1;
  else
    return 0;
}
