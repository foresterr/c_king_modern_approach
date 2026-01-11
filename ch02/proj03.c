#include <stdio.h>

#define PI 3.14159265

int main(void)
{
  float r;
  printf("Radius of the sphere: ");
  scanf("%f", &r);
  printf("Volume of the sphere: %f\n", r * r * PI * 3.0f / 4.0f); 

  return 0;
}
