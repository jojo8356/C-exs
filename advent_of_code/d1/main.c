#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(int* lock, char* cmd) {
  bool right = false;
  if (strlen(cmd) < 2) return;
  if (cmd[0] == 'R') {
    right = true;
  }
  int step = atoi(&cmd[1]);
  if (right) {
    (*lock) += step;
  } else {
    (*lock) -= step;
  }
  if ((*lock) > 99) {
    (*lock) -= 100;
  }
  if ((*lock) < 0) {
    (*lock) += 100;
  }
}

int main() {
  int lock = 50;
  char* cmds = "L68 L30 R48 L5 R60 L55 L1 L99 R14 L82";
  char* lines = strtok(cmds, " ");
  while (lines != NULL) {
    rotate(&lock, lines);
    printf("Lock position: %d\n", lock);
    lines = strtok(NULL, "\n");
  }
  return 0;
}