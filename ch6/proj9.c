
#include <stdio.h>

int main(void)
{
  float principal, rate, monthly;
  int payments, i;

  printf("Enter amount of loan: ");
  scanf("%f", &principal);
  printf("Enter interest rate: ");
  scanf("%f", &rate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthly);
  printf("Enter number of payments: ");
  scanf("%d", &payments);
  printf("\n");

  for (i = 1; i <= payments; i++) {
    principal = principal * (1 + rate / 1200) - monthly;
    printf("Balance remaining after payment %d: %.2f\n", i, principal);
  }
  return 0;
}
