#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int int_compare(const void *n1, const void *n2);

int main(int argc, char **argv)
{
  long size;
  clock_t ct;
  if (argc != 2) {
    printf("usage: proj03 n\n");
    exit(EXIT_FAILURE);
  }
  size = strtol(argv[1], NULL, 10);
  long arr[size];
  for (long j = 0; j < size; j++) {
    arr[j] = size - j;
  }
  ct = clock();
  qsort(arr, size, sizeof(arr[0]), int_compare);
  ct = clock() - ct;

  printf("Sorting the array of %ld integers took %g sec.\n", size, (double) ct / CLOCKS_PER_SEC);
}

int int_compare(const void *n1, const void *n2)
{
  return *(int *)n1 - *(int *)n2;
}

/* Sorting the array of 1000 integers took 5.3e-05 sec.
 * Sorting the array of 10000 integers took 0.00025 sec.
 * Sorting the array of 100000 integers took 0.003102 sec.
 * Sorting the array of 1000000 integers took 0.028799 sec.
 */
