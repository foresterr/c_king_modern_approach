/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* justify.c (Chapter 15, page 363) */
/* Formats a file of text */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
  FILE *fp_in, *fp_out;
  char word[MAX_WORD_LEN+2];
  int word_len;

  if (argc != 3) {
    printf("Usage: justify file_in file_out\n");
    exit(EXIT_FAILURE);
  }
  /* let's try to do it the lazy way. all functions expect their input and output to be
   * stdin/stdout
   */
  if ((fp_in = freopen(argv[1], "r", stdin)) == NULL) {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((fp_out = freopen(argv[2], "w", stdout)) == NULL) {
    printf("%s can't be opened\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN+1);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line();
      fclose(fp_in);
      fclose(fp_out);
      exit(EXIT_SUCCESS);
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    add_word(word);
  }
}
