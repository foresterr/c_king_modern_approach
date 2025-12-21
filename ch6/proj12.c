#include <stdio.h>

int main(void)
{
  int i = 1, fa = 1;
  float eta, term = 1.0f, e = 1.0f;

  printf("Enter eta: ");
  scanf("%f", &eta);

  while(term >= eta) {
    fa *= i++;
    term = 1.0f / fa;
    e += term;
  };

  printf("Approximation of e to eta %.14g: %.14g\n", eta, e);
  return 0;
}
