#include <stdio.h>

int maximumRecursif(int t[10], int taille) {
    if (taille == 1)
        return t[0];

    int maxReste = maximumRecursif(t, taille - 1);
    if (t[taille - 1] > maxReste)
        return t[taille - 1];
    else
        return maxReste;
}

int main() {
    int tab[10] = {3, 7, 2, 9, 5};
    int taille = 5;

    int max = maximumRecursif(tab, taille);
    printf("Maximum = %d\n", max);

    return 0;
}
