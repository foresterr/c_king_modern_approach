#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 100

int main(void)
{
  char message[MAXSIZE], ch, *pa = message, *pb = message;
  
  printf("Enter a message: ");
  while ((ch = getchar()) != '\n' && pa < message + MAXSIZE)
    if (isalpha(ch))
      *pa++ = tolower(ch);

  while (pa > pb) 
    if (*--pa != *pb++) {
      printf("Not a palindrome\n");
      return 0;
    }

  printf("Palindrome\n");
  return 0;
}

