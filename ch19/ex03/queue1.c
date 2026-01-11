#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

int contents[MAX_SIZE];
int first = 0, next = 0, count = 0;

/* attributes are GCC extension
 * in this case, it tells the compiler function terminate never returns
 * so it stops warning me about execution paths with no return value wherever I call it
 * (well, except in functions that return void, those don't care anyway)
 */
__attribute__ ((noreturn))
static void terminate(char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

bool queue_is_empty(void)
{
  return (count == 0);
}

bool queue_is_full(void)
{
  return (count == MAX_SIZE);
}

void queue_clear(void) {
  first = 0;
  next = 0;
  count = 0;
}

void queue_push(int i)
{
  if (!queue_is_full()) {
    contents[next] = i;
    next = (next + 1) % MAX_SIZE;
    count++;
  } else {
    terminate("Error in queue_push: queue is full.");
  }
}

int queue_pop(void)
{
  if (!queue_is_empty()) {
    int i = contents[first];
    first = (first + 1) % MAX_SIZE;
    count--;
    return i;
  } else {
    terminate("Error in queue_pop: queue is empty");
  }
}

/*
 * There is a potential issue with peek functions - what do they return if queue is empty?
 * Options:
 * - Terminate with error message
 * - Return some "magic" error indicating int value (eh)
 * - Return a pointer to int or NULL... but that pointer to int would in fact point to some
 *   element in contents, and so, writable lvalue, which is not great. Pop does not have this
 *   problem, as it removes the element from stack or queue, so the client is welcome to whatever
 *   they want with it.
 * - Can I declare function return type as const? Unclear... Seems like I can (if it makes sense -
 *   e.g. it's a pointer; returning a primitive type as "const" makes no sense and compiler ignores
 *   it and emits a warning, as a primitive type value does not have a location in memory that is
 *   "writable" in any meaningful sense anyway. Also it's not some kind of guarantee that the
 *   client won't mess with it, but it should at least get a warning from the compiler when the
 *   return value is assigned to a non-const writable pointer, and then if the client ignores it,
 *   it's on them.
 *
 * Stack module terminates in case of invalid operation, so I'll just do that for now.
 * For ADTs, when I have to implement peek function for them, maybe I'll try this idea
 * of using "pointer to const" return type
 */

int queue_peek_first(void)
{
  if (!queue_is_empty())
    return contents[first];
  else
    terminate("Error in queue_peek_first: queue is empty.");
}

int queue_peek_last(void)
{
  if (!queue_is_empty())
    return contents[((next - 1) + MAX_SIZE) % MAX_SIZE];
  else
    terminate("Error in queue_peek_last: queue is empty.");
}
