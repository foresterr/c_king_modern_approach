#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  int ch;
  bool between_words = true;
  while ((ch = getchar()) != EOF) {
    if (!between_words && isspace(ch)) {
      between_words = true;
    }
    if (between_words && isalpha(ch)) {
      putchar(toupper(ch));
      between_words = false;
    }
    else {
      putchar(ch);
    }
  }
}
