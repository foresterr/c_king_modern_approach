#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_TOKENS 20

int main(void)
{
  char inputstr[MAX_STR_LEN], *words[MAX_TOKENS], *curr_tok;
  int nwords = 0;

  printf("Enter words separated by spaces: ");
  if (fgets(inputstr, sizeof(inputstr), stdin) == NULL) {
    return 0;
  }

  curr_tok = strtok(inputstr, " \n");
  while (curr_tok != NULL && nwords < MAX_TOKENS) {
    words[nwords++] = curr_tok;
    curr_tok = strtok(NULL, " \n");
  }

  printf("Words in reverse order: ");
  for (int i = nwords - 1; i >= 0; i--) {
    printf("%s ", words[i]);
  }
  putchar('\n');

  return 0;
}
