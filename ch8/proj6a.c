#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
  char c;
  bool flag = false;
  printf("Enter message: ");
  //in principle, I don't need to use array for this
  while((c = getchar()) != '\n') {
    if (!flag) {
      printf("In B1FF-speak: ");
      flag = true;
    }
    switch (toupper(c)) {
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
        putchar(toupper(c));
        break;
    }
  }
  printf("!!!!!!!!!\n");

  return 0;
}

