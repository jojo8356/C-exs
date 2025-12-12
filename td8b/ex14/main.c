#include <stdio.h>

int estDecroissantRecursif(int t[10], int taille) {
    if (taille <= 1)
        return 1;
    if (t[0] < t[1])
        return 0;
    return estDecroissantRecursif(t + 1, taille - 1);
}

int main() {
    int tab[10] = {9, 7, 7, 4, 2};
    int taille = 5;

    if (estDecroissantRecursif(tab, taille))
        printf("Le tableau est décroissant\n");
    else
        printf("Le tableau n'est pas décroissant\n");

    return 0;
}
