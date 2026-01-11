#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

struct queue_type {
  Item contents[MAX_LEN];
  int first;
  int last;
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
  q->first = 0;
  q->last = -1;
  q->len = 0;
  return q;
}

void queue_destroy(Queue q)
{
  free(q);
}

bool queue_is_empty(Queue q)
{
  return (q->len == 0);
}

bool queue_is_full(Queue q)
{
  return (q->len == MAX_LEN);
}

void queue_clear(Queue q)
{
  q->first = 0;
  q->last = -1;
  q->len = 0;
}

void queue_push(Queue q, Item i)
{
  if (!queue_is_full(q)) {
    q->contents[q->last = (q->last + 1) % MAX_LEN] = i;
    ++q->len;
  } else
    terminate("Error in queue_push: queue is full");
}

Item queue_pop(Queue q)
{
  if (!queue_is_empty(q)) {
    Item i = q->contents[q->first++];
    q->first %= MAX_LEN;
    --q->len;
    return i;
  } else
    terminate("Error in queue_pop: queue is empty");
}

Item queue_peek_first(Queue q)
{
  if (!queue_is_empty(q))
    return q->contents[q->first];
  else
    terminate("Error in queue_peek_first: queue is empty");
}

Item queue_peek_last(Queue q)
{
  if (!queue_is_empty(q))
    return q->contents[(q->last)];
  else
    terminate("Error in queue_peek_first: queue is empty");
}

int queue_length(Queue q)
{
  return q->len;
}
