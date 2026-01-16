#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(int argc, char *argv[])
{
  FILE *fp_in, *fp_out;
  int ch0, ch1, runlen;

  if (argc != 2) {
    printf("usage: compress_file filename\n");
    exit(EXIT_FAILURE);
  }
  if ((fp_in = fopen(argv[1], "rb")) == NULL) {
    printf("%s cannot be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  char out_filename[strlen(argv[1]) + 5];
  sprintf(out_filename, "%s.rle", argv[1]);
  /* note: opening in "write" mode overwrites entire file, not just what bytes are written over
   * I guess to do that, it would be necessary to open in append mode, then seek to start of file
   */
  if ((fp_out = fopen(out_filename, "wb")) == NULL) {
    printf("%s cannot be opened\n", out_filename);
    exit(EXIT_FAILURE);
  }

  while ((ch0 = getc(fp_in)) != EOF) {
    runlen = 1;
    while ((ch1 = getc(fp_in)) == ch0 && runlen < UCHAR_MAX) {
      runlen++;
    }
    ungetc(ch1, fp_in);
    putc(runlen, fp_out);
    putc(ch0, fp_out);
  }
  fclose(fp_out);
  fclose(fp_in);

  exit(EXIT_SUCCESS);
}
