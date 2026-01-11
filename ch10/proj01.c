#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);
bool match(char c1, char c2);
void finish_fail(void);

int main(void)
{
  char c;
  printf("Enter parentheses and/or braces: ");
  while ((c = getchar()) != '\n') {
    if (c == '(' || c == '{')
      push(c);
    else if (c == ')' || c == '}') {
      if (!match(pop(), c)) {
        finish_fail();
      }
    }
  }
  if (is_empty()) {
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
  finish_fail();
}

void stack_overflow(void)
{
  printf("Stack overflow\n");
  exit(EXIT_FAILURE);
}
