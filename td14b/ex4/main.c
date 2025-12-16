#include <stdio.h>
#include <stdlib.h>

#include "../../lib/arbres.h"

int main() {
  NoeudAB* racine = creerExempleAB();
  printf(
      "Création de l'arbre: "
      "https://commons.wikimedia.org/wiki/File:Binary_tree.svg\n\n");
  printTree(racine);
  printf("\n\nParcours en largeur : ");
  parcoursLargeur(racine);
  libererAB(&racine);
  return 0;
}