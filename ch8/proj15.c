#include <stdio.h>

int main(void)
{
  char msg_chars[80];
  int i = 0, shift;

  printf("Enter message to be encrypted: ");
  while ((msg_chars[i++] = getchar()) != '\n');
  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  printf("Encrypted message: ");
  for(int j = 0; j < i; j++) {
    if (msg_chars[j] >= 'A' && msg_chars[j] <= 'Z')
      putchar(((msg_chars[j] - 'A') + shift) % 26 + 'A');
    else if (msg_chars[j] >= 'a' && msg_chars[j] <= 'z')
      putchar(((msg_chars[j] - 'a') + shift) % 26 + 'a');
    else
      putchar(msg_chars[j]);
  }
  putchar('\n');

  return 0;
}
