#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 100

int read_line(char *str, int n);
int string_comp(const void *p1, const void *p2);

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

  qsort(words, word_count, sizeof(words[0]), string_comp);

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

int string_comp(const void *p1, const void *p2)
{
  /* note: comparison function passed to qsort gets _pointers_ to array elements as args, not the 
   * array elements themselves. So in this case - pointers to pointers to char. If it was array 
   * of integers, it would be pointers to int, if structures - pointers to structs (which is why
   * when using qsort to sort a table of structs we were using -> operator to access fields, not .)
   */
  return strcmp(*(char **)p1, *(char **)p2);
}
