#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
  int sommet; // index du sommet de la pile
  int maxTaille;
  int tab[MAX_SIZE];
} PileTableau;

void empiler(PileTableau *p, int value){
    if(p->sommet >= p->maxTaille - 1){
        printf("Pile pleine\n");
        return;
    }
    p->sommet++;
    p->tab[p->sommet] = value;
}

int depiler(PileTableau *p){
    if(p->sommet == -1){
        printf("Pile vide\n");
        return -1;
    }
    int value = p->tab[p->sommet];
    p->sommet--;
    return value;
}

int sommet(PileTableau *p){
    if(p->sommet == -1){
        printf("Pile vide\n");
        return -1;
    }
    return p->tab[p->sommet];
}

int main(){
    PileTableau pile = {.sommet = -1, .maxTaille = MAX_SIZE};
    empiler(&pile, 1);
    empiler(&pile, 3);
    empiler(&pile, 2);
    printf("Sommet: %d\n", sommet(&pile));
    printf("Depile -> %d\n", depiler(&pile));
    printf("Depile -> %d\n", depiler(&pile));
    printf("Sommet element: %d\n", sommet(&pile));
    return 0;
}