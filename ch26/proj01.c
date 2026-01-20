#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  for (int i = 1; i <= 1000; i++) {
    printf("%d", rand() % 2);
    if (i % 50 == 0)
      putchar('\n');
  }
  /* I don't see much of a pattern of any kind in the output; maybe the rand() function got better
   * over time. But I assume that if there was one and low bits weren't particularly random, the
   * answer to get small random numbers could be to bit-shift the return value from rand a couple
   * bits to the right, and then use % operator to determine range, as usual.
   *
   * Official answer (divide based on RAND_MAX) is better because it's universal; with my idea it
   * would be necessary to think by how many bits to shift in different cases
   */
}
