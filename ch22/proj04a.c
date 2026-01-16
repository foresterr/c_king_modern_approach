#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int count = 0;
  if (argc != 2) {
    printf("usage: countchars filename\n");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("%s cannot be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  while (fgetc(fp) != EOF) {
    count++;
  }
  printf("%d characters in %s\n", count, argv[1]);
  return 0;
}
