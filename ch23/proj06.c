#include <ctype.h>
#include <stdio.h>

int main(void)
{
  int ch;
  while ((ch = getchar()) != EOF) {
    putchar(iscntrl(ch) && ch != '\n' ? '?' : ch);
  }
  return 0;
}
