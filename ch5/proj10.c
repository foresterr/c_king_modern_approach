#include <stdio.h>

int main(void)
{
  int grade;

  printf("Enter numerical grade (0-100): ");
  scanf("%d", &grade);

  if (grade < 0 || grade > 100) {
    printf("Error: Invalid grade\n");
    return 0;
  }
  
  printf("Letter grade: ");
  grade /= 10;
  switch (grade) {
    case 10:
    case 9:
      printf("A");
      break;
    case 8:
      printf("B");
      break;
    case 7:
      printf("C");
      break;
    case 6:
      printf("D");
      break;
    default:
      printf("F");
      break;
  }
  printf("\n");

  return 0;
}
