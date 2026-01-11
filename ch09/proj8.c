#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
  int wins = 0, losses = 0;
  char choice;
  srand((unsigned) time(NULL));

  do {
    if (play_game())
      wins++;
    else
      losses++;

    printf("Play again? ");
    choice = getchar();
    while (getchar() != '\n');
    putchar('\n');
  } while (choice == 'y' || choice == 'Y');

  printf("Wins: %2d   Losses: %2d\n", wins, losses);
  return 0;
}

int roll_dice(void)
{
  return rand() % 6 + rand() % 6 + 2;
}

bool play_game(void)
{
  int roll, point;

  roll = roll_dice();
  printf("You rolled: %d\n", roll);

  if (roll == 7 || roll == 11) {
    printf("You win!\n\n");
    return true;
  } else {
    point = roll;
    printf("Your point is %d\n", point);
  }

  for (;;) {
    roll = roll_dice();
    printf("You rolled: %d\n", roll);
    if (roll == point) {
      printf("You win!\n\n");
      return true;
    } else if (roll == 7) {
      printf("You lose!\n\n");
      return false;
    }
  }
}
