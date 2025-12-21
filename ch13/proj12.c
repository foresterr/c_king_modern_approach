#include <stdio.h>

#define MAXSTRLEN 20
#define MAXSENTENCES 30

int main(void)
{
  char ch, *word, words[MAXSENTENCES][MAXSTRLEN + 1];
  int word_count = 0;

  printf("Enter a sentence: ");
  word = words[word_count];
  while ((ch = getchar()) != '\n') {
    if (ch == ' ' || ch == '.' || ch == '?' || ch == '!') {
      *word = '\0';
      if (ch != ' ')
        break;
      word = words[++word_count];
    } else
      *word++ = ch;
  }

  printf("Reversal of sentence: ");
  while (word_count >= 0) {
    printf("%s", words[word_count]);
    if (word_count--)
      putchar(' ');
    else
      putchar(ch);
  }
  putchar('\n');
  return 0;
}

