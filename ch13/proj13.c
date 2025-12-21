#include <stdio.h>

#define MAXSTRLEN 100

void encrypt(char *message, int shift);

int main(void)
{
  char msg[MAXSTRLEN];
  int shift;

  printf("Enter message to be encrypted: ");
  fgets(msg, MAXSTRLEN, stdin);
  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);
  encrypt(msg, shift);
  printf("Encrypted message: %s", msg);

  return 0;
}

void encrypt(char *message, int shift)
{
  while (*message) {
    if (*message >= 'A' && *message <= 'Z')
      *message = ((*message - 'A') + shift) % 26 + 'A';
    else if (*message >= 'a' && *message <= 'z')
      *message = ((*message - 'a') + shift) % 26 + 'a';
    message++;
  }
}
