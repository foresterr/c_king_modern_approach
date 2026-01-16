#include <stdio.h>

int main(void) {
  int widget;
  widget = 1;
  printf("%d widget%s\n", widget, widget == 1 ? "" : "s");
  widget = 5;
  printf("%d widget%s\n", widget, widget == 1 ? "" : "s");
}
