#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool FileEstVide(File* f) { return f->tete == NULL; }

void afficherFile(File* f) {
    if (FileEstVide(f)) {
        printf("File vide\n");
        return;
    }
    printf("File: tête = %d, queue = %d\n", 
           f->tete->valeur,
           f->queue->valeur);
}

/*
int defiler(File* file) {
  if (FileEstVide(file)) {
    return -1;
  }
  Noeud* tmp = file->tete;
  int valeur = tmp->valeur;
  file->tete = file->tete->suivant;
  if (file->tete == NULL) {
    file->queue = NULL;
  }
  free(tmp);
  return valeur;
}
*/

/*
int main() {
  puts("Initialise file");
  File file = {NULL, NULL};
  afficherFile(&file);
  for (int i = 1; i <= 3; i++) {
    printf("Enfile %d\n", i);
    enfiler(&file, i);
    afficherFile(&file);
  }
  while (!FileEstVide(&file)) {
    printf("Défile %d\n", defiler(&file));
    afficherFile(&file);
  }
  return 0;
}
*/

bool defiler(File *file, int *val){
    if (FileEstVide(file)) {
        return false;
    }
    Noeud* tmp = file->tete;
    *val = tmp->valeur;
    file->tete = file->tete->suivant;
    if (file->tete == NULL) {
        file->queue = NULL;
    }
    free(tmp);
    return true;
}

int main() {
  puts("Initialise file");
  File file = {NULL, NULL};
  afficherFile(&file);
  for (int i = 1; i <= 3; i++) {
    printf("Enfile %d\n", i);
    enfiler(&file, i);
    afficherFile(&file);
  }
  int val;
  while (defiler(&file, &val)) {
    printf("Défile %d\n", val);
    afficherFile(&file);
  }
  return 0;
}