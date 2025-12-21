#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int total = 0, letter_counts[26] = {0};
  char c;

  printf("Enter first word: ");
  while((c = tolower(getchar())) != '\n') {
    if (isalpha(c)) {
      ++letter_counts[c - 'a'];
    }
  }
  printf("Enter second word: ");
  while((c = tolower(getchar())) != '\n') {
    if (isalpha(c)) {
      --letter_counts[c - 'a'];
    }
  }
  for (int i = 0; i < 26; i++) {
    if(letter_counts[i] != 0) {
      printf("The words are not anagrams\n");
      return 0;
    };
  }

  printf("The words are anagrams\n");
  return 0;
}
