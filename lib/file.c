#include "file.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

File* creerFile() {
  File* file = malloc(sizeof(File));
  file->debut = NULL;
  file->fin = NULL;
  return file;
}

bool FileEstVide(File* file) { return file->debut == NULL; }

void enfiler(File* file, int valeur) {
  Noeud* nouveauNoeud = malloc(sizeof(Noeud));
  nouveauNoeud->value = valeur;
  nouveauNoeud->suivant = NULL;
  if (FileEstVide(file)) {
    file->debut = nouveauNoeud;
  } else {
    file->fin->suivant = nouveauNoeud;
  }
  file->fin = nouveauNoeud;
}

int defiler(File* file) {
  if (FileEstVide(file)) {
    fprintf(stderr, "Erreur: tentative de défilement d'une file vide.\n");
    exit(EXIT_FAILURE);
  }
  Noeud* noeudASupprimer = file->debut;
  int valeur = noeudASupprimer->value;
  file->debut = file->debut->suivant;
  if (file->debut == NULL) {
    file->fin = NULL;
  }
  free(noeudASupprimer);
  return valeur;
}