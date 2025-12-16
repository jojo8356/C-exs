#include <stdio.h>
#include <stdlib.h>

#include "../../lib/arbres.h"

int main() {
  NoeudAB* racine = creerExempleAB();
  afficherAB(racine);
  puts("\nParcours en profondeur itératif");
  printf("\nParcours préfixe:  ");
  parcourirPreItAB(racine);
  printf("\nParcours infixe:   ");
  parcourirInItAB(racine);
  printf("\nParcours postfixe: ");
  parcourirPostItAB(racine);
  // libérer la mémoire de l'arbre
  libererAB(&racine);
  return 0;
}