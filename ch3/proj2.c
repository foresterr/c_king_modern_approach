#include <stdio.h>

int main(void)
{
  int item, m, d, y;
  float price;

  printf("Enter item number: ");
  scanf("%d", &item);
  printf("Enter unit price: ");
  scanf("%f", &price);
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &m, &d, &y);

  printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
  printf("%-d\t\t$ %7.2f\t%2.2d/%2.2d/%4.4d\n", item, price, m, d, y);
}
