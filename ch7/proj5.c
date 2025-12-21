#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int value = 0;
  char c;

  printf("Enter a word: ");
  do {
    c = toupper(getchar());
    switch (c) {
      case 'A': case 'E': case 'I': case 'L': case 'N':
      case 'O': case 'R': case 'S': case 'T': case 'U':
        value += 1;
        break;
      case 'D': case 'G':
        value += 2;
        break;
      case 'B': case 'C': case 'M': case 'P':
        value += 3;
        break;
      case 'F': case 'H': case 'V': case 'W': case 'Y':
        value += 4;
        break;
      case 'K':
        value += 5;
        break;
      case 'J': case 'X':
        value += 8;
      case 'Q': case 'Z':
        value += 10;
    }
  } while (c != '\n');
  printf("Scrabble value: %d\n", value);
  return 0;
}
