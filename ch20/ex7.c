#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n)
{
  return i << n | i >> (sizeof(i) * 8 - n);
}

unsigned int rotate_right(unsigned int i, int n)
{
  return i >> n | i << (sizeof(i) * 8 - n);
}

int main(void)
{
  unsigned int i;
  int n;
  printf("Enter hexadecimal number: ");
  scanf("%x", &i);
  printf("Enter number of bits to rotate: ");
  scanf("%d", &n);
  printf("Rotated left: %x\n", rotate_left(i, n));
  printf("Rotated right: %x\n", rotate_right(i, n));
  return 0;
}
