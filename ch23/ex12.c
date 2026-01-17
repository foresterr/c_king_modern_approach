#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *strdup(const char *s)
{
  char *p;
  if ((p = malloc(strlen(s) + 1)) == NULL) {
    return NULL;
  }
  strcpy(p, s);
  return p;
}

int stricmp(const char *s1, const char *s2)
{
  do {
    if (tolower(*s1) != tolower(*s2)) {
      return tolower(*s1) - tolower(*s2);
    }
  } while (*s1++ != '\0' && *s2++ != '\0');
  return 0;
}

char *strlwr(char *s)
{
  while (*s != '\0') {
    *s = tolower(*s);
    s++;
  }
  return s;
}

char *strrev(char *s)
{
  char tmp;
  int len = strlen(s);
  for (int i = 0; i < len / 2; i++) {
    tmp = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = tmp;
  }
  return s;
}

char *strset(char *s, int ch)
{
  memset(s, ch, strlen(s));
  return s;
}
