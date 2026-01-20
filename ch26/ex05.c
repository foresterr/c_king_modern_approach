#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

char *vstrcat(const char *first, ...)
{
  va_list va;
  char *str_arg, *str_out;
  int size = strlen(first);

  va_start(va, first);
  while ((str_arg = va_arg(va, char *)) != NULL) {
    size += strlen(str_arg);
  }
  va_end(va);
  size++; /* for the null terminator */

  str_out = malloc(size);
  if (str_out == NULL) {
    return NULL;
  }

  strcpy(str_out, first);
  va_start(va, first);
  while ((str_arg = va_arg(va, char *)) != NULL) {
    strcat(str_out, str_arg);
  }
  va_end(va);
  return str_out;
}

int main(void)
{
  printf("%s\n", vstrcat("A ", "series ", "of ", "unfortunate ", "accidents", (char *)NULL));
}
