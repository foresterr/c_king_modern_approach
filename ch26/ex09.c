#include <stdlib.h>
#include <time.h>

double rand_double(void)
{
  srand((unsigned) time(NULL));
  return (double) rand() / (RAND_MAX + 1.0);
  /* official answer sez to use "RAND_MAX+1" but what if RAND_MAX is the same as INT_MAX?
   * integer overflow, that's what, because the part in parentheses will be evaluated first, before
   * any casting to double happens (sure, getting RAND_MAX from rand() is pretty unlikely, but it's
   * not impossible)
   * using 1.0 forces the conversion from the bottom up. It's not even necessary to
   * keep the explicit cast to double, but it makes the intent more clear
   */
}
