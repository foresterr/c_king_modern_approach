#include <stdio.h>

#define MAXSIZE 100

int main(void) {
  char message[MAXSIZE], ch;
  int i = 0;
  printf("Enter a message: ");
  while ((ch = getchar()) != '\n')
    message[i++] = ch;
  printf("Reversal is: ");
  while (i >= 0)
    putchar(message[i--]);
  putchar('\n');
  return 0;
}
