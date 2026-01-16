#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int ch, count = 1;
  if (argc != 2) {
    printf("usage: countlines filename\n");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("%s cannot be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') {
      count++;
    }
  }
  printf("%d lines in %s\n", count, argv[1]);
  return 0;
}
