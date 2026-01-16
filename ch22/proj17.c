#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp_in, *fp_out;
  int ch, i = 0;
  char digits[10];

  if (argc != 3) {
    printf("usage: phones file_in file_out\n");
    exit(EXIT_FAILURE);
  }
  if ((fp_in = fopen(argv[1], "r")) == NULL) {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((fp_out = fopen(argv[2], "w")) == NULL) {
    printf("%s can't be opened\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(fp_in)) != EOF) {
    if (isdigit(ch)) {
      digits[i++] = ch;
    }
    if (i >= 10) {
      while ((ch = getc(fp_in)) != '\n') {}
    }
    if (ch == '\n') {
      fprintf(fp_out, "(%.3s) %.3s-%.4s\n", digits, &digits[3], &digits[6]);
      i = 0;
    }
  }

  fclose(fp_out);
  fclose(fp_in);
  exit(EXIT_SUCCESS);
}
