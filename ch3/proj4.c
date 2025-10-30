#include <stdio.h>

int main(void){
  int p1, p2, p3;
  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%d) %d-%d", &p1, &p2, &p3);
  printf("You entered %d.%d.%d\n", p1, p2, p3);

  return 0;
}
