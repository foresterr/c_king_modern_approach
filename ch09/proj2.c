#include <stdio.h>

float tax(float income);

int main(void)
{
  float income;

  printf("Enter amount of taxable income: ");
  scanf("%f", &income);
  printf("Tax due: %.2f\n", tax(income));

  return 0;
}

float tax(float income)
{
  float tax;
  if (income < 750.00f) tax = income * 0.01f;
  else if (income < 2250.00f) tax = 7.50f + (income - 750.00f) * 0.02f;
  else if (income < 3750.00f) tax = 37.50f + (income - 2250.00f) * 0.03f;
  else if (income < 5250.00f) tax = 82.50f + (income - 3750.00f) * 0.04f;
  else if (income < 7000.00f) tax = 142.50f + (income - 5250.00f) * 0.05f;
  else tax = 230.00f + (income - 7000.00f) * 0.06f;
  return tax;
}
