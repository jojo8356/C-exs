#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;

int main() {
  Noeud* n1 = (Noeud *)malloc(sizeof(Noeud));
  Noeud* n2 = (Noeud *)malloc(sizeof(Noeud));
  Noeud* n3 = (Noeud *)malloc(sizeof(Noeud));

  Noeud* tete = n1;

  n1->valeur = 12;
  n1->suivant = n2;
  printf("%d -> ", n1->valeur);
  n2->valeur = 99;
  printf("%d -> ", n2->valeur);
  n2->suivant = n3;
  printf("%d -> ", n3->valeur);
  n3->valeur = 37;
  n3->suivant = NULL;
  printf("NULL\n"); 

  free(tete);
  free(n2);
  free(n3);
}

/* tete | suivant
   -> 12 | suivant
   -> 99 | suivant
   -> 37 | suivant
   -> NULL
*/