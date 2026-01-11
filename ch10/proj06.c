#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

int contents[STACK_SIZE]; //the only thing that needs to be kept on stack are operands?
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

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

void make_empty(void)
{
  top = 0;
}

bool is_empty(void)
{
  return top == 0;
}

bool is_full(void)
{
  return top == STACK_SIZE;
}

void push(char c)
{
  if (is_full())
    stack_overflow();
  else
    contents[top++] = c;
}

char pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];
}

void stack_underflow(void)
{
  printf("Not enough operands\n");
  exit(EXIT_FAILURE);
}

void stack_overflow(void)
{
  printf("Expression too complex\n");
  exit(EXIT_FAILURE);
}

