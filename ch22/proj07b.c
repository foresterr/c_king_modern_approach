#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *fp_in, *fp_out;
  int b, runlen;

  if (argc != 2 || strcmp(argv[1] + (strlen(argv[1]) - 4), ".rle") != 0) {
    printf("usage: uncompress_file filename.rle\n");
    exit(EXIT_FAILURE);
  }
  if ((fp_in = fopen(argv[1], "rb")) == NULL) {
    printf("%s cannot be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  *(argv[1] + strlen(argv[1]) - 4) = '\0';
  if ((fp_out = fopen(argv[1], "wb")) == NULL) {
    printf("%s cannot be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  while ((runlen = getc(fp_in)) != EOF) {
    b = getc(fp_in);
    for (int i = 0; i < runlen; i++) {
      putc(b, fp_out);
    }
  }
  fclose(fp_in);
  fclose(fp_out);
  exit(EXIT_SUCCESS);
}
