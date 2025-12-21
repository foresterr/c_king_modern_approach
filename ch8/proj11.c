#include <stdio.h>

int main(void)
{
  char c[15];
  int i;

  printf("Enter phone number: ");
  //read number into array and convert
  i = 0;
  while ((c[i] = getchar()) != '\n') {
    if (c[i] >= 'A' && c[i] <= 'Y')
      c[i] = (c[i] - 'A') / 3 + '2';
    i++;
  }

  printf("In numeric form: ");
  //write output
  i = 0;
  while (putchar(c[i++]) != '\n');
  
  return 0;
}

