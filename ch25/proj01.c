#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void)
{
  /* Note: they are not the same, because default locale is C.UTF-8 */
  if (strcmp(setlocale(LC_ALL, ""), setlocale(LC_ALL, "C")) == 0) {
    printf("Default locale and C locale are the same\n");
  }
  else {
    printf("Default locale and C locale are not the same\n");
    setlocale(LC_ALL, "");
    printf("Default locale:\n%s\n", setlocale(LC_ALL, NULL));
    setlocale(LC_ALL, "C");
    printf("C locale:\n%s\n", setlocale(LC_ALL, NULL));
  }
}
