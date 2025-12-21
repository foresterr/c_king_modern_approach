#include <stdio.h>

int main(void)
{
  char c, initial;

  printf("Enter a first and a last name: ");
  scanf(" ");
  initial = getchar();
  while((c = getchar()) != ' ');
  scanf(" ");
  while(c = getchar(), c != ' ' && c != '\n') {
    putchar(c);
  }
  printf(", %c.\n", initial);
  return 0;
}
