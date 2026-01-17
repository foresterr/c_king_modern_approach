#include <stdio.h>
/* note, gcc requires "-lm" flag to compile properly when using math.h
 * this is because object code for most standard library functions sits
 * in a different file than math functions (file is called libm, -l is a
 * linker option that skips the "lib" part of the name)
 * curiously enough, this does not apply to all functions in math.h - I
 * used fma before and it had no issues. maybe the reason is that fma is
 * defined as a macro or inline function in that header?
 */
#include <math.h>

int main(void)
{
  double principal, rate, years;
  printf("Enter principal amount: ");
  if (scanf("%lf", &principal) != 1) {
    printf("Bad input\n");
    return 0;
  }
  printf("Enter yearly interest rate (in %%): ");
  if (scanf("%lf", &rate) != 1) {
    printf("Bad input\n");
    return 0;
  }
  rate /= 100;
  printf("Enter number of years: ");
  if (scanf("%lf", &years) != 1) {
    printf("Bad input\n");
    return 0;
  }
  printf("$%g with continuously compounded interest at %g%% rate after %g years: %g\n",
         principal, rate * 100, years, principal * exp(rate * years));
  return 0;
}
