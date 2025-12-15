#include <stdio.h>

#include "../../lib/arbres.h"
#include "../../lib/tableaux.h"

int main() {
  int tab[] = {2, 7, 5, 2, 6, -1, 9, -1, -1, 5, 11, -1, -1, 4, -1};
  int taille = sizeof(tab) / sizeof(int);
  puts("Arbre d'exemple");
  afficherTab(tab, taille);
  puts("Parcours en largeur");
  parcoursLargeurTabAB(tab, taille);
  printf("Taille: %d\n", calculerTailleTabAB(tab, taille));
  printf("Hauteur: %d\n", calculerHauteurTabAB(tab, taille));
  printf("Nombre de feuilles: %d\n", compterFeuillesTabAB(tab, taille));
  printf("Est parfait: %d\n", estParfaitTabAB(tab, taille));

  puts("\nArbre parfait de hauteur 2");
  int parfait[] = {0, 1, 2, 3, 4, 5, 6};
  int tailleParfait = sizeof(parfait) / sizeof(int);
  afficherTab(parfait, tailleParfait);
  puts("Parcours en largeur");
  parcoursLargeurTabAB(parfait, tailleParfait);
  printf("Taille: %d\n", calculerTailleTabAB(parfait, tailleParfait));
  printf("Hauteur: %d\n", calculerHauteurTabAB(parfait, tailleParfait));
  printf("Nombre de feuilles: %d\n",
         compterFeuillesTabAB(parfait, tailleParfait));
  printf("Est parfait: %d\n", estParfaitTabAB(parfait, tailleParfait));

  puts("\nTests de validité");
  afficherTab(tab, taille);
  printf("Valide ? -> %d\n", verifierTabAB(tab, taille));
  afficherTab(parfait, tailleParfait);
  printf("Valide ? -> %d\n", verifierTabAB(parfait, tailleParfait));
  int tabSansRacine[] = {-1, 2, 3};
  int tailleSansRacine = sizeof(tabSansRacine) / sizeof(int);
  afficherTab(tabSansRacine, tailleSansRacine);
  printf("Valide ? -> %d\n", verifierTabAB(tabSansRacine, tailleSansRacine));
  int tabInvalide[] = {2, -1, 5, -1, 2, 3, -1};
  int tailleInvalide = sizeof(tabInvalide) / sizeof(int);
  afficherTab(tabInvalide, tailleInvalide);
  printf("Valide ? -> %d\n", verifierTabAB(tabInvalide, tailleInvalide));

  return 0;
}