/* This is the original stack.c from unit 15.2
#include "stack.h"
int contents[100];
int top = 0;
void make_empty(void)
{ ... }
int is_empty(void)
{ ... }
int is_full(void)
{ ... }
void push(int i)
{ ... }
int pop(void)
{ ... }
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

struct node {
  int value;
  struct node *next;
};

/* external variables */
struct node *top = NULL;

bool is_empty(void)
{
  return top == NULL;
}

bool push(int i)
{
  struct node *newnode = malloc(sizeof (struct node));
  if (newnode == NULL)
    return false;

  newnode->value = i;
  newnode->next = top;
  top = newnode;
  return true;
}

int pop(void)
{
  if (is_empty()) {
    printf("Error: stack underflow\n");
    exit(EXIT_FAILURE);
  } else {
    int i = top->value;
    struct node *temp = top;
    top = top->next;
    free(temp);
    return i;
  }
}

void make_empty(void)
{
  while (!is_empty()) {
    /* could just call pop() and discard return value here
     * although that introduces some unnecessary overhead*/
    struct node *temp = top;
    top = top->next;
    free(temp);
  }
}
