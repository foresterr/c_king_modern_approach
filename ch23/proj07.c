#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
  int ch, count;
  while ((ch = getchar()) != EOF) {
    /* repeatedly reading from stream at its end will repeteadly return EOF, so no need to
     * check after getchar call inside the loop */
    if (strchr(".?!", ch) && isspace(getchar())) {
      count++;
    }
  }
  printf("Number of sentences found: %d\n", count);
  return 0;
}
