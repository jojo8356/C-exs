#include <stdio.h>
#include "../lib/tableaux.h"

int main() {
  int t[10];
  int n = 10;
  int k;
  printf("Saisir les éléments du tableau (%d éléments):\n", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &t[i]);
  printf("Quel méthode de tri?\n1: Tri par sélection\n2: Tri à bulles\n3: Tri à bulles optimisé\n4: Tri par insertion\n");
  scanf("%d", &k);
  switch(k){
    case 1:
        triSelectionTab(t, n);
        break;
    case 2:
        triABullesTab(t, n);
        break;
    case 3:
        triABullesOptimiseTab(t, n);
        break;
    case 4:
        triInsertionTab(t, n);
        break;
    default:
        printf("Méthode non reconnue\n");
        return 1;
  }
  printf("Tableau trié:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", t[i]);
  printf("\n");
  }

  return 0;
}