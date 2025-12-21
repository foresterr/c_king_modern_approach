#include <stdio.h>

int main(int argc, char *argv[])
{
  for (argc--; argc >= 1; argc--)
    printf("%s ", argv[argc]);
  putchar('\n');
  return 0;
}
