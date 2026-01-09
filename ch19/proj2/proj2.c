#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
  char c;
  int tmp;
  Stack stack = create();
  for (;;) {
    printf("Enter an RPN expression: ");
    do {
      scanf(" %c", &c);
      switch (c) {
        case '+':
          push(stack, pop(stack) + pop(stack));
          break;
        case '-':
          tmp = pop(stack);
          push(stack, pop(stack) - tmp);
          break;
        case '*':
          push(stack, pop(stack) * pop(stack));
          break;
        case '/':
          tmp = pop(stack);
          push(stack, pop(stack) / tmp);
          break;
        case '=':
          printf("Value of expression: %d\n", pop(stack));
          make_empty(stack);
          break;
        case 'q':
          exit(EXIT_SUCCESS);
          break;
        default:
          if (c >= '0' && c <= '9')
            push(stack, c - '0');
          break;
      }
    } while (c != '=');
  }
}
