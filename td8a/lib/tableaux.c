/**
 * @file tableaux.c
 * @brief Fonctions utilitaires pour la manipulation de tableaux d'entiers.
 *
 * Contient des fonctions pour vérifier, afficher, calculer somme, moyenne,
 * maximum, minimum, rechercher une valeur et compter les occurrences dans un
 * tableau.
 */

#include "tableaux.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Vérifie qu'un tableau a au moins un élément.
 *
 * @param tab Pointeur vers le tableau d'entiers.
 * @param taille Taille du tableau.
 *
 * Si le tableau est vide ou la taille est <= 0, la fonction affiche
 * un message d'erreur et termine le programme.
 */
int verif_tab(int* tab, int taille) {
  if (taille <= 0) {
    fprintf(stderr, "Il faut que le tableau ait au moins 1 élément");
    exit(1);
  }
}

/**
 * @brief Affiche le contenu d'un tableau d'entiers.
 *
 * @param tab Pointeur vers le tableau.
 * @param taille Taille du tableau.
 *
 * Appelle verif_tab pour vérifier la validité du tableau avant l'affichage.
 * Les éléments sont affichés sous la forme {a, b, c, ...}.
 */
void afficherTab(int* tab, int taille) {
  printf("{");
  for (int i = 0; i < taille; i++) {
    printf("%d", tab[i]);
    if (i < taille - 1) printf(", ");
  }
  printf("}\n");
}

/**
 * @brief Calcule la somme des éléments d'un tableau.
 *
 * @param tab Tableau d'entiers.
 * @param taille Taille du tableau.
 * @return La somme des éléments.
 */
int sommeTab(int tab[], int taille) {
  verif_tab(tab, taille);
  int somme = 0;
  for (int i = 0; i < taille; i++) {
    somme += tab[i];
  }
  return somme;
}

/**
 * @brief Calcule la moyenne des éléments d'un tableau.
 *
 * @param tab Tableau d'entiers.
 * @param taille Taille du tableau.
 * @return La moyenne des éléments.
 */
double moyenneTab(int tab[], int taille) {
  verif_tab(tab, taille);
  double somme = 0;
  for (int i = 0; i < taille; i++) {
    somme += tab[i];
  }
  return somme / (double)taille;
}

/**
 * @brief Retourne la valeur maximale d'un tableau.
 *
 * @param tab Tableau d'entiers.
 * @param taille Taille du tableau.
 * @return La valeur maximale.
 */
int maxTab(int tab[], int taille) {
  verif_tab(tab, taille);
  int max = tab[0];
  for (int i = 0; i < taille; i++) {
    if (tab[i] > max) max = tab[i];
  }
  return max;
}

/**
 * @brief Retourne la valeur minimale d'un tableau.
 *
 * @param tab Tableau d'entiers.
 * @param taille Taille du tableau.
 * @return La valeur minimale.
 */
int minTab(int tab[], int taille) {
  verif_tab(tab, taille);
  int min = tab[0];
  for (int i = 0; i < taille; i++) {
    if (tab[i] < min) min = tab[i];
  }
  return min;
}

/**
 * @brief Compte le nombre d'occurrences d'une valeur dans un tableau.
 *
 * @param tab Tableau d'entiers.
 * @param taille Taille du tableau.
 * @param valeur Valeur à compter.
 * @return Nombre d'occurrences de la valeur.
 */
int compterOccurrences(int tab[], int taille, int valeur) {
  verif_tab(tab, taille);
  int nb = 0;
  for (int i = 0; i < taille; i++) {
    if (tab[i] == valeur) nb++;
  }
  return nb;
}

/**
 * @brief Inverse l'ordre des éléments d'un tableau.
 *
 * @param tab Tableau d'entiers à inverser.
 * @param taille Taille du tableau.
 */
void inverserTab(int tab[], int taille) {
  verif_tab(tab, taille);
  for (int i = 0; i < taille; i++) {
    tab[i] = tab[taille - i - 1];
  }
}

