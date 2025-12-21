#include <stdio.h>

#define MAXSTRLEN 100

double compute_average_word_length(const char *sentence);

int main(void)
{
  char sentence[MAXSTRLEN];

  printf("Enter a sentence: ");
  fgets(sentence, MAXSTRLEN, stdin);
  printf("Average word length: %.1f\n", compute_average_word_length(sentence));
  return 0;
}

double compute_average_word_length(const char *sentence)
{
  int ch_count = 0, w_count = 1;
  while (*sentence)
    if (*sentence++ == ' ')
      w_count++;
    else
      ch_count++;
  return (double) ch_count / w_count;
}
