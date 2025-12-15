#include <stdio.h>

#include "../../lib/arbres.h"

int main() {
  NoeudAB* racine = creerExempleAB();
  afficherAB(racine);

  printf("Hauteur de l'arbre:     %3d\n", calculerHauteurAB(racine));
  printf("Taille de l'arbre:      %3d\n", calculerTailleAB(racine));
  printf("Nb de feuilles l'arbre: %3d\n", compterFeuillesAB(racine));
  printf("Arbre parfait:          %3s\n", estParfaitAB(racine) ? "Oui" : "Non");

  // libérer la mémoire de l'arbre
  libererAB(&racine);
}