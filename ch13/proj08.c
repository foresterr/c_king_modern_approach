#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100

int compute_scrabble_value(const char *word);

int main(void)
{
  char word[MAXLEN];

  printf("Enter a word: ");
  scanf("%s", word);
  printf("Scrabble value: %d\n", compute_scrabble_value(word));
  return 0;
}  


int compute_scrabble_value(const char *word)
{
  int value = 0;
  const int letter_values[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
 /* A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P,  Q, R, S, T, U, V, W, X, Y,  Z */  
  };
  while (*word)
    value += letter_values[toupper(*word++) - 'A'];
  return value;
}
