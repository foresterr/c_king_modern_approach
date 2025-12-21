#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

void reverse(char *message);
char *read_line(char *str, int n);

int main(void) {
  char message[MAXSIZE];

  printf("Enter a message: ");
  reverse(read_line(message, MAXSIZE));
  printf("Reversal is: %s\n", message);

  return 0;
}

void reverse(char *p1)
{
  char *p2 = p1, tmp;
  while (*p2++);
  p2 -= 2;
  while (p2 > p1) {
    tmp = *p1;
    *p1++ = *p2;
    *p2-- = tmp;
  }
}

char *read_line(char *str, int n)
{
  char *pch = str, ch;
  while ((ch = getchar()) != '\n' && pch < str + n - 1)
    *pch++ = ch;
  *pch = '\0';
  return str;
}

