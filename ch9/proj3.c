#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N_SIZE 10

void generate_random_walk(char walk[N_SIZE][N_SIZE]);
void print_array(char walk[N_SIZE][N_SIZE]);

int main(void)
{
  char field[N_SIZE][N_SIZE];

  generate_random_walk(field);
  print_array(field);

  return 0;
}

void print_array(char walk[N_SIZE][N_SIZE])
{
  for (int i = 0; i < N_SIZE; i++) {
    for (int j = 0; j < N_SIZE; j++) {
      printf("%c ", walk[i][j]);
    }
    printf("\n");
  }
  return;
}

void generate_random_walk(char walk[N_SIZE][N_SIZE])
{
  char step;
  bool blocked[4];
  int direction, x = 5, y = 5, blocked_count;

  // initialize pseudo-random generator
  srand((unsigned) time(NULL));

  // initialize walk array
  for (int i = 0; i < N_SIZE; i++) {
    for (int j = 0; j < N_SIZE; j++) {
      walk[i][j] = '.';
    }
  }

  for (step = 'A'; step <= 'Z'; step++) {
    // put current step on field; we know we're starting from a known good position
    walk[y][x] = step;
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
          if (x + 1 >= N_SIZE || walk[y][x+1] != '.') {
            blocked[direction] = true;
            blocked_count++;
          } else {
            x++;
          }
          break;
        case 1:
          if (y + 1 >= N_SIZE || walk[y+1][x] != '.') {
            blocked[direction] = true;
            blocked_count++;
          } else {
            y++;
          }
          break;
        case 2:
          if (x - 1 < 0 || walk[y][x-1] != '.') {
            blocked[direction] = true;
            blocked_count++;
          } else {
            x--;
          }
          break;
        case 3:
          if (y - 1 < 0 || walk[y-1][x] != '.') {
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
  return;
}
