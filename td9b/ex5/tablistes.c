#include "tablistes.h"

void afficherTabListe(TabListe* t) {
  printf("[");
  for (int i = 0; i < t->taille; i++) {
    printf("%d", t->tab[i]);
    if (i < t->taille - 1) printf(", ");
  }
  printf("]\n");
}

void ajouterElt(TabListe* t, int val) {
  if (t->taille >= TAILLE_TAB) {
    printf("Tableau plein, impossible d'ajouter.\n");
    return;
  }
  t->tab[t->taille++] = val;
}

void retirerElt(TabListe* t) {
  if (t->taille == 0) {
    printf("Tableau vide, rien à retirer.\n");
    return;
  }
  t->taille--;
}

void insererElt(TabListe* t, int indice, int val) {
  if (t->taille >= TAILLE_TAB) {
    printf("Tableau plein, insertion impossible.\n");
    return;
  }
  if (indice < 0 || indice > t->taille) {
    printf("Indice invalide.\n");
    return;
  }

  for (int i = t->taille; i > indice; i--) {
    t->tab[i] = t->tab[i - 1];
  }
  t->tab[indice] = val;
  t->taille++;
}

void supprimerElt(TabListe* t, int indice) {
  if (indice < 0 || indice >= t->taille) {
    printf("Indice invalide.\n");
    return;
  }

  for (int i = indice; i < t->taille - 1; i++) {
    t->tab[i] = t->tab[i + 1];
  }
  t->taille--;
}
