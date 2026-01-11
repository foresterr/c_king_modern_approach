#include <stdio.h>

unsigned short swap_bytes(unsigned short i)
{
  /* This was my default solution for me, so I won't artificially provide one
   * with more than one statement
   */
  return i << 8 | i >> 8;
}

int main(void)
{
  unsigned short i;
  printf("Enter a hex number (up to four digits): ");
  scanf("%hx", &i);
  printf("Number with bytes swapped: %hx\n", swap_bytes(i));
  return 0;
}
