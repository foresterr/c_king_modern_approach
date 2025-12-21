#include <stdio.h>

#define MAX_DIGITS 10

char digits[3][MAX_DIGITS * 4];
char segments[10][9] = {
  { /* 0 */ ' ', '_', ' ',  '|', ' ', '|',  '|', '_', '|'},
  { /* 1 */ ' ', ' ', ' ',  ' ', ' ', '|',  ' ', ' ', '|'},
  { /* 2 */ ' ', '_', ' ',  ' ', '_', '|',  '|', '_', ' '},
  { /* 3 */ ' ', '_', ' ',  ' ', '_', '|',  ' ', '_', '|'},
  { /* 4 */ ' ', ' ', ' ',  '|', '_', '|',  ' ', ' ', '|'},
  { /* 5 */ ' ', '_', ' ',  '|', '_', ' ',  ' ', '_', '|'},
  { /* 6 */ ' ', '_', ' ',  '|', '_', ' ',  '|', '_', '|'},
  { /* 7 */ ' ', '_', ' ',  ' ', ' ', '|',  ' ', ' ', '|'},
  { /* 8 */ ' ', '_', ' ',  '|', '_', '|',  '|', '_', '|'},
  { /* 9 */ ' ', '_', ' ',  '|', '_', '|',  ' ', '_', '|'},
};

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
  char c;
  int position = 0;

  clear_digits_array();
  printf("Enter a number: ");
  while((c = getchar()) != '\n') {
    if (c >= '0' && c <= '9') {
      process_digit((int)(c - '0'), position);
      ++position;
    }
    if (position > MAX_DIGITS - 1)
      break;
  }
  print_digits_array();
  return 0;
}

void clear_digits_array(void)
{
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < MAX_DIGITS * 4; j++) {
      digits[i][j] = ' ';
    }
  }
}

void print_digits_array(void)
{
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < MAX_DIGITS * 4; j++) {
      putchar(digits[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}

void process_digit(int digit, int position)
{
  for (int i = 0; i < 9; i++) {
    digits[i / 3][i % 3 + position * 4] = segments[digit][i];
  }
}
