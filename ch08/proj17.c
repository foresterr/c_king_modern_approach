#include <stdio.h>

int main(void)
{
  int size, x, y;

  printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 and 99.\nEnter size of magic square: ");
  scanf("%d", &size);

  int magic_square[size][size];
  for(int y = 0; y < size; y++) {
    for(int x = 0; x < size; x++) {
      magic_square[y][x] = 0;
    }
  }
  x = size / 2;
  y = 0;
  for (int i = 1; i <= size * size; i++) {
    magic_square[y][x] = i;
    x = (x + 1) % size;
    y = (y - 1 + size) % size;
    if (magic_square[y][x] != 0) {
      x = (x - 1 + size) % size;
      y = (y + 2) % size;
    }
  }

  for(int y = 0; y < size; y++) {
    for(int x = 0; x < size; x++) {
      printf("%5d", magic_square[y][x]);
    }
    putchar('\n');
  }
  return 0;
}
