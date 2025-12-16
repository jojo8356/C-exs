#include "liste.h"

#include <stdio.h>
#include <stdlib.h>

Noeud* nouveauNoeud(int value) {
  Noeud* n = malloc(sizeof(Noeud));
  n->value = value;
  n->suivant = NULL;
  return n;
}

Noeud* creerListeDunTab(int tab[], int n) {
  if (n == 0) return NULL;
  Noeud* tete = nouveauNoeud(tab[0]);
  Noeud* current = tete;
  for (int i = 1; i < n; i++) {
    current->suivant = nouveauNoeud(tab[i]);
    current = current->suivant;
  }
  return tete;
}

int lenListe(Noeud* l) {
  int compteur = 0;
  while (l) {
    compteur++;
    l = l->suivant;
  }
  return compteur;
}

void afficherListe(Noeud* l) {
  while (l) {
    printf("%d -> ", l->value);
    l = l->suivant;
  }
  printf("NULL\n");
}

void libererListe(Noeud* l) {
  while (l) {
    Noeud* tmp = l;
    l = l->suivant;
    free(tmp);
  }
}

bool estTrieeListe(Noeud* l) {
  while (l && l->suivant) {
    if (l->value > l->suivant->value) return false;
    l = l->suivant;
  }
  return true;
}