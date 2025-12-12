#include <stdio.h>

void echanger(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int x = 5;
  int y = 10;
  printf("Avant échange: x = %d, y = %d\n", x, y);
  echanger(&x, &y);
  printf("Après échange: x = %d, y = %d\n", x, y);
  return 0;
}
