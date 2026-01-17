#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int ch = 0;
  while (ch != EOF) {
    /* general style guidance, after comparing to official answer:
     * nested loops are stylistically worse from a single loop
     * repetition is to be avoided if possible (getchar and comparison to EOF)
     * but, it works, so I'm leaving it*/
    while (isspace(ch = getchar()) && ch != EOF) {}
    ungetc(ch, stdin);
    while ((ch = getchar()) != '\n' && ch != EOF) {
      putchar(ch);
    }
    if (ch == '\n') {
      putchar(ch);
    }
  }
  return 0;
}
