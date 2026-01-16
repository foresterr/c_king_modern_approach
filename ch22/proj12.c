#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int item, m, d, y;
  float price;

  if (argc != 2) {
    printf("usage: proj12 filename\n");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
  while (fscanf(fp, "%d,%f,%d/%d/%d", &item, &price, &m, &d, &y) == 5) {
    printf("%-d\t\t$ %7.2f\t%2.2d/%2.2d/%4.4d\n", item, price, m, d, y);
    while (getc(fp) != '\n')
      ;
  }
  exit(EXIT_SUCCESS);
}
