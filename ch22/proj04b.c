#include <stdio.h>
#include <stdlib.h>
/* technically ctype.h is covered in next chapter, but it was already used in some previous
 * exercises so I don't think it's a problem to use it here
 */
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int ch, count = 0;
  if (argc != 2) {
    printf("usage: countwords filename\n");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("%s cannot be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  while ((ch = fgetc(fp)) != EOF) {
    if (!isspace(ch)) {
      count++;
      while ((ch = fgetc(fp)) != EOF && !isspace(ch))
        ;
    }
  }
  printf("%d words in %s\n", count, argv[1]);
  return 0;
}
