#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

int contents[STACK_SIZE]; //the only thing that needs to be kept on stack are operands?
int top = 0;

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
  if (is_empty()) {
    stack_underflow();
    return '\0';
  }
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

