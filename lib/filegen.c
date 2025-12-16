#include "filegen.h"

#include <stdlib.h>

#include "filegen.h"

FileGen* creerFileGen(void) {
  FileGen* f = malloc(sizeof(FileGen));
  if (f != NULL) {
    f->tete = NULL;
    f->queue = NULL;
  }
  return f;
}

void enfilerGen(FileGen* f, void* val) {
  if (f == NULL) {
    return;
  }
  NoeudFileGen* nouveau = malloc(sizeof(NoeudFileGen));
  if (nouveau != NULL) {
    nouveau->valeur = val;
    nouveau->suivant = NULL;
    if (f->queue == NULL) {
      f->tete = nouveau;
      f->queue = nouveau;
    } else {
      f->queue->suivant = nouveau;
      f->queue = nouveau;
    }
  }
}

void* defilerGen(FileGen* f) {
  if (f == NULL || f->tete == NULL) {
    return NULL;
  }
  NoeudFileGen* temp = f->tete;
  void* val = temp->valeur;
  f->tete = temp->suivant;
  if (f->tete == NULL) {
    f->queue = NULL;
  }
  free(temp);
  return val;
}

int estVideFileGen(FileGen* f) { return (f == NULL || f->tete == NULL); }

void* teteFileGen(FileGen* f) {
  if (f == NULL || f->tete == NULL) {
    return NULL;
  }
  return f->tete->valeur;
}

void detruireFileGen(FileGen* f) {
  if (f == NULL) {
    return;
  }
  while (f->tete != NULL) {
    NoeudFileGen* temp = f->tete;
    f->tete = temp->suivant;
    free(temp);
  }
  free(f);
}

int lenFileGen(FileGen* f) {
  if (f == NULL) return 0;

  int count = 0;
  NoeudFileGen* courant = f->tete;
  while (courant != NULL) {
    count++;
    courant = courant->suivant;
  }
  return count;
}

void** fileGenEnTab(FileGen* f, int* taille) {
  if (f == NULL || f->tete == NULL) {
    *taille = 0;
    return NULL;
  }

  int len = lenFileGen(f);

  void** tab = malloc(len * sizeof(void*));
  if (!tab) {
    *taille = 0;
    return NULL;
  }

  NoeudFileGen* courant = f->tete;
  for (int i = 0; i < len; i++) {
    tab[i] = courant->valeur;
    courant = courant->suivant;
  }

  *taille = len;
  return tab;
}