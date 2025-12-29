#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
  char c;
  int tmp;
  for (;;) {
    printf("Enter an RPN expression: ");
    do {
      scanf(" %c", &c);
      switch (c) {
        case '+':
          push(pop() + pop());
          break;
        case '-':
          tmp = pop();
          push(pop() - tmp);
          break;
        case '*':
          push(pop() * pop());
          break;
        case '/':
          tmp = pop();
          push(pop() / tmp);
          break;
        case '=':
          printf("Value of expression: %d\n", pop());
          make_empty();
          break;
        case 'q':
          exit(EXIT_SUCCESS);
          break;
        default:
          if (c >= '0' && c <= '9')
            push(c - '0');
          break;
      }
    } while (c != '=');
  }

}

