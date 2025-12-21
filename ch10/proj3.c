/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* poker.c (Chapter 10, page 233) */
/* Classifies a poker hand */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
int hand[NUM_CARDS][2]; /* column 0 is rank, column 1 is suit */
bool straight, flush, four, three;
int pairs;   /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
  for (;;) {
    read_cards();
    analyze_hand();
    print_result();
  }
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables num_in_rank and num_in_suit;     *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(void)
{
  char ch, rank_ch, suit_ch;
  int card, rank, suit;
  bool bad_card, duplicate_card;
  int cards_read = 0;

  while (cards_read < NUM_CARDS) {
    bad_card = false;
    duplicate_card = false;

    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
      case '0':           exit(EXIT_SUCCESS);
      case '2':           rank = 0; break;
      case '3':           rank = 1; break;
      case '4':           rank = 2; break;
      case '5':           rank = 3; break;
      case '6':           rank = 4; break;
      case '7':           rank = 5; break;
      case '8':           rank = 6; break;
      case '9':           rank = 7; break;
      case 't': case 'T': rank = 8; break;
      case 'j': case 'J': rank = 9; break;
      case 'q': case 'Q': rank = 10; break;
      case 'k': case 'K': rank = 11; break;
      case 'a': case 'A': rank = 12; break;
      default:            bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch) {
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'H': suit = 2; break;
      case 's': case 'S': suit = 3; break;
      default:            bad_card = true;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ') bad_card = true;

    for (int i = 0; i < cards_read; i++) {
      if (hand[i][0] == rank && hand[i][1] == suit)
        duplicate_card = true;
    }

    if (bad_card)
      printf("Bad card; ignored.\n");
    else if (duplicate_card) {
      printf("Duplicate card; ignored.\n");
    }
    else {
      hand[cards_read][0] = rank;
      hand[cards_read][1] = suit;
      cards_read++;
    }
  }

  /* sort the hand by rank, it will make analysis much easier */
  for (int i = NUM_CARDS - 1; i >= 0; i--)
    for (int j = 0; j < i; j++) {
      if (hand[j][0] > hand[j + 1][0]) {
        int temp_rank = hand[j + 1][0];
        int temp_suit = hand[j + 1][1];
        hand[j + 1][0] = hand[j][0];
        hand[j + 1][1] = hand[j][1];
        hand[j][0] = temp_rank;
        hand[j][1] = temp_suit;
      }
    }
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand(void)
{
  int num_same_rank = 1; /* there is always at least current card */
  int rank, suit;

  straight = true;
  flush = true;
  four = false;
  three = false;
  pairs = 0;

  /* check for everything in one loop */
  for (int i = 0; i < NUM_CARDS - 1; i++) {
    /* flush */
    if (hand[i][1] != hand[i + 1][1])
      flush = false;
    /* straight */
    if (hand[i][0] + 1 != hand[i + 1][0])
      straight = false;
    /* same of a kinds */
    if (hand[i][0] == hand[i+1][0])
      num_same_rank++;
    else
      num_same_rank = 1;
    switch (num_same_rank) {
      case 2:
        pairs++;
        break;
      case 3:
        three = true;
        break;
      case 4:
        four = true;
        break;
    }
  }
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void)
{
  if (straight && flush) printf("Straight flush");
  else if (four)         printf("Four of a kind");
  else if (three &&
           pairs == 1)   printf("Full house");
  else if (flush)        printf("Flush");
  else if (straight)     printf("Straight");
  else if (three)        printf("Three of a kind");
  else if (pairs == 2)   printf("Two pairs");
  else if (pairs == 1)   printf("Pair");
  else                   printf("High card");

  printf("\n\n");
}

