#include "pilegen.h"

#include <stdlib.h>

PileGen* creerPileGen(void) {
  PileGen* p = malloc(sizeof(PileGen));
  if (p != NULL) {
    p->sommet = NULL;
  }
  return p;
}

void empilerGen(PileGen* p, void* val) {
  if (p == NULL) {
    return;
  }
  NoeudGen* nouveau = malloc(sizeof(NoeudGen));
  if (nouveau != NULL) {
    nouveau->valeur = val;
    nouveau->suivant = p->sommet;
    p->sommet = nouveau;
  }
}

void* depilerGen(PileGen* p) {
  if (p == NULL || p->sommet == NULL) {
    return NULL;
  }
  NoeudGen* temp = p->sommet;
  void* val = temp->valeur;
  p->sommet = temp->suivant;
  free(temp);
  return val;
}

int estVidePileGen(PileGen* p) {
  return (p == NULL || p->sommet == NULL);
}

void* sommetPileGen(PileGen* p) {
  if (p == NULL || p->sommet == NULL) {
    return NULL;
  }
  return p->sommet->valeur;
}

void detruirePileGen(PileGen* p) {
  if (p == NULL) {
    return;
  }
  while (p->sommet != NULL) {
    NoeudGen* temp = p->sommet;
    p->sommet = temp->suivant;
    free(temp);
  }
  free(p);
}
