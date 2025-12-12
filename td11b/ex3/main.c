#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;

Noeud* creerListeDunTab(int tab[], int taille) {
    if (taille <= 0) return NULL;

    Noeud* tete = NULL;
    Noeud* courant = NULL;

    for (int i = 0; i < taille; i++) {
        Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
        nouveauNoeud->valeur = tab[i];
        nouveauNoeud->suivant = NULL;

        if (tete == NULL) {
            tete = nouveauNoeud;
            courant = tete;
        } else {
            courant->suivant = nouveauNoeud;
            courant = nouveauNoeud;
        }
    }
    return tete;
}

int longueurListe(Noeud* tete) {
    int longueur = 0;
    Noeud* courant = tete;
    while (courant != NULL) {
        longueur++;
        courant = courant->suivant;
    }
    return longueur;
}

void libererListe(Noeud* tete) {
    Noeud* courant = tete;
    while (courant != NULL) {
        Noeud* temp = courant;
        courant = courant->suivant;
        free(temp);
    }
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
    int tab[] = {12, 99, 37};
    Noeud* tete = creerListeDunTab(tab, 3);
    afficherListe(tete);
    int len = longueurListe(tete);
    printf("Longueur de la liste: %d\n", len);
    libererListe(tete);
    return 0;
}