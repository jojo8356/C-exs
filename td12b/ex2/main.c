#include <stdio.h>
#include <stdlib.h>
#include "../../lib/tableaux.h"
#include "../../lib/liste.h"

Noeud* insereElementListe(Noeud* l, int x) {
    Noeud* n = nouveauNoeud(x);

    if (!l || x < l->value) {
        n->suivant = l;
        return n;
    }

    Noeud* current = l;
    while (current->suivant && current->suivant->value < x) {
        current = current->suivant;
    }

    n->suivant = current->suivant;
    current->suivant = n;
    return l;
}

Noeud* triListe(Noeud* l) {
    Noeud* tri = NULL;

    while (l) {
        tri = insereElementListe(tri, l->value);
        l = l->suivant;
    }

    return tri;
}

// on passe le tableau et la taille sous forme de
// pointeurs pour pouvoir les modifier sur place
void insereElementTabTrie(int** tab, int donnee, int* taille) {
  /* Augmenter de 1 la taille du tableau alloué */
  int* newTab = realloc(*tab, (*taille + 1) * sizeof(int));
  if (newTab == NULL) {
    fprintf(stderr, "Erreur de réallocation de mémoire\n");
    exit(EXIT_FAILURE);
  }
  *tab = newTab;
  // appliquer l'algorithme d'insertion
    int i = *taille - 1;
    while (i >= 0 && (*tab)[i] > donnee) {
        (*tab)[i + 1] = (*tab)[i];
        i--;
    }
    (*tab)[i + 1] = donnee;
    (*taille)++;
}

int main() {
  int taille;
  int* tab;
  printf("Quelle taille de tableau souhaitez-vous?\n");
  scanf("%d", &taille);
  printf("Créez un tableau de %d éléments non triés SVP\n", taille);
  tab = tableauScanfTaille(taille);

  afficherTab(tab, taille);
  printf("Tab %s trié\n", estTrieeTab(tab, taille) ? "" : "non");
  printf("On trie le Tab\n");
  triTab(tab, taille);
  afficherTab(tab, taille);

  printf("Tab %s trié.\n", estTrieeTab(tab, taille) ? "" : "non");

  // Test d'insertion en boucle
  printf("\nInsertion d'éléments\n");
  for (int i = 0; i < 6; i += 2) {
    printf("On insère la valueeur %d\n", i);
    insereElementTabTrie(&tab, i, &taille);
    afficherTab(tab, taille);
  }

  // Libération de la mémoire
  free(tab);

  return 0;
}