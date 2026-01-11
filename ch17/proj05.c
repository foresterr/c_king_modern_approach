#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 100

int read_line(char *str, int n);

int main(void) {
  char current_word[MAX_WORD_LEN + 1], *words[MAX_WORDS];
  int word_count = 0;

  for (int i = 0; i < MAX_WORDS; i++) {
    printf("Enter word: ");
    int l = read_line(current_word, MAX_WORD_LEN + 1);
    if (l > 0) {
      words[i] = malloc(l + 1);
      if (words[i] == NULL) {
        printf ("Error allocating memory\n");
        exit(EXIT_FAILURE);
      }
      strcpy(words[i], current_word);
      word_count++;
    } else
      break;
  }

  /* selection sort */
  for (int i = word_count - 1; i >= 0; i--)
    for (int j = 0; j < i; j++)
      if (strcmp(words[j], words[j + 1]) > 0) {
        char *tmp = words[j];
        words[j] = words[j + 1];
        words[j + 1] = tmp;
      }


  printf("In sorted order: ");
  for (int i = 0; i < word_count; i++)
    printf("%s ", words[i]);
  putchar('\n');

  return 0;
}

/* readline returns number of chars in read string
 * (without the null terminator)
 */
int read_line(char *str, int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
