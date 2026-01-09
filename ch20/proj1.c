#include <stdio.h>

union float_u {
  float float_val;
  struct {
    unsigned int frac: 23;
    unsigned int exp:   8;
    unsigned int sign:  1;
  } fields;
};

int main(void)
{
  union float_u fl = {.fields.sign = 1, .fields.exp = 128, .fields.frac = 0};
  printf("Sign: %d\n", fl.fields.sign);
  printf("Exponent: %d\n", fl.fields.exp);
  printf("Fraction: %d\n", fl.fields.frac);
  printf("Value: %f\n", fl.float_val);
  return 0;
}
