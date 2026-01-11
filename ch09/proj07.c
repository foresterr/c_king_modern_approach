#include <stdio.h>

double power(double x, int exp);

int main(void)
{
  double x;
  int exp;
  printf("Enter a number and power to raise the number to: ");
  scanf("%lf %d", &x, &exp);
  printf("%g ^ %d = %g\n", x, exp, power(x, exp));

}

double power(double x, int exp)
{
  double tmp;
  if (exp == 0)
    return 1;
  if (exp % 2 == 0) {
    tmp = power(x, exp / 2);
    return tmp * tmp; 
  } else {
    return x * power(x, exp - 1);
  }
}
