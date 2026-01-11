#pragma once
#include <stdbool.h>
#define QUEUE_SIZE 100

typedef struct {
  int contents[QUEUE_SIZE];
  int first;
  int last;
  int count;
} Queue;

bool is_empty(Queue *q);
void queue_insert_last(Queue *q, int i);
int queue_peek_first(Queue *q);
int queue_peek_last(Queue *q);
int queue_remove_first(Queue *q);
