#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
};

int main(int argc, char *argv[])
{
  enum {IN1, IN2, OUT};
  int i, fread_n1, fread_n2;
  FILE *fp[3];
  bool fopen_error = false;
  struct part part1, part2;
  if (argc != 4) {
    printf("usage: invmerge file_in1 file_in2 file_out\n");
    exit(EXIT_FAILURE);
  }
  fp[IN1] = fopen(argv[1], "rb");
  fp[IN2] = fopen(argv[2], "rb");
  fp[OUT] = fopen(argv[3], "wb");
  for (i = 0; i < 3; i++) {
    if (fp[i] == NULL) {
      printf("%s can't be opened\n", argv[i+1]);
      fopen_error = true;
    }
  }
  if (fopen_error) {
    for (i = 0; i < 3; i++) {
      if (fp[i] != NULL) {
        fclose(fp[i]);
      }
    }
    exit(EXIT_FAILURE);
  }

  fread_n1 = fread(&part1, sizeof(struct part), 1, fp[IN1]);
  fread_n2 = fread(&part2, sizeof(struct part), 1, fp[IN2]);
  while (fread_n1 == 1 && fread_n2 == 1) {
    if (part1.number == part2.number) {
      if (strcmp(part1.name, part2.name) != 0) {
        printf("Name mismatch for part #%d, using %s\n", part1.number, part1.name);
      }
      part1.on_hand += part2.on_hand;
      fwrite(&part1, sizeof(struct part), 1, fp[OUT]);
      fread_n1 = fread(&part1, sizeof(struct part), 1, fp[IN1]);
      fread_n2 = fread(&part2, sizeof(struct part), 1, fp[IN2]);
    }
    else if (part1.number < part2.number) {
      fwrite(&part1, sizeof(struct part), 1, fp[OUT]);
      fread_n1 = fread(&part1, sizeof(struct part), 1, fp[IN1]);
    }
    else {
      fwrite(&part2, sizeof(struct part), 1, fp[OUT]);
      fread_n2 = fread(&part2, sizeof(struct part), 1, fp[IN2]);
    }
  }
  while (fread_n1 == 1) {
    fwrite(&part1, sizeof(struct part), 1, fp[OUT]);
    fread_n1 = fread(&part1, sizeof(struct part), 1, fp[IN1]);
  }
  while (fread_n2 == 1) {
    fwrite(&part2, sizeof(struct part), 1, fp[OUT]);
    fread_n2 = fread(&part2, sizeof(struct part), 1, fp[IN2]);
  }

  for (i = 0; i < 3; i++) {
    fclose(fp[i]);
  }
  exit(EXIT_SUCCESS);
}
