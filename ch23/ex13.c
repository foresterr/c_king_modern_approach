#include <string.h>

int count_words(char *sentence)
{
  int count = 0;
  if (strtok(sentence, " \f\n\r\t\v") != NULL) {
    count++;
    while (strtok(NULL, " \f\n\r\t\v") != NULL) {
      count++;
    }
  }
  return count;
}
