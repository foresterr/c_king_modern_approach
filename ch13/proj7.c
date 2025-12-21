#include <stdio.h>

int main(void)
{
  int n;

  const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  const char *ones[] = {"", "one", "two", "three", "four", "five",
                        "six", "seven", "eight", "nine"};
  const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", 
                        "sixty", "seventy", "eighty", "ninety"};

  printf("Enter a two-digit number: ");
  scanf("%d", &n);

  printf("You entered the number ");
  if (n < 20)
    printf("%s", teens[n - 10]);
  else if (n % 10)
    printf("%s-%s", tens[n / 10], ones[n % 10]);
  else
    printf("%s", tens[n / 10]);
  putchar('\n');
  return 0;
}

