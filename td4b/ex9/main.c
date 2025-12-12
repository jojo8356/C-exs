#include <stdbool.h>
#include <stdio.h>

#define TAILLE 3

int sommeLigne(int c[TAILLE][TAILLE], int n) {
  int somme = 0;
  for (int j = 0; j < TAILLE; j++) {
    somme += c[n][j];
  }
  return somme;
}

bool verifieLignes(int c[TAILLE][TAILLE]) {
  int ref = sommeLigne(c, 0);
  for (int i = 1; i < TAILLE; i++) {
    if (sommeLigne(c, i) != ref) return false;
  }
  return true;
}

int sommeColonne(int c[TAILLE][TAILLE], int n) {
  int somme = 0;
  for (int i = 0; i < TAILLE; i++) {
    somme += c[i][n];
  }
  return somme;
}

bool verifieColonnes(int c[TAILLE][TAILLE]) {
  int ref = sommeColonne(c, 0);
  for (int j = 1; j < TAILLE; j++) {
    if (sommeColonne(c, j) != ref) return false;
  }
  return true;
}

int sommeDiagonale1(int c[TAILLE][TAILLE]) {
  int somme = 0;
  for (int i = 0; i < TAILLE; i++) {
    somme += c[i][i];
  }
  return somme;
}

int sommeDiagonale2(int c[TAILLE][TAILLE]) {
  int somme = 0;
  for (int i = 0; i < TAILLE; i++) {
    somme += c[i][TAILLE - 1 - i];
  }
  return somme;
}

bool verifieCarreMagique(int c[TAILLE][TAILLE]) {
  int ref = sommeLigne(c, 0);
  for (int i = 0; i < TAILLE; i++) {
    if (sommeLigne(c, i) != ref) return false;
  }
  for (int j = 0; j < TAILLE; j++) {
    if (sommeColonne(c, j) != ref) return false;
  }
  if (sommeDiagonale1(c) != ref) return false;
  if (sommeDiagonale2(c) != ref) return false;

  return true;
}

int main() {
  int carre[TAILLE][TAILLE] = {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}};

  printf("Somme de la ligne 0: %d\n", sommeLigne(carre, 0));
  printf("Vérification des lignes: %s\n",
         verifieLignes(carre) ? "true" : "false");
  printf("Vérification des colonnes: %s\n",
         verifieColonnes(carre) ? "true" : "false");
  printf("Somme de la diagonale 1: %d\n", sommeDiagonale1(carre));
  printf("Somme de la diagonale 2: %d\n", sommeDiagonale2(carre));
  printf("Vérification du carré magique: %s\n",
         verifieCarreMagique(carre) ? "true" : "false");

  return 0;
}
