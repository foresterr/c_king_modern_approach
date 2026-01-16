#include <stdio.h>

/* Note: library fgets returns NULL if n <= 0 */
char *my_fgets(char * restrict s, int n, FILE * restrict stream)
{
  int ch, len = 0;

  if (n < 1) {
    return NULL;
  }

  while ((ch = getc(stream)) != EOF && len < n - 1) {
    s[len++] = ch;
    if (ch == '\n') {
      break;
    }
  }

  if (ch == EOF && (len == 0 || ferror(stream))) {
    return NULL;
  }
  s[len] = '\0';
  return s;
}

int my_fputs (const char * restrict s, FILE * restrict stream)
{
  int ch;
  while (*s != '\0') {
    ch = putc(*s++, stream);
    if (ch == EOF) {
      break;
    }
  }
  return ch;
}
