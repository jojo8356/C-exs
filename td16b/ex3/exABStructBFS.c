#include <stdio.h>
#include <stdlib.h>

#include "../../lib/arbres.h"

int main(void) {
  printf("Création de l'arbre: "
         "https://commons.wikimedia.org/wiki/File:Binary_tree.svg\n\n");

  NoeudAB* arbre = creerExempleAB();
  afficherAB(arbre);

  printf("\nParcours en largeur : ");
  parcoursLargeur(arbre);

  libererAB(&arbre);
  return 0;
}
