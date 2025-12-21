#include <stdio.h>

int main(void)
{
  int dd, mm, yyyy;
  char *monthnames[] = {"", "January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};

  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &mm, &dd, &yyyy);
  printf("You entered the date %s %d, %d\n", monthnames[mm], dd, yyyy);
  return 0;
}
