#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000

int compare_int(const void *i1, const void *i2);

int main(int argc, char *argv[])
{
  FILE *fp_in;
  int numbers[LIMIT], n_numbers = 0, median;

  if (argc != 2) {
    printf("usage: stats file_in\n");
    exit(EXIT_FAILURE);
  }
  if ((fp_in = fopen(argv[1], "r")) == NULL) {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while (n_numbers < LIMIT && fscanf(fp_in, " %d", &numbers[n_numbers]) == 1) {
    n_numbers++;
  }
  fclose(fp_in);
  if (n_numbers == 0) {
    printf("%s does not have expected content\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  qsort(numbers, n_numbers, sizeof(numbers[0]), compare_int);
  if (n_numbers % 2 == 1) {
    median = numbers[n_numbers / 2];
  }
  else {
    median = (numbers[n_numbers / 2] + numbers[n_numbers / 2 - 1]) / 2;
  }
  printf("%d integers were read from %s\nLargest: %d Smallest: %d Median: %d\n",
      n_numbers, argv[1], numbers[n_numbers-1], numbers[0], median);

  exit(EXIT_SUCCESS);
}

int compare_int(const void *i1, const void *i2) {
  const int *pi1 = i1, *pi2 = i2;
  return *pi1 - *pi2;
}
