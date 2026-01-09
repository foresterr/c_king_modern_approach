#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  Item data;
  struct node *next;
};

struct queue_type {
  struct node *first;
  struct node *last;
  int len;
};

__attribute__ ((noreturn))
static void terminate(char *message)
{
    printf("%s\n", message);
      exit(EXIT_FAILURE);
}

Queue queue_create(void)
{
  struct queue_type *q = malloc(sizeof(struct queue_type));
  if (q == NULL)
    terminate("Error in queue_create: failure to allocate memory for queue");
  q->len = 0;
  q->first = NULL;
  q->last = NULL;
  return q;
}

void queue_destroy(Queue q)
{
  queue_clear(q);
  free(q);
}

bool queue_is_empty(Queue q)
{
  return (q->len == 0);
}

bool queue_is_full(Queue q)
{
  return false;
}

void queue_clear(Queue q)
{
  while (!(queue_is_empty(q))) {
    queue_pop(q);
  }
}

void queue_push(Queue q, Item i)
{
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL)
    terminate("Error in queue_push: failure to allocate memory for new queue item");
  new_node->data = i;
  new_node->next = NULL;

  if(queue_is_empty(q)) {
    q->first = q->last = new_node;
  } else {
    q->last = q->last->next = new_node;
  }

  ++q->len;
}

Item queue_pop(Queue q)
{
  if (!queue_is_empty(q)) {
    struct node *old_first = q->first;
    Item i = old_first->data;
    q->first = q->first->next;
    free(old_first);
    --q->len;
    return i;
  } else
    terminate("Error in queue_pop: queue is empty");
}

Item queue_peek_first(Queue q)
{
  if (!queue_is_empty(q))
    return q->first->data;
  else
    terminate("Error in queue_peek_first: queue is empty");
}

Item queue_peek_last(Queue q)
{
  if (!queue_is_empty(q))
    return q->last->data;
  else
    terminate("Error in queue_peek_first: queue is empty");
}

int queue_length(Queue q)
{
  return q->len;
}
