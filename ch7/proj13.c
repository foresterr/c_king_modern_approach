#include <stdio.h>

int main(void)
{
  char c;
  int ch_count = 0, w_count = 1;
  float avg;

  printf("Enter a sentence: ");
  while((c = getchar()) != '\n') {
    if (c == ' ') ++w_count;
    else ++ch_count;
  }
  avg = (float)ch_count / w_count;
  printf("Average word length: %.1f\n", avg);
  return 0;
}
