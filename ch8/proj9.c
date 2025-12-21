#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N_SIZE 11

int main(void)
{
  char step, field[N_SIZE][N_SIZE];
  bool blocked[4];
  int direction, x = 5, y = 5, blocked_count;

  // initialize pseudo-random generator
  srand((unsigned) time(NULL));

  // initialize field array
  for (int i = 0; i < N_SIZE; i++) {
    for (int j = 0; j < N_SIZE; j++) {
      field[i][j] = '.';
    }
  }

  for (step = 'A'; step <= 'Z'; step++) {
    // put current step on field; we know we're starting from a known good position
    field[y][x] = step;
    // initialize blocked directions array
    blocked_count = 0;
    for (int i = 0; i < 4; i++)
      blocked[i] = false;
    // pick new direction randomly until it's not blocked or all are found blocked
    do {
      direction = rand() % 4;
      if (blocked[direction])
        continue;
      switch (direction) {
        case 0:
          if (x + 1 >= N_SIZE || field[y][x+1] != '.') {
            blocked[direction] = true;
            blocked_count++;
          } else {
            x++;
          }
          break;
        case 1:
          if (y + 1 >= N_SIZE || field[y+1][x] != '.') {
            blocked[direction] = true;
            blocked_count++;
          } else {
            y++;
          }
          break;
        case 2:
          if (x - 1 < 0 || field[y][x-1] != '.') {
            blocked[direction] = true;
            blocked_count++;
          } else {
            x--;
          }
          break;
        case 3:
          if (y - 1 < 0 || field[y-1][x] != '.') {
            blocked[direction] = true;
            blocked_count++;
          } else {
            y--;
          }
          break;
      } 
    } while (blocked[direction] && blocked_count < 4);
    // if all directions were blocked, we're done, exit for loop
    if (blocked_count >= 4)
      break;
  }

  //print out the array
  for (int i = 0; i < N_SIZE; i++) {
    for (int j = 0; j < N_SIZE; j++) {
      printf("%c ", field[i][j]);
    }
    printf("\n");
  }

  return 0;
}
