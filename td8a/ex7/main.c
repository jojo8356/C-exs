#include <stdio.h>
#include <time.h>

#include "../lib/tableaux.h"

void triFusionRecursif(int tab[], int gauche, int droite){
    if (gauche < droite){
        int milieu = (gauche + droite) / 2;
        triFusionRecursif(tab, gauche, milieu);
        triFusionRecursif(tab, milieu + 1, droite);
        fusionnerTriTab(tab, gauche, milieu, droite);
    }
}

void triFusion(int tab[], int taille){
    triFusionRecursif(tab, 0, taille-1);
}

int main() {
    int tab[1000];
    int taille = sizeof(tab) / sizeof(tab[0]);

    for (int i = 0; i < taille; i++) {
        tab[i] = taille - 1 - i;
    }

    time_t debut = clock();
    triFusion(tab, taille);
    clock_t fin = clock();
    double tempsExecution = 1000.0 * ((double)(fin - debut)) / CLOCKS_PER_SEC;

    printf("Tri fusion en %.3lf ms\n", tempsExecution);

    for (int i = 0; i < taille; i++) {
        tab[i] = taille - 1 - i;
    }

    debut = clock();
    triSelectionTab(tab, taille);
    fin = clock();
    tempsExecution = 1000.0 * ((double)(fin - debut)) / CLOCKS_PER_SEC;

    printf("Tri selection en %.3lf ms\n", tempsExecution);
    return 0;
}