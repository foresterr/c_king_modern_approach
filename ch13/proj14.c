#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXSTRLEN 100

bool are_anagrams(const char *word1, const char *word2); 

int main(void)
{
  char word1[MAXSTRLEN], word2[MAXSTRLEN];

  printf("Enter first word: ");
  fgets(word1, MAXSTRLEN, stdin);
  printf("Enter second word: ");
  fgets(word2, MAXSTRLEN, stdin);

  if (are_anagrams(word1, word2))
    printf("The words are anagrams\n");
  else
    printf("The words are not anagrams\n");

  return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
  int letter_counts[26] = {0};

  while (*word1) {
    if (isalpha(*word1))
      ++letter_counts[tolower(*word1) - 'a'];
    word1++;
  }
  while (*word2) {
    if (isalpha(*word2))
      --letter_counts[tolower(*word2) - 'a'];
    word2++;
  }
  for (int i = 0; i < 26; i++)
    if (letter_counts[i] != 0)
      return false;
  
  return true;
}
