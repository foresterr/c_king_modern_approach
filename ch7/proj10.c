#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char c;
  int total = 0;
  printf("Enter a sentence: ");
  while((c = toupper(getchar())) != '\n') {
    switch (c) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        total++;
        break;
    }
  }
  printf("Your sentence contains %d vowels.\n", total);
  return 0;
}
