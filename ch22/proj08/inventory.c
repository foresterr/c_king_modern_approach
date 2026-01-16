/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* inventory.c (Chapter 16, page 391) */
/* Maintains a parts database (array version) */

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;   /* number of parts currently stored */
char filename[FILENAME_MAX+1];

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);
void sort(void);
int part_compare(const void *part1, const void *part2);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'i': insert();
                break;
      case 's': search();
                break;
      case 'u': update();
                break;
      case 'p': print();
                break;
      case 'd': dump();
                break;
      case 'r': restore();
                break;
      case 'o': sort();
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            array. Returns the array index if the part  *
 *            number is found; otherwise, returns -1.     *
 **********************************************************/
int find_part(int number)
{
  int i;

  for (i = 0; i < num_parts; i++)
    if (inventory[i].number == number)
      return i;
  return -1;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         database. Prints an error message and returns  *
 *         prematurely if the part already exists or the  *
 *         database is full.                              *
 **********************************************************/
void insert(void)
{
  int part_number;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);
  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);
  num_parts++;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         Prints an error message if the part doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update(void)
{
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Parts are printed in the      *
 *        order in which they were entered into the       *
 *        database.                                       *
 **********************************************************/
void print(void)
{
  int i;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (i = 0; i < num_parts; i++)
    printf("%7d       %-25s%11d\n", inventory[i].number,
           inventory[i].name, inventory[i].on_hand);
}

/**********************************************************
 * dump: Asks user for a file name, then writes database  *
 *       to that file. Any previous file contents will be *
 *       overwritten.
 **********************************************************/
void dump(void)
{
  FILE *fp;
  int n_records;
  printf("Enter name of output file: ");
  read_line(filename, FILENAME_MAX);
  if ((fp = fopen(filename, "wb")) == NULL) {
    printf("%s cannot be opened\n", filename);
    return;
  }
  n_records = fwrite(inventory, sizeof(inventory[0]), num_parts, fp);
  fclose(fp);
  printf("%d part records dumped to %s\n", n_records, filename);
  if (n_records !=  num_parts) {
    printf("error writing to %s, database dump incomplete\n", filename);
  }
}

/**********************************************************
 * restore: Asks user for a file name, then reads         *
 *          database from that file into memory if it     *
 *          exists. If any database exists in memory at   *
 *          that time, it will be overwritten.            *
 **********************************************************/
void restore(void)
{
  FILE *fp;
  printf("Enter name of input file: ");
  read_line(filename, FILENAME_MAX);
  if ((fp = fopen(filename, "rb")) == NULL) {
    printf("%s cannot be opened\n", filename);
    return;
  }
  num_parts = fread(inventory, sizeof(inventory[0]), MAX_PARTS, fp);
  fclose(fp);
  printf("%d part records restored from %s\n", num_parts, filename);
}

/**********************************************************
 * sort: Sorts database in ascending part number order    *
 * and prints confirmation                                *
 **********************************************************/
void sort(void)
{
  qsort(inventory, num_parts, sizeof(struct part), part_compare);
}

int part_compare(const void *p1, const void *p2)
{
  const struct part *part1 = p1, *part2 = p2;
  return part1->number - part2->number;
}
