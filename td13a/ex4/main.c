#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../lib/liste.h"

void concatener (Noeud **tete1, Noeud *tete2){
    if (*tete1 == NULL) {
        *tete1 = tete2;
        return;
    }
    Noeud* courant = *tete1;
    while(courant->suivant != NULL){
        courant = courant->suivant;
    }
    courant->suivant = tete2;
}

void partition (Noeud *tete, Noeud **plusPetit, Noeud **egal, Noeud **plusGrand){
    if (tete == NULL) {
        *plusPetit = NULL;
        *egal = NULL;
        *plusGrand = NULL;
        return;
    }

    int pivot = tete->value;
    Noeud *courant = tete;

    *plusPetit = NULL;
    *egal = NULL;
    *plusGrand = NULL;

    while (courant != NULL) {
        Noeud* suivant = courant->suivant;
        courant->suivant = NULL;

        if (courant->value < pivot) {
            concatener(plusPetit, courant);
        } else if (courant->value == pivot) {
            concatener(egal, courant);
        } else {
            concatener(plusGrand, courant);
        }
        courant = suivant;
    }
}

void triRapideListe (Noeud **ptrTete){
    if (*ptrTete == NULL || (*ptrTete)->suivant == NULL) {
        return;
    }

    Noeud *plusPetit = NULL;
    Noeud *egal = NULL;
    Noeud *plusGrand = NULL;

    partition(*ptrTete, &plusPetit, &egal, &plusGrand);

    triRapideListe(&plusPetit);
    triRapideListe(&plusGrand);

    *ptrTete = NULL;
    concatener(ptrTete, plusPetit);
    concatener(ptrTete, egal);
    concatener(ptrTete, plusGrand);
}

int main(){
    srand(time(NULL));
    Noeud* tete = NULL;

    // Création d'une liste chaînée avec des values aléatoires
    for(int i = 0; i < 10; i++){
        Noeud* nouveau = nouveauNoeud(rand() % 100);
        nouveau->suivant = tete;
        tete = nouveau;
    }

    printf("Liste avant le tri rapide:\n");
    afficherListe(tete);

    triRapideListe(&tete);

    printf("Liste après le tri rapide:\n");
    afficherListe(tete);

    libererListe(tete);
    return 0;
}