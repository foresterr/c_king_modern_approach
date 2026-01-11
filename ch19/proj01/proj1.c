#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

bool match(char c1, char c2);
void finish_fail(void);

int main(void)
{
  char c;
  Stack stack = create();
  printf("Enter parentheses and/or braces: ");
  while ((c = getchar()) != '\n') {
    if (c == '(' || c == '{')
      push(stack, c);
    else if (c == ')' || c == '}') {
      if (!match(pop(stack), c)) {
        finish_fail();
      }
    }
  }
  if (is_empty(stack)) {
    printf("Parentheses/braces are nested properly\n");
    exit(EXIT_SUCCESS);
  } else
    finish_fail();
}

bool match(char c1, char c2)
{
  if ((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}'))
    return true;
  else
    return false;
}

void finish_fail(void)
{
  printf("Parentheses/braces are not nested properly\n");
  exit(EXIT_SUCCESS);
}
