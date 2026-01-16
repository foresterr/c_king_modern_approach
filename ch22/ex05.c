#include <stdio.h>

int main(void)
{
  printf("%.4d\n",1);
  printf("%04d\n",1);
  printf("%.4d\n",-1);
  printf("%04d\n",-1);
  printf("%.4d\n",12345);
  printf("%04d\n",12345);
  printf("%.4d\n",-12345);
  printf("%04d\n",-12345);
  printf("%.4d\n",1234);
  printf("%04d\n",1234);
  printf("%.4d\n",-1234);
  printf("%04d\n",-1234);
  printf("%.4d\n",0);
  printf("%04d\n",0);
}
