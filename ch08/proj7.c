#include <stdio.h>

int main(void)
{
  int n[5][5];
  int sum;

  for (int i = 0; i < 5; i++) {
    printf("Enter row %d: ", i + 1);
    for (int j = 0; j < 5; j++) {
      scanf("%d", &n[i][j]);
    }
  }
  printf("\nRow totals: ");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (j == 0)
        sum = n[i][j];
      else
        sum += n[i][j];
    }
    printf("%d ", sum);
  };

  printf("\nColumn totals: ");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (j == 0)
        sum = n[j][i];
      else
        sum += n[j][i];
    }
    printf("%d ", sum);
  }
  printf("\n");

  return 0;
}
