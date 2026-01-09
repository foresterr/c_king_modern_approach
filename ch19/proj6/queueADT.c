#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

struct queue_type {
  Item *contents;
  int first;
  int last;
  int len;
  int size;
};

__attribute__ ((noreturn))
static void terminate(char *message)
{
    printf("%s\n", message);
      exit(EXIT_FAILURE);
}

Queue queue_create(int size)
{
  struct queue_type *q = malloc(sizeof(struct queue_type));
  Item *contents = malloc(sizeof(Item) * size);
  if (q == NULL || contents == NULL)
    terminate("Error in queue_create: failure to allocate memory for queue");
  q->contents = contents;
  q->first = 0;
  q->last = -1;
  q->len = 0;
  q->size = size;
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
  return (q->len == q->size);
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
    q->contents[q->last = (q->last + 1) % q->size] = i;
    ++q->len;
  } else
    terminate("Error in queue_push: queue is full");
}

Item queue_pop(Queue q)
{
  if (!queue_is_empty(q)) {
    Item i = q->contents[q->first++];
    q->first %= q->size;
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
