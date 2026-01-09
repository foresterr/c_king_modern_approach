#pragma once
#include <stdbool.h>

struct node {
  int value;
  struct node *next;
};

typedef struct node *Stack;

void make_empty(Stack *s);
bool is_empty(const Stack *s);
bool is_full(const Stack *s);
void push(Stack *s, int i);
int pop(Stack *s);
