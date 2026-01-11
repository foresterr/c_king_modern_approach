#include <stdio.h>
#include <string.h>

#define MAXLEN 20

int main(void)
{
  char smallest_word[MAXLEN + 1] = "\xff", largest_word[MAXLEN + 1] = "", current_word[MAXLEN + 1];
  for (;;) {
    printf("Enter word: ");
    scanf("%s", current_word);
    if (strcmp(current_word, largest_word) > 0)
      strcpy(largest_word, current_word);
    if (strcmp(current_word, smallest_word) < 0)
      strcpy(smallest_word, current_word);
    if (strlen(current_word) == 4)
      break;
  }
  printf("Smallest word: %s\nLargest word: %s\n", smallest_word, largest_word);
  return 0;
}
