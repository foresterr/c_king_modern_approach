#include <stdio.h>
#include <math.h>
#include <complex.h>

#define PI 3.14159265358979323846

int main(void)
{
  int n;
  complex double root;
  printf("Enter n: ");
  scanf("%d", &n);
  printf("Roots of unity (n = %d):\n", n);
  for (int k = 0; k < n; k++) {
    root = cexp(2 * PI * I * k / n);
    printf("%d: % .2f%+.2fi\n", k+1, creal(root), cimag(root));
  }
  return 0;
}
