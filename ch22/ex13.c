#include <stdio.h>

int line_length(const char *filename, int n)
{
  int line_n = 1, line_len = 0, ch;
  FILE *fp;

  if ((fp = fopen(filename, "r")) != NULL) {
    while ((ch = fgetc(fp)) != EOF) {
      line_len++;
      if (ch == '\n') {
        if (line_n == n) {
          fclose(fp);
          return line_len;
        }
        else {
          line_len = 0;
          line_n++;
        }
      }
    }
    fclose(fp);
  }
  return 0;
}
