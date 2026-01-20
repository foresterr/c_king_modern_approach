#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

char *max_pair(int num_pairs, ...)
{
  va_list va;
  int int_arg, max = INT_MIN;
  char *str_arg, *str_out = NULL;

  va_start(va, num_pairs);
  for (int i = 1; i <= num_pairs; i++) {
    int_arg = va_arg(va, int);
    str_arg = va_arg(va, char *);
    if (int_arg > max) {
      max = int_arg;
      str_out = str_arg;
    }
  }
  va_end(va);
  return str_out;
}

int main(void)
{
  printf("%s\n", max_pair(5, 180, "Seinfeld", 180, "I Love Lucy",
                             39, "The Honeymooners", 210, "All in the Family",
                             86, "The Sopranos"));
}
