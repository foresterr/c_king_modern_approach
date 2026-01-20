#include <stdio.h>
#include <stdarg.h>

void display(int n, ...)
{
  va_list va;
  char *str_arg, ch;
  va_start(va, n);
  while (n-- > 0) {
    str_arg = va_arg(va, char *);
    while ((ch = *str_arg++) != '\0') {
      putchar(ch);
    }
    if (n != 0) {
      putchar(' ');
    }
  }
  va_end(va);
}

int main(void)
{
  display(4, "Special", "Agent", "Dale", "Cooper");
}
