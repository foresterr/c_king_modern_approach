#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N_BYTES_LINE 10

static void print_bytes(unsigned char *b, int n);
static void print_chars(unsigned char *b, int n);

int main(int argc, char *argv[])
{
  FILE *fp;
  unsigned char bytes[N_BYTES_LINE];
  int nread;
  long lastoffset;

  if (argc != 2) {
    printf("usage: byteview filename\n");
    exit(EXIT_FAILURE);
  }
  if((fp = fopen(argv[1], "rb")) == NULL) {
    printf("error: %s cannot be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Offset               Bytes               Characters\n");
  printf("------   -----------------------------   ----------\n");

  do {
    lastoffset = ftell(fp);
    nread = fread(bytes, sizeof(bytes[0]), N_BYTES_LINE, fp);
    if (nread == 0) {
      break;
    }
    else {
      printf("%6ld   ", lastoffset);
    }
    print_bytes(bytes, nread);
    printf("  ");
    print_chars(bytes, nread);
    putchar('\n');
  } while (nread == 10);

  fclose(fp);
  exit(EXIT_SUCCESS);
}

static void print_bytes(unsigned char *b, int n)
{
  for (int i = 0; i < n; i++) {
    printf("%02X ", b[i]);
  }
  for (int i = 0; i < N_BYTES_LINE - n; i++) {
    printf("   ");
  }
}

static void print_chars(unsigned char *b, int n)
{
  for (int i = 0; i < n; i++) {
    if (isprint(b[i])) {
      putchar(b[i]);
    }
    else {
      putchar('.');
    }
  }
}
