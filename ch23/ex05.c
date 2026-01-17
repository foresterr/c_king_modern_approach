#include <ctype.h>
#include <stdlib.h>

long int strtohex(const char *str) {
  const char *p = str;
  while (*p++ != '\0') {
    if (!isxdigit(*p)) {
      return -1;
    }
  }
  /* note: strto... support bases from 2 to 36, because 36 is 26 (english alphabet) + 10 (digits) */
  return strtol(str, NULL, 16);
}
