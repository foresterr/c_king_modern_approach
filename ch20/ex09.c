#include <stdio.h>

int count_ones_a(unsigned char ch)
{
  int count = 0;
  for (int i = 0; i < (int) sizeof(char) * 8; i++)
    if ((ch & 1 << i) != 0)
      count++;
  return count;
}

int count_ones_b(unsigned char ch)
{
  union {
    unsigned char ch;
    struct {
      unsigned char b0: 1;
      unsigned char b1: 1;
      unsigned char b2: 1;
      unsigned char b3: 1;
      unsigned char b4: 1;
      unsigned char b5: 1;
      unsigned char b6: 1;
      unsigned char b7: 1;
    } ch_bits;
  } u = {.ch = ch};
  return u.ch_bits.b0 + u.ch_bits.b1 + u.ch_bits.b2 + u.ch_bits.b3 +
         u.ch_bits.b4 + u.ch_bits.b5 + u.ch_bits.b6 + u.ch_bits.b7;
}

int main(void)
{
  unsigned char ch;
  printf("Enter a hex number (two digits max): ");
  scanf("%hhx", &ch);
  printf("Number of 1 bits, function a: %d\n", count_ones_a(ch));
  printf("Number of 1 bits, function b: %d\n", count_ones_b(ch));
}
