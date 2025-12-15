#include <stdio.h>

#include "../../lib/arbres.h"

int main() {
  NoeudAB* racine = creerExempleAB();
  afficherAB(racine);

  bool inverse = false;
  puts("Parcours en profondeur dans l'ordre\n---");

  printf("\tPRE: ");
  parcourirProfondeurAB(racine, PRE, inverse);
  printf("\n\tIN: ");
  parcourirProfondeurAB(racine, IN, inverse);
  printf("\n\tPOST: ");
  parcourirProfondeurAB(racine, POST, inverse);

  inverse = true;
  puts("\n\nParcours en profondeur inversé\n---");

  printf("\tPRE: ");
  parcourirProfondeurAB(racine, PRE, inverse);
  printf("\n\tIN: ");
  parcourirProfondeurAB(racine, IN, inverse);
  printf("\n\tPOST: ");
  parcourirProfondeurAB(racine, POST, inverse);
  puts("");

  // libérer la mémoire de l'arbre
  libererAB(&racine);
  return 0;
}