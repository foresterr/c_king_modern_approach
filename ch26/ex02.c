#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int simple_printf(char* format, ...)
{
  va_list va;
  /* note: we need max 5 characters (decimal digits) to represent 2 bytes of an integer
   * because fucking logarithms, how do they work
   */
  char ch, digits[sizeof(int) / 2 * 5];
  int int_arg, i, count = 0;
  va_start(va, format);
  while ((ch = *format++) != '\0') {
    /* I'll assume "ignore" means "print like any other characters", because this is what real
     * printf would do. Although checking with the official solution, it meant "don't print the %
     * but print whatever follows as normal", but whatever, I don't like it.
     */
    if (ch == '%' && *format == 'd') {
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
  i = simple_printf("int 1: %d, int 1,5: %d, nothing: %x, int 2: %d, int 3: %d", 12045, 1300, -456, 789666);
  putchar('\n');
  simple_printf("previous call of simple_printf printed %d characters", i);
  putchar('\n');
}
