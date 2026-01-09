#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node *next;
};

struct node *first = NULL, *last = NULL;

__attribute__ ((noreturn))
static void terminate(char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

bool queue_is_empty(void)
{
  return first == NULL;
}

bool queue_is_full(void)
{
  return false;
}

void queue_clear(void)
{
  while(!queue_is_empty())
    queue_pop();
}

void queue_push(int i)
{
  struct node *new = malloc(sizeof(struct node));
  if (new == NULL)
    terminate("Malloc failed in queue_push.");

  new->value = i;
  new->next = NULL;

  if (queue_is_empty())
    first = last = new;
  else
    last = last->next = new;
}

int queue_pop(void)
{
  if(queue_is_empty())
    terminate("Error in queue_pop: queue is empty.");

  struct node *old_first = first;
  int val = old_first->value;

  first = first->next;
  if (queue_is_empty())
    last = first;

  free(old_first);
  return val;
}

int queue_peek_first(void)
{
  if(queue_is_empty())
    terminate("Error in queue_peek_first: queue is empty.");
  return first->value;
}

int queue_peek_last(void)
{
  if(queue_is_empty())
    terminate("Error in queue_peek_last: queue is empty.");
  return last->value;
}
