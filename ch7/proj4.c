#include <stdio.h>

int main(void)
{
  char c;

  printf("Enter phone number: ");
  // input buffer is given to the program when user inputs enter (and contains \n as last char)
  do {
    c = getchar();
    if (c >= 'A' && c <= 'Y')
      c = (c - 'A') / 3 + '2';
    putchar(c);
  } while (c != '\n');

  return 0;
}
