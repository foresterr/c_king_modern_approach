#pragma once
#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

Queue queue_create(void);
void queue_destroy(Queue q);
bool queue_is_empty(Queue q);
bool queue_is_full(Queue q);
void queue_clear(Queue q);
void queue_push(Queue q, Item i);
Item queue_peek_first(Queue q);
Item queue_peek_last(Queue q);
Item queue_pop(Queue q);
int queue_length(Queue q);
