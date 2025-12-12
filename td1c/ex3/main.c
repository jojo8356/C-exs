#include <stdio.h>

bool estDivisible(int nb, int div) { return nb % div == 0; }

bool estPremier(int nb) {
  for (int i = 2; i < nb; i++)
    if (estDivisible(nb, i)) return 0;
  return 1;
}

/*
int main() {
  int nb;
  int div;
  printf("Entrez un entier et un diviseur : ");
  scanf("%d %d", &nb, &div);
  if (estDivisible(nb, div)) printf("%d  est divisible par %d.\n", nb, div);
  return 0;
}
*/

int main() {
  printf("Liste des nombres premiers\n");
  for (int i = 2; i <= 100; i++)
    if (estPremier(i)) printf("%d ", i);
  printf("\n");
  return 0;
}