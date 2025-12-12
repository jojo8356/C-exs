#include <stdio.h>

typedef struct {
  int a;
  int b;
  float c;
  char d;
} Exemple;

int main() {
  Exemple var1 = {10, 20, 30.5, 'A'};
  Exemple var2 = {15, 25, 35.5, 'B'};

  printf("Variable 1: %d, %d, %.1f, %c\n", var1.a, var1.b, var1.c, var1.d);
  printf("Variable 2: %d, %d, %.1f, %c\n", var2.a, var2.b, var2.c, var2.d);

  return 0;
}
