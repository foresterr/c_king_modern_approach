#include <stdio.h>
#include <stdlib.h>

#define DATA_FILE "flights.dat"

int main(void)
{
  FILE *fp;
  int h, m, minutes, lines = 0, ch, i;
  enum {DEPARTURE, ARRIVAL};

  if ((fp = fopen(DATA_FILE, "r")) == NULL) {
    printf("%s can't be opened\n", DATA_FILE);
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(fp)) != EOF) {
    if (ch == '\n') {
      lines++;
    }
  }
  if (lines == 0) {
    printf("%s is empty\n", DATA_FILE);
    fclose(fp);
    exit(EXIT_FAILURE);
  }
  fseek(fp, 0, SEEK_SET);
  int flights[lines][2];

  for (i = 0; i < lines * 2; i++) {
    if (fscanf(fp, " %d:%d", &h, &m) != 2) {
      break;
    }
    flights[i / 2][i % 2] = h * 60 + m;
  }
  fclose(fp);

  printf("Enter a 24-h time: ");
  scanf("%d:%d", &h, &m);
  minutes = h * 60 + m;

  for (i = 0; minutes > flights[i][DEPARTURE] && i < lines; i++)
    ;
  if (i == lines) {
    i = 0;
  }
  printf("Closest departure time is %d:%02d %c.m., arriving at %d:%02d %c.m.\n",
          (flights[i][DEPARTURE] / 60 + 11) % 12 + 1,
          flights[i][DEPARTURE] % 60,
          flights[i][DEPARTURE] < 12 * 60 ? 'a' : 'p',
          (flights[i][ARRIVAL] / 60 + 11) % 12 + 1,
          flights[i][ARRIVAL] % 60,
          flights[i][ARRIVAL] < 12 * 60 ? 'a' : 'p'
        );

  exit(EXIT_SUCCESS);
}
