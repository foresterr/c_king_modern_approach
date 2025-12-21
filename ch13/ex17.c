#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool test_extension(const char *file_name, const char *extension)
{
  const char *pf = file_name, *pe = extension;
  while (*pf)
    pf++; // points at null terminator
  while (*pe)
    pe++; // same
  while (toupper(*pe) == toupper(*pf)) {
    if (pf <= file_name) return false;
    pf--;
    if (pe <= extension) break;
    pe--;
  }
  return (bool)(*pf == '.');
}

int main(void)
{
  char filename[100], extension[10];

  puts("Enter file name: \b");
  scanf("%s", filename);
  puts("Enter extension: \b");
  scanf("%s", extension);

  if (test_extension(filename, extension))
    puts("Extension matches\n");
  else
    puts("Extension does not match\n");

  return 0;
}
