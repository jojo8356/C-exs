#include <stdio.h>

bool estPair(int a) { return a % 2 == 0; }

/*
int main() {
  int nb;
  puts("Entrez un nombre entier: ");
  scanf("%d", &nb);
  printf("%d est ", nb);
  if (estPair(nb))
    printf("pair");
  else
    printf("impair");
  printf("\n");
  return 0;
}
*/

int main() {
  for (int i = 1; i <= 10; i++) printf("%d ", i * 2);
  printf("\n");
  return 0;
}