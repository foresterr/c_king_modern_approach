#include <stdio.h>

#define QUOTE_INNER(n) #n
#define QUOTE(n) QUOTE_INNER(n)
#define LINE_FILE "Line " QUOTE(__LINE__) " of file " __FILE__

int main(void)
{
  int i, j = 10;
  i = SQR(j);
  printf(LINE_FILE);
  putchar('\n');
  return 0;
}
