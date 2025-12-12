#include <stdio.h>
#include <stdlib.h>

typedef struct NoeudChar {
  char valeur;
  struct NoeudChar* suivant;
} NoeudChar;

typedef struct {
  NoeudChar* sommet;
} PileChar;

void empilerChar(PileChar* p, char valeur) {
  NoeudChar* nouveau = (NoeudChar*)malloc(sizeof(NoeudChar));
  if (nouveau == NULL) {
    fprintf(stderr, "Erreur d'allocation de mémoire\n");
    return;
  }
  nouveau->valeur = valeur;
  nouveau->suivant = p->sommet;
  p->sommet = nouveau;
}

char depilerChar(PileChar* p) {
  if (p->sommet == NULL) {
    fprintf(stderr, "Erreur : pile vide\n");
    return '\0';
  }
  NoeudChar* temp = p->sommet;
  char ret = temp->valeur;
  p->sommet = p->sommet->suivant;
  free(temp);
  return ret;
}

void initChar(PileChar* p) {
  p->sommet = NULL;
}

int main(){
    PileChar p;
    initChar(&p);
    printf("Quel est ton mot? ");
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        empilerChar(&p, c);
    }
    printf("Mot inversé: ");
    while (p.sommet != NULL) {
        char ch = depilerChar(&p);
        if (ch) {
            putchar(ch);
        }
    }
    printf("\n");
    return 0;
}