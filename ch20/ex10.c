#include <stdio.h>

#define BIT_W(t) (sizeof(t) * 8)
#define KEEP_BIT(n,s) ((n) & (1 << (s)))

unsigned int reverse_bits(unsigned int n)
{
  unsigned int reversed = 0;
  for (int i = 0; i < (int)BIT_W(n) / 2; i++) {
    reversed |=
      KEEP_BIT(n, i) << (BIT_W(n)-1 - 2*i)
      | KEEP_BIT(n, BIT_W(n)-1 - i) >> (BIT_W(n)-1 - 2*i);
  }
  return reversed;
}

void print_bits(unsigned int n)
{
  for (int i = BIT_W(n)-1; i >= 0; i--) {
    if (n >> i & 1)
      putchar('1');
    else
      putchar('0');
    if (i % 8 == 0)
      putchar(' ');
  }
  putchar('\n');
}

int main(void)
{
  unsigned int n;
  printf("Enter a hex number: ");
  scanf("%x", &n);
  print_bits(n);
  printf("With reversed bits: %x\n", reverse_bits(n));
  print_bits(reverse_bits(n));
  return 0;
}
