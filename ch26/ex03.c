#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int simple_printf(char* format, ...)
{
  va_list va;
  char ch, digits[sizeof(int) / 2 * 5], *str_arg;
  int int_arg, i, count = 0;
  va_start(va, format);
  while ((ch = *format++) != '\0') {
    if (ch == '%') {
      switch (*format) {
        case 'd':
          int_arg = va_arg(va, int);
          if (int_arg < 0) {
            int_arg *= -1;
            putchar('-');
            count++;
          }
          i = 0;
          do {
            digits[i++] = '0' + int_arg % 10;
          } while ((int_arg /= 10) > 0);
          while (--i >= 0) {
            putchar(digits[i]);
            count++;
          }
          format++;
          break;
        case 's':
          str_arg = va_arg(va, char *);
          while ((ch = *str_arg++) != '\0') {
            putchar(ch);
            count++;
          }
          format++;
          break;
      }
    }
    else {
      putchar(ch);
      count++;
    }
  }
  va_end(va);
  return count;
}

int main (void)
{
  int i;
  i = simple_printf("int 1: %d, int 1,5: %d, nothing: %x, a string: '%s', int 2: %d, int 3: %d",
                    12045, 1300, "i am a string", -456, 789666);
  putchar('\n');
  simple_printf("previous call of simple_printf printed %d characters", i);
  putchar('\n');
}
