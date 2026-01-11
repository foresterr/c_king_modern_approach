#include <stdio.h>

int main(void)
{
  char c, surname[20], initial;
  int i;

  printf("Enter a first and a last name: ");
  scanf(" ");
  initial = getchar();
  while((c = getchar()) != ' ');
  scanf(" ");
  i = 0;
  while(surname[i] = getchar(), surname[i] != ' ' && surname[i] != '\n')
    i++;
  printf("You entered the name: ");
  i = 0;
  while(surname[i] != ' ' && surname[i] != '\n') {
    putchar(surname[i]);
    i++;
  }
  printf(", %c.\n", initial);
  return 0;
}

