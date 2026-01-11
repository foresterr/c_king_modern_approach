#pragma once
#include <stdbool.h>

bool queue_is_empty(void);
bool queue_is_full(void);
void queue_clear(void);
void queue_push(int i);
int queue_peek_first(void);
int queue_peek_last(void);
int queue_pop(void);
