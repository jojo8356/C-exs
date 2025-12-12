#include <stdio.h>

#include "../lib/tableaux.h"

int main() {
  puts("Tests de tris à bulles");

  // valeurs quelconques
  int tab1[] = {5, 3, -1, 4, -2};
  puts("\nAvant tri");
  afficherTab(tab1, 5);
  triSelectionTab(tab1, 5);
  puts("Après tri");
  afficherTab(tab1, 5);

  // Déja trié
  int tab2[] = {-1, 0, 1};
  puts("\nAvant tri");
  afficherTab(tab2, 3);
  triSelectionTab(tab2, 3);
  puts("Après tri");
  afficherTab(tab2, 3);

  // à l'envers
  int tab3[] = {5, 4, 3, 2, 1, 0, -1, -2, 3, -4, -5};
  puts("\nAvant tri");
  afficherTab(tab3, 11);
  triSelectionTab(tab3, 11);
  puts("Après tri");
  afficherTab(tab3, 11);
}