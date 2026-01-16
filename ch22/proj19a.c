#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp_in, *fp_out;
  int ch;

  if (argc != 3) {
    printf("usage: txtwintounix filename\n");
    exit(EXIT_FAILURE);
  }
  if ((fp_in = fopen(argv[1], "rb")) == NULL) {
    printf("%s cannot be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((fp_out = fopen(argv[2], "wb")) == NULL) {
    printf("%s cannot be opened\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(fp_in)) != EOF) {
    if (ch == '\r') {
      if ((ch = getc(fp_in)) == '\n') {
        putc(ch, fp_out);
      }
      else {
        ungetc(ch, fp_in);
        putc('\r', fp_out);
      }
    }
    else {
      putc(ch, fp_out);
    }
  }

  fclose(fp_out);
  fclose(fp_in);
  exit(EXIT_SUCCESS);
}
