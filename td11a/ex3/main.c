#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud* suivant;
} Noeud;

typedef struct {
    Noeud* sommet;
} Pile;

int estVide(Pile* p) {
    return p->sommet == NULL;
}

void empiler(Pile* p, int valeur) {
    Noeud* nouveau = malloc(sizeof(Noeud));
    if (!nouveau) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(1);
    }

    nouveau->valeur = valeur;
    nouveau->suivant = p->sommet;
    p->sommet = nouveau;
}

int depiler(Pile* p) {
    if (estVide(p)) {
        return -1;
    }

    Noeud* temp = p->sommet;
    int ret = temp->valeur;

    p->sommet = temp->suivant;
    free(temp);

    return ret;
}

int getSommet(Pile* p) {
    if (estVide(p)) {
        fprintf(stderr, "Pile vide, pas de sommet\n");
        return -1;
    }
    return p->sommet->valeur;
}


int main() {
    Pile p = {NULL};

    printf("Pile initialisée, estVide renvoie: %d\n", estVide(&p));
    printf("Début de l'empilement.\n");

    for (int i = 1; i <= 3; i++) {
        printf("Valeur empilée: %d\n", i * 10);
        empiler(&p, i * 10);
    }

    int sommet = getSommet(&p);
    printf("Maintenant estVide renvoie: %d et getSommet: %d\n", estVide(&p), sommet);

    printf("Dépile et affiche tous les éléments avec une boucle while.\n");

    int value = depiler(&p);
    while (value != -1) {
        printf("Valeur dépilée: %d\n", value);
        value = depiler(&p);
    }

    printf("Maintenant estVide renvoie: %d\n", estVide(&p));

    return 0;
}
