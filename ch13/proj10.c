#include <stdio.h>
#include <ctype.h>

#define MAXSTRLEN 100

void reverse_name(char *name);

int main(void)
{
  char name[MAXSTRLEN];

  printf("Enter a first and a last name: ");
  fgets(name, MAXSTRLEN, stdin);
  reverse_name(name);
  printf("%s\n", name);
  return 0;
}

void reverse_name(char *name)
{
  char initial, *p = name;
  while (isspace(*p)) p++; // skip wspace, p points at first non-wspace char (or start)
  initial = *p; // remember initial
  while (isalpha(*p)) p++; // skip non-wspace, p points at first wspace
  while (isspace(*p)) p++; // skip whitespace again
  while (isalpha(*name = *p++)) name++; // name points at last surname character
  *name++ = ',';
  *name++ = ' ';
  *name++ = initial;
  *name++ = '.';
  *name++ = '\0';
}
