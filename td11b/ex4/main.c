#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;
void afficherListe(Noeud* tete) {
  Noeud* courant = tete;
  while (courant != NULL) {
    printf("%d -> ", courant->valeur);
    courant = courant->suivant;
  }
  printf("NULL\n");
}
unsigned longueurListe(Noeud* tete) {
  int len = 0;
  Noeud* courant = tete;
  while (courant != NULL) {
    courant = courant->suivant;
    len++;
  }
  return len;
}
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

int main() {
  srand(time(NULL));
  int nbAInserer;
  Noeud* tete = NULL;

  puts("Insertion de 7 nombres aléatoires entre 0 et 9");
  for (int i = 0; i < 7; i++) {
    nbAInserer = rand() % 10;
    ajouterFin(&tete, nbAInserer);
    printf("Ajout de %d\n", nbAInserer);
    afficherListe(tete);
  }
  puts("Libération de la mémoire");
  libererListe(tete);
  return 0;
}