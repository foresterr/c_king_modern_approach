/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* remind2.c (Chapter 17, page 418) */
/* Prints a one-month reminder list (dynamic string version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

struct vstring {
  int len;
  char chars[];
};

int read_line(char str[], int n);
int vstringcmp(const struct vstring *vs1, const struct vstring *vs2);
void putvstring (const struct vstring *vs);

int main(void)
{
  struct vstring *reminders[MAX_REMIND];
  struct vstring *new_reminder_vstring;
  char day_str[3], msg_str[MSG_LEN+1], reminder_str[MSG_LEN+3];
  int day, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;
    sprintf(day_str, "%2d", day);
    read_line(msg_str, MSG_LEN);
    strcpy(reminder_str, day_str);
    strcat(reminder_str, msg_str);
    
    new_reminder_vstring = malloc(sizeof(struct vstring) + strlen(reminder_str));
    if (new_reminder_vstring == NULL) {
      printf("-- No space left --\n");
      break;
    }
    for (i = 0; reminder_str[i] != '\0'; i++)
      new_reminder_vstring->chars[i] = reminder_str[i];
    new_reminder_vstring->len = strlen(reminder_str);

    for (i = 0; i < num_remind; i++)
      if (vstringcmp(new_reminder_vstring, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      reminders[j] = reminders[j-1];

    reminders[i] = new_reminder_vstring;
    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    putvstring(reminders[i]);
  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}

int vstringcmp(const struct vstring *vs1, const struct vstring *vs2)
{
  for (int i = 0; i < vs1->len && i < vs2->len; i++)
    if (vs1->chars[i] > vs2->chars[i])
      return 1;
    else if (vs1->chars[i] < vs2->chars[i])
      return -1;
  if (vs1->len > vs2->len)
    return 1;
  else if (vs1->len < vs2->len)
    return -1;
  return 0;
}

void putvstring (const struct vstring *vs)
{
  for(int i = 0; i < vs->len; i++)
    putchar(vs->chars[i]);
  putchar('\n');
}

