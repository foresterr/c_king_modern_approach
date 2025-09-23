#include <stdio.h>

int main(void)
{
  int amount, billno;

  printf("Enter a dollar amount: ");
  scanf("%d", &amount);
  billno = amount / 20;
  printf("$20 bills: %d\n", billno);
  amount = amount - billno * 20;
  billno = amount / 10;
  printf("$10 bills: %d\n", billno);
  amount = amount - billno * 10;
  billno = amount / 5;
  printf(" $5 bills: %d\n", billno);
  amount = amount - billno * 5;
  printf(" $1 bills: %d\n", amount);
  
  return 0;
}
