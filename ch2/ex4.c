#include <stdio.h>

int main(void)
{
  int int1, int2, int3;
  float fl1, fl2, fl3;

  printf("Undeclared ints: %d %d %d\n", int1, int2, int3);
  printf("Undeclared floats: %f %f %f\n", fl1, fl2, fl3);

  return 0;
}
