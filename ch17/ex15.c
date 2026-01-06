#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void)
{
  printf("Answer: %d\n", f1(f2));
  return 0;
}

int f1(int (*f)(int))
{
  int n = 0;
  while ((*f)(n)) n++;
  return n;
}

int f2(int i)
{
  return i * i + i - 12;
}

/* f2 is a simple function. It will return 0 for i == 3.
 * Note that passing a pointer to function as argument is more or less the same as passing the
 * function itself (NOT function output) as argument, so I will refer to it in this way.
 * f1 will keep calling whatever function it gets as argument with consecutive int arguments
 * starting from 0 as long as this argument function returns something other than 0. Then it will
 * return argument for which f2 returned 0.
 * So, all in all, it should print "Answer: 3"
 * Checks out.
 */
