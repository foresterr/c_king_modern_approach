#include <stddef.h>
#include <stdio.h>

struct s {
  char a;
  int b[2];
  float c;
};

int main(void)
{
  struct s sv;
  printf("Offset of s.a: %zu, size of a: %zu\n", offsetof(struct s, a), sizeof(sv.a));
  printf("Offset of s.b: %zu, size of b: %zu\n", offsetof(struct s, b), sizeof(sv.b));
  printf("Offset of s.c: %zu, size of c: %zu\n", offsetof(struct s, c), sizeof(sv.c));
  printf("Size of s: %zu\n", sizeof(struct s));
  return 0;
}

/* Output:
 * Offset of s.a: 0, size of a: 1
 * Offset of s.b: 4, size of b: 8
 * Offset of s.c: 12, size of c: 4
 * Size of s: 16
 * It looks like there is a 3-byte hole after a (char takes up only 1 byte), and no other holes
 * (array of 2 ints = 2*4 bytes = 8, so next offset is 12, and a float of 4 bytes comes up to 16)
 */
