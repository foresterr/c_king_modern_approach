#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int ch;

  if (argc < 2) {
    printf("usage: fcat filename1 [...filenameN]\n");
    exit(EXIT_FAILURE);
  }

  while (*++argv != NULL) {
    if ((fp = fopen(*argv, "r")) == NULL) {
      printf("%s can't be opened\n", *argv);
      exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(fp)) != EOF) {
      putchar(ch);
    }
    fclose(fp);
  }
}
