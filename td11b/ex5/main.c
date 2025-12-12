#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;

typedef struct Pile {
  Noeud* sommet;
} Pile;

Noeud* initNoeud(int valeur) {
  Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
  nouveauNoeud->valeur = valeur;
  nouveauNoeud->suivant = NULL;
  return nouveauNoeud;
}

void ajouterFin(Noeud** tete, int nouvelleValeur) {
  if (tete == NULL) return;

  Noeud* nouveauNoeud = initNoeud(nouvelleValeur);
  if (*tete == NULL) {
    *tete = nouveauNoeud;
    return;
  }

  Noeud* courant = *tete;
  while (courant->suivant != NULL) {
    courant = courant->suivant;
  }
  courant->suivant = nouveauNoeud;
}

void libererListe(Noeud* tete) {
  Noeud* courant = tete;
  while (courant != NULL) {
    Noeud* temp = courant;
    courant = courant->suivant;
    free(temp);
  }
}

int estVide(Pile* p) { return p->sommet == NULL; }
void empiler(Pile* p, int valeur) {
  Noeud* nouveau = malloc(sizeof(Noeud));
  if (!nouveau) {
    fprintf(stderr, "Erreur d'allocation de mémoire\n");
    exit(1);
  }

  nouveau->valeur = valeur;
  nouveau->suivant = p->sommet;
  p->sommet = nouveau;
}

int depiler(Pile* p) {
  if (estVide(p)) {
    return -1;
  }

  Noeud* temp = p->sommet;
  int ret = temp->valeur;

  p->sommet = temp->suivant;
  free(temp);

  return ret;
}

Pile* initPile() {
  Pile* p = malloc(sizeof(Pile));
  p->sommet = NULL;
  return p;
}

void deleteByIndex(Noeud** tete, int index) {
  if (tete == NULL || *tete == NULL || index < 0) return;

  Noeud* courant = *tete;
  if (index == 0) {
    *tete = courant->suivant;
    free(courant);
    return;
  }

  int i = 0;
  while (courant != NULL && i < index - 1) {
    courant = courant->suivant;
    i++;
  }

  if (courant == NULL || courant->suivant == NULL) return;

  Noeud* temp = courant->suivant;
  courant->suivant = temp->suivant;
  free(temp);
}

void afficherListe(Noeud* tete) {
    Noeud* courant = tete;
    printf("Liste: ");
    while (courant != NULL) {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}


int main(){
    Noeud* tete = initNoeud(1);
    Pile* indices = initPile();

    // generate list with duplicates
    int i = 0;
    for (i = 2; i <= 4; i++) {
        for (int j = 0; j < i; j++) {
            ajouterFin(&tete, i);
        }
    }

    // get target from user
    int target;
    printf("Les elements de la liste:\n");
    afficherListe(tete);
    printf("Entrez l'entier a supprimer:\n");
    scanf("%d", &target);

    // get indices of target occurrences
    Noeud* courant = tete;
    i = 0;
    while (courant != NULL) {
        int tmp = courant->valeur;
        if (tmp == target) {
            empiler(indices, i);
        }
        courant = courant->suivant;
        i++;
    }
    
    // delete target occurrences from list from indexes
    int index = depiler(indices);
    while (index != -1) {
        deleteByIndex(&tete, index);
        index = depiler(indices);
    }

    afficherListe(tete);
    libererListe(tete);
    return 0;
}