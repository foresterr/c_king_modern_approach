/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* line.c (Chapter 15, page 364) */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct word {
  char *word;
  struct word *next;
};

struct word *line = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  struct word *p = line, *temp;
  while (p != NULL) {
    temp = p;
    p = p->next;
    free(temp->word);
    free(temp);
  }
  line = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  int word_len = strlen(word) + 1;
  /* allocate space for new word struct and string */
  struct word *new_word = malloc(sizeof(struct word)), **p;
  char *word_chars = malloc(word_len);
  if (new_word == NULL || word_chars == NULL) {
    printf("Error: malloc failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  /* make new word struct */
  strcpy(word_chars, word);
  new_word->word = word_chars;
  new_word->next = NULL;
  /* find tail pointer of the list */
  for (p = &line; *p != NULL; p = &(*p)->next)
    ;
  /* insert new word struct at the end of list */
  *p = new_word;
  /* update tracking variables */
  line_len += word_len;
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces = MAX_LINE_LEN - line_len ;
  struct word *p = line;
  while (p != NULL) {
    printf("%s", p->word);
    p = p->next;
    if (p != NULL) {
      int extra_spaces_to_insert = extra_spaces / (num_words - 1);
      for (int i = 1; i <= extra_spaces_to_insert + 1; i++)
        putchar(' ');
      extra_spaces -= extra_spaces_to_insert;
      num_words--;
    } else
      putchar('\n');
  }
}

void flush_line(void)
{
  struct word *p = line;
  while (p != NULL) {
    printf("%s", p->word);
    p = p->next;
    if (p != NULL)
      putchar(' ');
    else
      putchar('\n');
  }
}
