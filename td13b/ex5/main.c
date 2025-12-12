#include <stdio.h>
#include <limits.h>
#include "../../lib/tableaux.h"
#include <stdlib.h>

int renduMonnaieDynamique(int pieces[], int nbPiece, int montant) {
    int *rendus = malloc((montant + 1) * sizeof(int));
    if (rendus == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return -1;
    }

    rendus[0] = 0;
    for (int i = 1; i <= montant; i++) {
        rendus[i] = INT_MAX;
    }

    for (int m = 1; m <= montant; m++) {
        for (int p = 0; p < nbPiece; p++) {
            int piece = pieces[p];

            if (piece <= m && rendus[m - piece] != INT_MAX) {
                int tentative = rendus[m - piece] + 1;
                if (tentative < rendus[m]) {
                    rendus[m] = tentative;
                }
            }
        }
    }

    printf("Tableau rendus : ");
    afficherTab(rendus, montant + 1);
    int result = rendus[montant];
    free(rendus);

    return result;
}

int main() {
  int valeurs[] = {1, 7, 23};
  int nbPiece = sizeof(valeurs) / sizeof(valeurs[0]);

  printf("Tableau des pieces: ");
  afficherTab(valeurs, nbPiece);

  int montant = 28;
  printf("Rendu dynamique du montant %d€\n", montant);

  int nbRendu = renduMonnaieDynamique(valeurs, nbPiece, montant);

  if (nbRendu == INT_MAX) {
    printf(
        "Il est impossible de rendre ce montant avec les pièces "
        "disponibles.\n");
  } else {
    printf("Nombre minimal de pièces/billets nécessaires : %d\n", nbRendu);
  }

  return 0;
}
