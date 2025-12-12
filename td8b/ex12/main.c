#include <stdio.h>

int minimumRecursif(int t[10], int taille) {
    if (taille == 1)
        return t[0];

    int minReste = minimumRecursif(t, taille - 1);
    if (t[taille - 1] < minReste)
        return t[taille - 1];
    else
        return minReste;
}

int main() {
    int tab[10] = {7, 3, 9, 2, 5};
    int taille = 5;

    int min = minimumRecursif(tab, taille);
    printf("Minimum = %d\n", min);

    return 0;
}
