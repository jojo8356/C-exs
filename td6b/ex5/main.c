#include <stdio.h>

#include "../lib/tableaux.h"
#include <stdlib.h>

/*
int main() {
  int taille;
  while (scanf("%d", &taille) == 1) {
    // déclaration du tableau
    int tab[taille];

    // Lecture des éléments et remplissage du tableau
    for (int i = 0; i < taille; i++) {
      scanf("%d", &tab[i]);
    }

    printf("Avant tri : ");
    afficherTab(tab, taille);

    // Tri du tableau
    triABullesTab(tab, taille);

    printf("Après tri : ");
    afficherTab(tab, taille);

    // Vérification du tri
    bool estTrie = estCroissantTab(tab, taille);
    printf("Le tableau %s trié\n", estTrie ? "est" : "n'est pas");
  }

  puts("Tests finis");
  return 0;
}
*/

/*
int main() {
  int taille;
  int notSorted = 0;
  int sorted = 0;
  while (scanf("%d", &taille) == 1) {
    // déclaration du tableau
    int tab[taille];

    // Lecture des éléments et remplissage du tableau
    for (int i = 0; i < taille; i++) {
      scanf("%d", &tab[i]);
    }
    triABullesTab(tab, taille);

    // Vérification du tri
    bool estTrie = estCroissantTab(tab, taille);
    if (estTrie) {
      sorted++;
    } else {
      notSorted++;
    }
  }
  printf("Tests finis: %d triés, %d non triés\n", sorted, notSorted);
  return 0;
}
*/

/*
int main() {
  int taille;
  int notSorted = 0;
  int sorted = 0;
  while (scanf("%d", &taille) == 1) {
    // déclaration du tableau
    int tab[taille];

    // Lecture des éléments et remplissage du tableau
    for (int i = 0; i < taille; i++) {
      scanf("%d", &tab[i]);
    }
    triABullesOptimiseTab(tab, taille);

    // Vérification du tri
    bool estTrie = estCroissantTab(tab, taille);
    if (estTrie) {
      sorted++;
    } else {
      notSorted++;
    }
  }
  printf("Tests finis: %d triés, %d non triés\n", sorted, notSorted);
  return 0;
}
*/

/*
int main() {
  int taille;
  int notSorted = 0;
  int sorted = 0;
  while (scanf("%d", &taille) == 1) {
    // déclaration du tableau
    int tab[taille];

    // Lecture des éléments et remplissage du tableau
    for (int i = 0; i < taille; i++) {
      scanf("%d", &tab[i]);
    }
    triFusionIteratifTab(tab, taille);

    // Vérification du tri
    bool estTrie = estCroissantTab(tab, taille);
    if (estTrie) {
      sorted++;
    } else {
      notSorted++;
    }
  }
  printf("Tests finis: %d triés, %d non triés\n", sorted, notSorted);
  return 0;
}
*/

/*
int main() {
  int taille;
  int notSorted = 0;
  int sorted = 0;
  while (scanf("%d", &taille) == 1) {
    // déclaration du tableau
    int tab[taille];

    // Lecture des éléments et remplissage du tableau
    for (int i = 0; i < taille; i++) {
      scanf("%d", &tab[i]);
    }
    triInsertionTab(tab, taille);

    // Vérification du tri
    bool estTrie = estCroissantTab(tab, taille);
    if (estTrie) {
      sorted++;
    } else {
      notSorted++;
    }
  }
  printf("Tests finis: %d triés, %d non triés\n", sorted, notSorted);
  return 0;
}
*/

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Usage: ./test_tris [algorithme]\nAlgorithmes disponibles:\n1: Tri par sélection\n2: Tri à bulles\n3: Tri à bulles optimisé\n4: Tri par insertion\n");
    return 0;
  }
  int taille;
  while (scanf("%d", &taille) == 1) {
    // déclaration du tableau
    int tab[taille];

    // Lecture des éléments et remplissage du tableau
    for (int i = 0; i < taille; i++) {
      scanf("%d", &tab[i]);
    }
    switch(atoi(argv[1])) {
        case 1:
            triSelectionTab(tab, taille);
            break;
        case 2:
            triABullesTab(tab, taille);
            break;
        case 3:
            triABullesOptimiseTab(tab, taille);
            break;
        case 4:
            triInsertionTab(tab, taille);
            break;
        default:
            printf("Méthode non reconnue\n");
            return 1;
    }

    // Vérification du tri
    bool estTrie = estCroissantTab(tab, taille);
    if (!estTrie){
        fprintf(stderr, "Le tableau n'est pas trié\n");
        return 1;
    }
  }
  puts("Tests finis");
  return 0;
}