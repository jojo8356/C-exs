#include <stdio.h>
#include <stdlib.h>
#include "../lib/tableaux.h"

void rechercheDichotomique(int tab[], int n, int x) {
  int debut = 0;
  int fin = n - 1;
  int i = 0;
  while (debut <= fin) {
    int milieu = (debut + fin) / 2;
    if (tab[milieu] == x) {
      printf("Recherche dichotomique: l'élément %d a été trouvé en %d tours\n", x, i + 1);
      return;
    } else if (tab[milieu] < x) {
      debut = milieu + 1;
    } else {
      fin = milieu - 1;
    }
    i++;
  }
  printf("Recherche dichotomique: l'élément %d n'a pas été trouvé en %d tours\n", x, i);
}

void rechercherValeur(int tab[], int taille, int valeur) {
  verif_tab(tab, taille);
  for (int i = 0; i < taille; i++) {
    if (tab[i] == valeur){
        printf("Recherche séquentielle: l'élément %d a été trouvé en %d tours\n", valeur, i+1);
        return;
    }
  }
  printf("Recherche séquentielle: l'élément %d n'a pas été trouvé sur %d tours\n", valeur, taille);
}

int main(){
    int valeurs[3] = {0, 499999, -1};
    int taille = 1000000;
    int tableau[1000000];
    for(int i=0; i<taille; i++){
        tableau[i] = i;
    }
    for(int i=0; i<3; i++){
        rechercherValeur(tableau, taille, valeurs[i]);
        rechercheDichotomique(tableau, taille, valeurs[i]);
    }
}