#include <stdio.h>

#define MAXSIZE 100

int main(void) {
  char message[MAXSIZE], ch, *pch = message;

  printf("Enter a message: ");
  while ((ch = getchar()) != '\n' && pch < message + MAXSIZE)
    *pch++ = ch;
  printf("Reversal is: ");
  while (--pch >= message)
    putchar(*pch);
  putchar('\n');
  return 0;
}

