#include <stdarg.h>

int max_int(int n, ...)
{
  va_list ap;
  int current, largest;
  largest = n;
  va_start(ap, n);
  while (largest != 0) {
    current = va_arg(ap, int);
    if (current > largest)
      largest = current;
  }
  va_end(ap);
  return largest;
}
