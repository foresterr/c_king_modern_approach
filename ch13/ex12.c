#include <string.h>
#include <stdio.h>

void get_extension(const char *file_name, char *extension)
{
  const char *p = file_name + strlen(file_name); // points to terminating \0

  while (p > file_name && *--p != '.'); // scrolls p to the position of last dot in filename
    // do nothing
  if (p == file_name)
    *extension = '\0'; // this means that either there are no dots in filename, or only the first character is a dot
  else
    strcpy(extension, p + 1); // copy extension into extension array, sans dot
}

int main(void) {
  char file_name[100], extension[10];
  printf("Input a file name: ");
  scanf("%s", file_name);
  get_extension(file_name, extension);
  printf("Extension is: %s\n", extension);
  return 0;
}
