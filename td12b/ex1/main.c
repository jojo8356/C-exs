#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;
// La tete est pointé vers la queue
// queue->suivant est la tete

bool estVide(Noeud* queue) { return queue == NULL; }

void afficherFile(Noeud* queue){
    if (estVide(queue)) {
        printf("File vide: queue @%p\n", queue);
        return;
    }
    printf("File: queue = %d\n", 
           queue->valeur);
}

void enfiler(Noeud** queue, int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    if (estVide(*queue)) {
        nouveau->suivant = nouveau;
    } else {
        nouveau->suivant = (*queue)->suivant;
        (*queue)->suivant = nouveau;
    }
    *queue = nouveau;
}

int defiler(Noeud** queue) {
    if (estVide(*queue)) {
        fprintf(stderr, "Erreur: tentative de défilement d'une file vide\n");
        exit(1);
    }
    Noeud* tete = (*queue)->suivant;
    int valeur = tete->valeur;
    if (tete == *queue) {
        *queue = NULL; // vide file
    } else {
        (*queue)->suivant = tete->suivant; // sauter la tête
    }
    free(tete);
    return valeur;
}

/*
bool defiler(Noeud** queue, int* valeur) {
    if (estVide(*queue)) {
        return false;
    }
    Noeud* tete = (*queue)->suivant;
    *valeur = tete->valeur;
    if (tete == *queue) {
        *queue = NULL;
    } else {
        (*queue)->suivant = tete->suivant;
    }
    free(tete);
    return true;
}
*/

int main() {
  Noeud* file = NULL;
  puts("# Etat initial");

  printf("File vide ? %s\n", estVide(file) ? "vrai" : "faux");
  afficherFile(file);

  puts("\n# Début des enfilages");
  for (int i = 0; i < 3; i++) {
    printf("Enfile %d\n", i + 1);
    enfiler(&file, i + 1);
    afficherFile(file);
  }

  printf("File vide ? %s\n", estVide(file) ? "vrai" : "faux");

  puts("\n# Début des défilements");
  while (!estVide(file)) {
    printf("Défile %d\n", defiler(&file));
    afficherFile(file);
  }

  puts("\n# Etat final");

  printf("File vide ? %s\n", estVide(file) ? "vrai" : "faux");
}