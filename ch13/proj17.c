#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXSIZE 100

char *read_line(char *str, int n);
bool is_palindrome(const char *message);

int main(void)
{
  char message[MAXSIZE];
  
  printf("Enter a message: ");
  read_line(message, MAXSIZE);
  if (is_palindrome(message))
    printf("Palindrome\n");
  else
    printf("Not a palindrome\n");

  return 0;
}

bool is_palindrome(const char *message)
{
  char message_clean[MAXSIZE], *p1 = message_clean, *p0 = message_clean;
  // remove nonalphabetic characters and convert to lowercase first
  while (*message) {
    if (isalpha(*message))
      *p1++ = tolower(*message);
    message++; 
  }
  // check if palindrome
  while (p0 < p1)
    if (*p0++ != *--p1)
      return false;
  return true;
}

char *read_line(char *str, int n)
{
  char *pch = str, ch;
  while ((ch = getchar()) != '\n' && pch < str + n - 1)
    *pch++ = ch;
  *pch = '\0';
  return str;
}
