#include <stdio.h>

int main(void)
{
  char c_last, sentence[100];
  int i = 0, j;

  printf("Enter a sentence: ");
  do {
    sentence[i++] = c_last = getchar();
  } while (c_last != '.' && c_last != '?' && c_last != '!');

  printf("Reversal of sentence: ");
  for (i--; i >= 0; i--) {
    if (i == 0 || sentence[i-1] == ' ') {
      j = i;
      while (sentence[j] != ' ' && sentence[j] != c_last) {
        putchar(sentence[j]);
        j++;
      }
      if (i == 0) {
        printf("%c\n", c_last);
      }
      else
        putchar(' ');
    }
  }

  return 0;
}
