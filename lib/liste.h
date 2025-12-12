#pragma once

#include <stdbool.h>

typedef struct Noeud {
  int value;
  struct Noeud* suivant;
} Noeud;

Noeud* nouveauNoeud(int value);
Noeud* creerListeDunTab(int tab[], int n);
void afficherListe(Noeud* l);
void libererListe(Noeud* l);
bool estTrieeListe(Noeud* l);