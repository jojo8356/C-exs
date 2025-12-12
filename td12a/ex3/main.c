#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;

typedef struct {
  Noeud* tete;
  Noeud* queue;
} File;

Noeud* init(int valeur) {
  Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
  nouveau->valeur = valeur;
  nouveau->suivant = NULL;
  return nouveau;
}

void enfiler(File* file, int valeur) {
  Noeud* nouveau = init(valeur);
  if (file->queue == NULL) {
    file->tete = nouveau;
  } else {
    file->queue->suivant = nouveau;
  }
  file->queue = nouveau;
}