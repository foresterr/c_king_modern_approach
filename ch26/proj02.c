#include <stdlib.h>
#include <stdio.h>

void atex1(void);
void atex2(void);

int main(void)
{
  atexit(atex2);
  atexit(atex1);
  return 0;
}

void atex1(void)
{
  printf("That's all,");
}

void atex2(void)
{
  printf(" folks!\n");
}
