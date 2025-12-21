#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 100

int main(void)
{
  char message[MAXSIZE], ch;
  int i = 0, j;

  printf("Enter a message: ");
  while ((ch = getchar()) != '\n')
    if (isalpha(ch))
      message[i++] = tolower(ch);

  for (j = 0, i--; j < i; j++, i--)
    if (message[i] != message[j]) {
      printf("Not a palindrome\n");
      return 0;
    }

  printf("Palindrome\n");
  return 0;
}
