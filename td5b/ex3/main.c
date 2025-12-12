#include <stdio.h>

#include "../lib/tableaux.h"

int main() {
  int tab[] = {-1, 2, -3, 4, -5};
  afficherTab(tab, 5);
  printf("La somme du tableau est : %d\n", sommeTab(tab, 5));
  printf("La moyenne du tableau est : %.2f\n", moyenneTab(tab, 5));
  printf("La valeur maximale du tableau est : %d\n", maxTab(tab, 5));
  printf("La valeur minimale du tableau est : %d\n", minTab(tab, 5));

  return 0;
}