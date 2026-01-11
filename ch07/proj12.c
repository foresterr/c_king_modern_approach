#include <stdio.h>

int main(void)
{
  double operand, total;
  char operator;

  printf("Enter an expression: ");
  scanf("%lf", &total);
  while ((operator = getchar()) != '\n') {
    scanf("%lf", &operand);
    switch (operator) {
      case '+':
        total += operand;
        break;
      case '-':
        total -= operand;
        break;
      case '*':
        total *= operand;
        break;
      case '/':
        total /= operand;
        break;
    }
  }
  printf("Value of expression: %g\n", total);
  return 0;
}
