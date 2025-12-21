#include <stdio.h>

#define MAXSTRLEN 100

int main(void)
{
  char word1[MAXSTRLEN], word2[MAXSTRLEN];

  printf("Enter first word: ");
  fgets(word1, MAXSTRLEN, stdin);
  //printf("%s", word1);
  printf("Enter second word: ");
  fgets(word2, MAXSTRLEN, stdin);
  //printf("%s", word2);

  return 0;
}

