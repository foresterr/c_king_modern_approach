#include <stdio.h>

int main(void)
{
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);
  printf("The number %d has ", n);
  if (n < 10) printf("1 digit\n");
  else if (n < 100) printf("2 digits\n");
  else printf("3 digits\n");

  return 0;
}
