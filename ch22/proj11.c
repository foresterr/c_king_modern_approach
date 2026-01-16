#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int day, mon, year;
  const char *months[] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
  };
  if (argc != 2 || sscanf(argv[1], "%d%*[-/]%d%*[-/]%d", &mon, &day, &year) != 3) {
    printf("usage: printdate d/m/y or printdate d-m-y\n");
    exit(EXIT_FAILURE);
  }
  printf("%s %d, %d\n", months[mon], day, year);
  exit(EXIT_SUCCESS);
}
