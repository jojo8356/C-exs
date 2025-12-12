#include <stdio.h>

int estCroissantRecursif(int t[10], int taille) {
    if (taille <= 1)
        return 1;
    if (t[0] > t[1])
        return 0;
    return estCroissantRecursif(t + 1, taille - 1);
}

int main() {
    int tab[10] = {1, 2, 2, 4, 5};
    int taille = 5;

    if (estCroissantRecursif(tab, taille))
        printf("Le tableau est croissant\n");
    else
        printf("Le tableau n'est pas croissant\n");

    return 0;
}
