#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TRY_MATH_FCN(FCN, X) (try_math_fcn((FCN), (X), "Error in call of " #FCN))

double try_math_fcn(double (*fcn)(double x), double x, char *message)
{
  double result;
  errno = 0;
  result = (*fcn)(x);
  if (errno != 0) {
    perror(message);
    exit(EXIT_FAILURE);
  }
  else {
    return result;
  }
}

int main(void) {
  printf("%g\n", TRY_MATH_FCN(sqrt, 5));
  printf("%g\n", TRY_MATH_FCN(sqrt, -1));
  puts("Program terminates normally");
}
