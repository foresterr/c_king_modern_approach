#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  FILE *fp_in, *fp_out;
  char filename[FILENAME_MAX+1];
  int shift, ch;

  printf("Enter name of file to be encrypted: ");
  scanf("%s", filename);
  if ((fp_in = fopen(filename, "r")) == NULL) {
    printf("%s can't be opened\n", filename);
    exit(EXIT_FAILURE);
  }
  strncat(filename, ".enc", sizeof(filename) - strlen(filename) - 1);
  if ((fp_out = fopen(filename, "w")) == NULL) {
    printf("%s can't be opened\n", filename);
    exit(EXIT_FAILURE);
  }
  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);


  while ((ch = getc(fp_in)) != EOF) {
    if (isupper(ch)) {
      putc(((ch - 'A') + shift) % 26 + 'A', fp_out);
    }
    else if (islower(ch)) {
      putc(((ch - 'a') + shift) % 26 + 'a', fp_out);
    }
    else {
      putc(ch, fp_out);
    }
  }


  fclose(fp_in);
  fclose(fp_out);
  exit(EXIT_SUCCESS);
}
