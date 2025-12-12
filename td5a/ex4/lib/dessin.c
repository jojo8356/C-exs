#include "dessin.h"

#include <stdio.h>

void affiche_etoile() { printf("*"); }

void affiche_espace() { printf(" "); }

void nouvelle_ligne() { printf("\n"); }

void affiche_nbetoiles(int nb) {
  if (nb >= 1 && nb <= 5) {
    for (int i = 0; i < nb; i++) {
      affiche_etoile();
    }
  }
}

void affiche_nbespaces(int nb) {
  if (nb >= 1 && nb <= 5) {
    for (int i = 0; i < nb; i++) {
      affiche_espace();
    }
  }
}

void carre() {
  affiche_nbetoiles(4);
  nouvelle_ligne();
  for (int i = 0; i < 2; i++) {
    affiche_etoile();
    affiche_nbespaces(2);
    affiche_etoile();
    nouvelle_ligne();
  }
  affiche_nbetoiles(4);
  nouvelle_ligne();
}

void carre_custom(int nb) {
  affiche_nbetoiles(nb);
  nouvelle_ligne();
  for (int i = 0; i < 2; i++) {
    affiche_etoile();
    affiche_nbespaces(nb - 2);
    affiche_etoile();
    nouvelle_ligne();
  }
  affiche_nbetoiles(nb);
  nouvelle_ligne();
}

void triangle_bas() {
  affiche_nbetoiles(4);
  nouvelle_ligne();
  affiche_etoile();
  affiche_espace();
  affiche_etoile();
  nouvelle_ligne();
  affiche_nbetoiles(2);
  nouvelle_ligne();
  affiche_etoile();
  nouvelle_ligne();
}

void triangle_haut() {
  affiche_etoile();
  nouvelle_ligne();
  affiche_nbetoiles(2);
  nouvelle_ligne();
  affiche_etoile();
  affiche_espace();
  affiche_etoile();
  nouvelle_ligne();
  affiche_nbetoiles(4);
  nouvelle_ligne();
}

void triangle_isocele_bas() {
  affiche_nbespaces(2);
  affiche_etoile();
  affiche_nbespaces(2);
  nouvelle_ligne();
  affiche_espace();
  affiche_etoile();
  affiche_espace();
  affiche_etoile();
  affiche_espace();
  nouvelle_ligne();
  affiche_nbetoiles(5);
  nouvelle_ligne();
}

void triangle_isocele_haut() {
  affiche_nbetoiles(5);
  nouvelle_ligne();
  affiche_espace();
  affiche_etoile();
  affiche_espace();
  affiche_etoile();
  affiche_espace();
  nouvelle_ligne();
  affiche_nbespaces(2);
  affiche_etoile();
  affiche_nbespaces(2);
  nouvelle_ligne();
}