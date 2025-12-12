#ifndef TABLISTES_H
#define TABLISTES_H

#include <stdio.h>

#define TAILLE_TAB 256

typedef struct {
  int tab[TAILLE_TAB];
  int taille;
} TabListe;

void afficherTabListe(TabListe* t);
void ajouterElt(TabListe* t, int val);
void retirerElt(TabListe* t);
void insererElt(TabListe* t, int indice, int val);
void supprimerElt(TabListe* t, int indice);

#endif
