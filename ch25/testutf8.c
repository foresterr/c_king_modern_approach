#include <stdio.h>
#include <string.h>

int main(void)
{
  printf("Zażółć gęślą jaźń\n");
  printf("%s  length: %ld\n", "ąćęłśńóżź", strlen("ąćęłśńóżź"));
  printf("%s  length: %ld\n", "acelsnozz", strlen("acelsnozz"));
}