/**
 * @brief Copie le contenu d'un tableau source vers un tableau destination.
 *
 * @param source Tableau source.
 * @param dest Tableau destination.
 * @param taille Taille des tableaux.
 */
void copierTab(int source[], int dest[], int taille) {
  verif_tab(source, taille);
  for (int i = 0; i < taille; i++) {
    dest[i] = source[i];
  }
}

/**
 * @brief Vérifie si un tableau est trié en ordre croissant.
 *
 * @param tab Tableau d'entiers.
 * @param taille Taille du tableau.
 * @return true si le tableau est croissant, false sinon.
 */
bool estCroissantTab(int tab[], int taille) {
  for (int i = 0; i < taille - 1; i++) {
    if (tab[i] > tab[i + 1]) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Vérifie si un tableau est trié en ordre décroissant.
 *
 * @param tab Tableau d'entiers.
 * @param taille Taille du tableau.
 * @return true si le tableau est décroissant, false sinon.
 */
bool estDecroissant(int tab[], int taille) {
  verif_tab(tab, taille);
  for (int i = 0; i < taille - 1; i++) {
    if (tab[i] < tab[i + 1]) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Fusionne deux tableaux dans un tableau résultat.
 *
 * @param tab1 Premier tableau.
 * @param taille1 Taille du premier tableau.
 * @param tab2 Deuxième tableau.
 * @param taille2 Taille du deuxième tableau.
 * @param resultat Tableau pour stocker le résultat (taille >= taille1 +
 * taille2).
 */
void fusionnerTableaux(int tab1[], int taille1, int tab2[], int taille2,
                       int resultat[]) {
  copierTab(tab1, resultat, taille1);
  for (int i = 0; i < taille2; i++) {
    resultat[i + taille1] = tab2[i];
  }
}

/**
 * @brief Extrait un sous-tableau d'un tableau source.
 *
 * @param source Tableau source.
 * @param debut Index de début (inclus).
 * @param fin Index de fin (exclus).
 * @param dest Tableau destination pour stocker le sous-tableau.
 */
void extraireSousTab(int source[], int debut, int fin, int dest[]) {
  for (int i = debut; i < fin; i++) {
    dest[i - debut] = source[i];
  }
}

/**
 * @brief Échange deux éléments dans un tableau.
 *
 * @param tab Le tableau d'entiers.
 * @param i Index 1
 * @param j Index 2
 */
void swap_tab(int tab[], int i, int j) {
  int tmp = tab[i];
  tab[i] = tab[j];
  tab[j] = tmp;
}

/**
 * @brief Tri un tableau en utilisant l'algorithme de tri par insertion.
 *
 * @param tab Le tableau d'entiers.
 * @param taille La taille du tableau.
 */
void triInsertionTab(int tab[], int taille) {
  for (int i = 1; i < taille; i++) {
    int x = tab[i];
    int j = i;
    while (j > 0 && tab[j - 1] > x) {
      tab[j] = tab[j - 1];
      j--;
    }
    tab[j] = x;
  }
}

/**
 * @brief Tri un tableau en utilisant l'algorithme de tri à bulles optimisé.
 *
 * @param tab Le tableau d'entiers.
 * @param taille La taille du tableau.
 */
void triABullesOptimiseTab(int tab[], int taille) {
  for (int i = taille - 1; i > 0; i--) {
    int tableauTrie = 1;
    for (int j = 0; j <= i; j++) {
      if (tab[j] > tab[j + 1]) {
        swap_tab(tab, j, j + 1);
        tableauTrie = 0;
      }
    }
    if (tableauTrie) return;
  }
}

/**
 * @brief Tri un tableau en utilisant l'algorithme de tri à bulles.
 *
 * @param tab Le tableau d'entiers.
 * @param taille La taille du tableau.
 */
// Tri par échange voisin au fur et à mesure de la boucle
void triABullesTab(int tab[], int taille) {
  for (int i = taille - 1; i > 0; i--)
    for (int j = 0; j < i; j++)
      if (tab[j] > tab[j + 1]) {
        swap_tab(tab, j, j + 1);
      }
}

/**
 * @brief Tri un tableau en utilisant l'algorithme de tri par sélection.
 *
 * @param tab Le tableau d'entiers.
 * @param taille La taille du tableau.
 */
// Tri par minimum
void triSelectionTab(int tab[], int taille) {
  for (int i = 0; i < taille - 1; i++) {
    // minimum entre i et taille-1
    int min = i;

    // get minimum
    for (int j = i + 1; j < taille; j++) {
      if (tab[j] < tab[min]) min = j;
    }

    // swap min avec i (gauche)
    if (min != i) swap_tab(tab, i, min);
  }
}

/**
 * @brief Fusionne deux sous-tableaux triés en un seul tableau trié.
 *
 * @param tab Le tableau d'entiers.
 * @param gauche Index de début du premier sous-tableau.
 * @param milieu Index milieu (droite + gauche) / 2.
 * @param droite Index de fin du second sous-tableau.
 */
// fusion de 2 tableaux triés [gauche..milieu] et [milieu+1..droite]
void fusionnerTableauxTri(int tab1[], int taille1, int tab2[], int taille2,
                          int resultat[]) {
  int i = 0, j = 0, k = 0;
  while (i < taille1 && j < taille2) {
    if (tab1[i] <= tab2[j])
      resultat[k++] = tab1[i++];
    else
      resultat[k++] = tab2[j++];
  }
  while (i < taille1) resultat[k++] = tab1[i++];
  while (j < taille2) resultat[k++] = tab2[j++];
}

void fusionnerTriTab(int tab[], int gauche, int milieu, int droite) {
  int n1 = milieu - gauche + 1;
  int n2 = droite - milieu;

  int temp1[n1];
  int temp2[n2];

  extraireSousTab(tab, gauche, milieu + 1, temp1);  // milieu inclus
  extraireSousTab(tab, milieu + 1, droite + 1, temp2);

  fusionnerTableauxTri(temp1, n1, temp2, n2, tab + gauche);
}

/**
 * @brief Tri un tableau en utilisant l'algorithme de tri par fusion itératif.
 *
 * @param tableau Le tableau d'entiers.
 * @param taille La taille du tableau.
 */
void triFusionIteratifTab(int tableau[], int taille) {
  // On part de tableaux de taille 1 qui sont déjà triés
  int pas = 1;

  // On double la taille des sous-tableaux tant qu'on a pas fusionné tout le
  // tableau
  while (pas < taille) {
    // On parcourt le tableau par pas de 2*pas
    for (int i = 0; i < taille - pas; i += 2 * pas) {
      int gauche = i;
      int milieu = i + pas - 1;
      int droite;

      // Calcul de l'indice de fin du second sous-tableau
      // Il faut s'assurer qu'on ne sorte pas du tableau
      if (i + 2 * pas < taille) {
        droite = i + 2 * pas - 1;
      } else {
        // le deuxième tableau s'arrête à la fin du tableau
        droite = taille - 1;
      }

      // Fusion des sous-tableaux [gauche..milieu] et [milieu+1..droite]
      fusionnerTriTab(tableau, gauche, milieu, droite);
    }
    pas *= 2;
  }
}

int rechercheDichoRec(int tab[], int gauche, int droite, int valeur) {
  if (gauche > droite) return -1;

  int milieu = (gauche + droite) / 2;

  if (tab[milieu] == valeur)
    return milieu;
  else if (tab[milieu] > valeur)
    return rechercheDichoRec(tab, gauche, milieu - 1, valeur);
  else
    return rechercheDichoRec(tab, milieu + 1, droite, valeur);
}