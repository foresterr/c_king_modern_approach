#include <stdio.h>
#include "queueADT.h"

int main(void)
{
  Queue q1, q2;

  q1 = queue_create();
  q2 = queue_create();

  //TODO: push 100 ints to q1, print count after (need new function to get count)
  for (int i = 1; i <= 100; i++) {
    queue_push(q1, i);
  }
  printf("q1 size: %d\n", queue_length(q1));
  //TODO: print if q1 is full
  if (queue_is_full(q1)) {
    printf("q1 is full\n");
  } else {
    printf("q1 is not full\n");
  }
  //TODO: pop 50 items from q1 and push each to q2, print count after
  for (int i = 0; i < 50; i++) {
    queue_push(q2, queue_pop(q1));
  }
  printf("q1 size: %d\n", queue_length(q1));
  printf("q2 size: %d\n", queue_length(q2));
  //TODO: push 25 ints to q1, print count after
  for (int i = 201; i <= 225; i++) {
    queue_push(q1, i);
  }
  printf("q1 size: %d\n", queue_length(q1));
  //TODO: peek first and last from q1
  printf("First item in q1: %d\n", queue_peek_first(q1));
  printf("Last item in q1: %d\n", queue_peek_last(q1));
  //TODO: pop all elements from q printing them as we go
  while(!queue_is_empty(q1)) {
    printf("%d ", queue_pop(q1));
  }
  putchar('\n');
  //TODO: destroy q1
  queue_destroy(q1);
  //TODO: peek first and last from q2
  printf("First item in q2: %d\n", queue_peek_first(q2));
  printf("Last item in q2: %d\n", queue_peek_last(q2));
  //TODO: push 10 ints to q2, print count
  for (int i = 101; i <= 110; i++) {
    queue_push(q2, i);
  }
  printf("q2 size: %d\n", queue_length(q2));
  //TODO: peek last from s2
  printf("Last item in q2: %d\n", queue_peek_last(q2));
  //TODO: clear s2, print count
  queue_clear(q2);
  printf("q2 size: %d\n", queue_length(q2));
  //TODO: print if q2 is empty
  if (queue_is_empty(q2)) {
    printf("q2 is empty\n");
  } else {
    printf("q2 is not not empty\n");
  }
  //TODO: destroy q2
  queue_destroy(q2);
}
