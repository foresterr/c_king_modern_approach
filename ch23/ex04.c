#include <stdbool.h>
#include <ctype.h>

bool is_identifier(char *str)
{
  if (!isalpha(*str) && *str != '_') {
    return false; /* note, this will also return false if it's an empty string - which is not a valid identifier */
  }
  while (*++str != '\0') {
    if (!isalnum(*str) && *str != '_') {
      return false;
    }
  }
  return true;
}
