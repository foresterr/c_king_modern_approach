#include <stdio.h>
#include <ctype.h>

int main(void)
{
  short h, m;
  char ind;

  printf("Enter a 12-hour time: ");
  scanf("%hd:%hd %c", &h, &m, &ind);

  if (toupper(ind) == 'A' && h == 12)
    h = 0;
  else if (toupper(ind) == 'P' && h != 12)
    h += 12;

  printf("Equivalent 24-hour time: %2.2d:%2.2d\n", h, m);
  return 0;
}
