#include <stdio.h>
#include <stdlib.h>

#include "../../lib/arbres.h"

int main() {
  NoeudAB* racine = creerExempleAB();
  afficherAB(racine);
  printf("\nParcours en largeur : ");
  parcourirLargeurAB(racine);
  puts("");

  // libérer la mémoire de l'arbre
  libererAB(&racine);
  return 0;
}