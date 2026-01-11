#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void)
{
  int size;

  printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 and 99.\nEnter size of magic square: ");
  scanf("%d", &size);

  char magic_square[size][size];

  create_magic_square(size, magic_square);
  print_magic_square(size, magic_square);

  return 0;
}

void print_magic_square(int n, char magic_square[n][n])
{
  for(int y = 0; y < n; y++) {
    for(int x = 0; x < n; x++) {
      printf("%5d", magic_square[y][x]);
    }
    putchar('\n');
  }
}

void create_magic_square(int n, char magic_square[n][n])
{
  int x, y;

  //initialize array
  for(y = 0; y < n; y++) {
    for(x = 0; x < n; x++) {
      magic_square[y][x] = 0;
    }
  }
  //generate the magic square
  x = n / 2;
  y = 0;
  for (int i = 1; i <= n * n; i++) {
    magic_square[y][x] = i;
    x = (x + 1) % n;
    y = (y - 1 + n) % n;
    if (magic_square[y][x] != 0) {
      x = (x - 1 + n) % n;
      y = (y + 2) % n;
    }
  }
}
