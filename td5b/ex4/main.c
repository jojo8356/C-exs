#include <stdio.h>

#include "../lib/tableaux.h"

int main() {
  int tab[] = {3, 2, 2, 1, 1, 1};
  afficherTab(tab, 6);
  for (int i = 0; i < 5; i++) {
    printf("\nPrésence de %d: %d\n", i, rechercherValeur(tab, 6, i));

    printf("Nombre d'occurrences de %d: %d\n", i,
           compterOccurrences(tab, 6, i));
  }
  return 0;
}