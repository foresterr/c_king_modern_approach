#include <stdio.h>
#include <ctype.h>

#define MAXSTRLEN 100

int compute_vowel_count(const char *sentence);

int main(void)
{
  char sentence[MAXSTRLEN];
  printf("Enter a sentence: ");
  fgets(sentence, MAXSTRLEN, stdin);
  printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));
  return 0;
}

int compute_vowel_count(const char *sentence)
{
  int vowel_count = 0;
  while (*sentence)
    switch (toupper(*sentence++)) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        vowel_count++;
        break;
    }
  return vowel_count;
}
