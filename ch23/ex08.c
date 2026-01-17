#include <string.h>

int numchar(const char *s, char ch)
{
  int count = 0;
  char *p;
  while ((p = strchr(s, ch)) != NULL) {
    count++;
    p++;
  }
  return count;
}
