#include <stdio.h>
#include <stdlib.h>
#include "stack_b.h"

__attribute__ ((noreturn))
static void terminate(char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void make_empty(Stack *s)
{
  if (!is_empty(s))
    pop(s);
}

bool is_empty(const Stack *s)
{
  return *s == NULL;
}

bool is_full(const Stack *s)
{
  return false;
}

void push(Stack *s, int i)
{
  struct node *new_top = malloc(sizeof(struct node));
  if (new_top == NULL)
    terminate("Error in push: cannot allocate space for new stack element");
  new_top->value = i;
  new_top->next = *s;
  *s = new_top;
}

int pop(Stack *s)
{
  if (is_empty(s))
    terminate("Error in pop: stack is empty");
  struct node *old_top = *s;
  int tmp = old_top->value;
  *s = old_top->next;
  free(old_top);
  return tmp;
}

