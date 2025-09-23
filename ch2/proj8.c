#include <stdio.h>

int main(void)
{
  float principal, rate, monthly;

  printf("Enter amount of loan: ");
  scanf("%f", &principal);
  printf("Enter interest rate: ");
  scanf("%f", &rate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthly);
  printf("\n");

  principal = principal * (1 + rate / 1200) - monthly;
  printf("Balance remaining after first payment: %.2f\n", principal);
  principal = principal * (1 + rate / 1200) - monthly;
  printf("Balance remaining after second payment: %.2f\n", principal);
  principal = principal * (1 + rate / 1200) - monthly;
  printf("Balance remaining after third payment: %.2f\n", principal);

  return 0;
}
