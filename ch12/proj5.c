#include <stdio.h>

#define MAXLEN 100

int main(void)
{
  char c_last, sentence[MAXLEN], *pch = sentence, *pword;

  printf("Enter a sentence: ");
  do {
    *pch++ = c_last = getchar();
  } while (c_last != '.' && c_last != '?' && c_last != '!');

  printf("Reversal of sentence: ");
  while (--pch >= sentence) {
    if (pch == sentence || *(pch - 1) == ' ') {
      pword = pch;
      while (*pword != ' ' && *pword != c_last) {
        putchar(*pword++);
      }
      if (pch == sentence) {
        putchar(c_last);
        putchar('\n');
      } else {
        putchar(' ');
      }
    }
  }

  return 0;
}

