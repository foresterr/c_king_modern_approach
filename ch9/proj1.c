#include <stdio.h>

#define MAX_ARR_SIZE 100

void selsort(int a[], int n);

int main(void)
{
  int a[MAX_ARR_SIZE], n = 0; //seems I must specify some max array size here
  printf("Enter series of integers (space separated): ");
  do {
    scanf(" %d", &a[n]);
    n++;
  } while (getchar() != '\n');

  selsort(a, n);

  printf("Sorted: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  putchar('\n');
}

void selsort(int a[], int n) {
  int swap;
  if (n <= 1) //array with 1 element is already sorted
    return;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] > a[i]) {
      swap = a[i - 1];
      a[i - 1] = a[i];
      a[i] = swap;
    }
  }
  selsort(a, n - 1);
}
