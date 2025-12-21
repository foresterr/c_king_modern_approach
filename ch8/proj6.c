#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MESSAGE_MAX_LENGTH 100

int main(void)
{
  char c[MESSAGE_MAX_LENGTH];
  int c_count = 0;

  printf("Enter message: ");
  while((c[c_count] = getchar()) != '\n' && c_count <= MESSAGE_MAX_LENGTH)
    c_count++;

  for (int i = 0; i < c_count; i++) {
    switch (toupper(c[i])) {
      case 'A':
        putchar('4');
        break;
      case 'B':
        putchar('8');
        break;
      case 'E':
        putchar('3');
        break;
      case 'I':
        putchar('1');
        break;
      case 'O':
        putchar('0');
        break;
      case 'S':
        putchar('5');
        break;
      default:
        putchar(toupper(c[i]));
        break;
    }
  }
  printf("!!!!!!!!!\n");

  return 0;
}

